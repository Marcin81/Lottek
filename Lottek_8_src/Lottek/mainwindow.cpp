#include "mainwindow.h"
#include <QtGui>
#include <QTimer>
#include "messagedialog.h"
#include <QFile>
#include "ui_form.h"
#include "ui_drawingform.h"
#include "lottotools.h"
#include "colorchanger.h"
#include "spinboxdecorator.h"
#include "ui_about.h"
#include <QtGui/QStyleFactory>

MainWindow::MainWindow( QWidget *parent, const std::string& xmlFile )
    : QWidget( parent ),
      url( "http://www.lotto.pl/" ),
      checkCount( 0 ),
      xmlName( xmlFile ),
      timeFormat( "HH:mm" ),
      numberOfRow( 6 ),
      flags( Qt::Tool | Qt::WindowTitleHint | Qt::CustomizeWindowHint )
{
  resize( 400, 200 );
  setWindowTitle( "Lottek" );
  setWindowIcon( QIcon( ":/images/ball.png" ) );
  //------------------------------

  form.reset( new Ui_Form );
  form->setupUi( this );
  //------------------------------
/*
  Qt::WindowFlags flags = Qt::Tool
    | Qt::WindowTitleHint
    | Qt::CustomizeWindowHint;*/

  drawingForm.reset( new Ui_drawingform );
  drawingFormParent = new QWidget( 0, flags );
  drawingFormParent->setAttribute( Qt::WA_DeleteOnClose, true );
  drawingForm->setupUi( drawingFormParent );
  //------------------------------

  msgdialog.reset( new MessageDialog );
  msgdialog->hide();

  setWindowFlags( flags );
  //------------------------------

  http = new QHttp( this );
  timer = new QTimer( this );
  gridLayout = new QGridLayout( form->scrollAreaWidgetContents );

  form->scrollArea->setWidgetResizable(false);
  //------------------------------

  progressDialog = new QProgressDialog( this );
  progressDialog->setWindowIcon( QIcon( ":/images/3balls.png" ) );
  progressDialog->setWindowTitle( "Pobieranie pliku" );
  progressDialog->setAutoClose( true );

  // Powiązanie sygnał-gniazdo:
  connect( form->pushButtonCheck, SIGNAL(clicked() ), this, SLOT(checkPage()) );
  connect( timer, SIGNAL( timeout () ),this, SLOT( checkPage() ) );
  //------------------------------

  connect( http, SIGNAL(requestFinished(int,bool)),
           this, SLOT( httpRequestFinished( int, bool ) ) );

  connect( http, SIGNAL(responseHeaderReceived(QHttpResponseHeader)),
           this, SLOT(httpResponseHeaderReceived(QHttpResponseHeader)));

  connect( http, SIGNAL(dataReadProgress(int,int)),
           this, SLOT(httpDataReadProgress(int,int)));
  //------------------------------

  connect( form->pushButtonHide, SIGNAL(clicked()), this, SLOT(hide()));
  connect( progressDialog, SIGNAL(canceled()), this, SLOT(cancelcheckPage()));
  connect( progressDialog, SIGNAL(canceled()), this, SLOT(hide()) );
  connect( form->pushButtonRandom, SIGNAL( clicked() ), this, SLOT( setRandomNumbers() ) );
  //---------------------------------
  downloadPage();
  numbers = LottoTools::getLottoNumbers( pageHtlmText );
  form->lineEditLottoNumbers->setText( numbers.join( " " ) );
  //---------------------------------
  windowAction = new QAction( "Pokaż okno", this );

  connect( windowAction, SIGNAL(triggered(bool)),
           this, SLOT( showOrHideFormMenuAction(bool) ) );

  connect( form->pushButtonHide, SIGNAL(clicked()),
           this, SLOT( showOrHideFormMenuAction() ) );

  connect( form->pushButtonAdd, SIGNAL(clicked()),
           this, SLOT(clickAdd()) );
  //------------------------------

  drawingFormAction = new QAction( "Losowania", this );

  connect( drawingFormAction, SIGNAL(triggered( bool )),
           this, SLOT(showOrHideDrawingFormMenuAction(bool)) );

  connect( drawingForm->pushButtonHidden, SIGNAL(clicked()),
           this, SLOT( showOrHideDrawingFormMenuAction()) );

  connect( this, SIGNAL(messageSignal(QString,QString)),
           this, SLOT(messageSlot(QString,QString)) );
  //------------------------------

  connect( drawingForm->pushButtonHidden, SIGNAL(clicked()),
           this,SLOT( startNewTimer() ) );
  //------------------------------
  aboutAction = new QAction( "O programie...", this );
  connect( aboutAction, SIGNAL(triggered()), this, SLOT(showAbout()) );
  //------------------------------

  quitAction = new QAction( "Wyjście", this );
//  connect( quitAction, SIGNAL(triggered()), this, SLOT(Quit()) );
  connect( quitAction, SIGNAL(triggered()), qApp, SLOT(quit() ) );
  //------------------------------

  trayIconMenu = new QMenu(this);
  trayIconMenu->addAction(windowAction);
  trayIconMenu->addAction(drawingFormAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(aboutAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(quitAction);
  //------------------------------

  trayIcon = new QSystemTrayIcon(this);
  trayIcon->setContextMenu(trayIconMenu);
  trayIcon->setIcon( QIcon( ":/images/ball.png" ) );
  trayIcon->show();
  hide();
  //------------------------------
  configureColorsWinLotto();
  prepareStandardRowDecorator();
  readConfiguration();
  connect( form->pushButtonDelete, SIGNAL(clicked()), this, SLOT(clickDelete() ) );
  connect( qApp, SIGNAL(aboutToQuit()), this, SLOT(writeConfiguration()));
  //----------------------------------
  const QString styleName = QApplication::style()->objectName();
  if( styleName != trUtf8( "macintosh (aqua)" ) ) {
    QApplication::setStyle( new QPlastiqueStyle );
    QApplication::setPalette( QApplication::style()->standardPalette() );
  } // if
}

void MainWindow::showAbout()
{
  Ui_About about;
  QWidget* w = new QWidget( 0, flags );
  about.setupUi( w );
  w->show();
  aboutAction->setDisabled( true );
  connect( about.closeButton, SIGNAL(clicked()), this, SLOT(showAboutAction()) );
}

void MainWindow::showAboutAction()
{
  aboutAction->setEnabled( true );
}

void MainWindow::pushSpinBoxToDecorators( QSpinBox* spin, const int row )
{
  SpinBoxDecorator* spinDec = new SpinBoxDecorator( spin, row );
  connect( spinDec, SIGNAL(valueChanged()),
             this, SLOT(changeColorAndValue()) );
  spinDecorators.push_back( spinDec );
}

void MainWindow::prepareStandardRowDecorator()
{
  pushSpinBoxToDecorators( form->spinBox_1, 0 );
  pushSpinBoxToDecorators( form->spinBox_2, 0 );
  pushSpinBoxToDecorators( form->spinBox_3, 0 );
  pushSpinBoxToDecorators( form->spinBox_4, 0 );
  pushSpinBoxToDecorators( form->spinBox_5, 0 );
  pushSpinBoxToDecorators( form->spinBox_6, 0 );
}

bool MainWindow::canChangeColor( QSpinBox* spinBox ) const
{
  const int value = spinBox->value();
  return numbers.contains( QString::number( value) );
}

void MainWindow::changeColorAndValue()
{
  SpinBoxDecorator* spinDecorator = qobject_cast<SpinBoxDecorator*>(sender());
  if( !spinDecorator )
    return;

  QSpinBox* spin = spinDecorator->getSpinBox();
  bool changePrevValue = false;

  for( boost::ptr_deque<SpinBoxDecorator>::size_type r = 0u;
       r < spinDecorators.size(); r++ ) {
    if( r == spinDecorator->getRow() ) {
      for( int v = 0; v < numberOfRow; v++ ) {
        const int index = (r*numberOfRow)+v;
        QSpinBox* tspin = spinDecorators[index].getSpinBox();
        if( ( spin != tspin ) && ( spin->value() == tspin->value()  ) ) {
          changePrevValue = true;
          break;
        }

      } // for

    } // if

  } //for

  if( changePrevValue ) {
    const int prevValue = spinDecorator->getPreviewValue();
    spinDecorator->changeValueWthOutSignal( prevValue );
  } else
    spinDecorator->setPreviewValue( spin->value() );

  // set color:
  const bool canChange = canChangeColor( spin );
  colorChanger->changeColorsAndFont( spin, canChange );
}

void MainWindow::configureColorsWinLotto()
{
  const QPalette palette = form->spinBox_1->palette();
  const QColor color = palette.color( QPalette::Text );
  const QFont font = form->spinBox_1->font();
  //------------------------------

  QFont newFont;
  newFont.setBold(true);
  newFont.setWeight(75);
  //------------------------------

  colorChanger.reset( new ColorChanger( font, newFont, color ) );

  form->lineEditLottoNumbers->setFont( newFont );
  QPalette palette2;
  QBrush brush( colorChanger->getNewColor() );
  brush.setStyle(Qt::SolidPattern);
  palette2.setBrush(QPalette::Active, QPalette::Text, brush);
  palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);

  form->lineEditLottoNumbers->setPalette( palette2 );
}

void MainWindow::showOrHideDrawingFormMenuAction( bool on )
{
  drawingFormAction->setEnabled( on );
  drawingFormParent->setHidden( on );
}

void MainWindow::showOrHideFormMenuAction( bool on )
{
  windowAction->setEnabled( on );
  setHidden( on );
}

void MainWindow::clickAdd( const bool ignoreCount )
{
  const int row = ( gridLayout->isEmpty() ? 0 : getRowCount() );

  for (int i = 0; i < numberOfRow; i++) {
    QSpinBox *spin = new QSpinBox(form->scrollAreaWidgetContents );
    spin->setRange( 1, 49 );
    spin->setValue( i + 1);
    pushSpinBoxToDecorators( spin, row + 1 );
    spin->show();
    gridLayout->addItem( new QWidgetItem( spin ), row, i);
  } //for
  //------------------------------

  QCheckBox* checkbox = new QCheckBox( form->scrollAreaWidgetContents );
  checkbox->setChecked( true );
  checkbox->show();
  connect( checkbox, SIGNAL(clicked(bool)), this, SLOT( setCheckBoxState( bool ) ) );
  if( !ignoreCount )
    setCheckBoxState( true );
  gridLayout->addItem( new QWidgetItem( checkbox ), row, numberOfRow );
  //------------------------------

  form->scrollAreaWidgetContents ->resize(form->scrollAreaWidgetContents->sizeHint().width(), form->scrollAreaWidgetContents->sizeHint().height());
  gridLayout->update();
}

void MainWindow::setCheckBoxState( const bool state )
{
  state ? checkCount++ : checkCount--;
  checkDeleteButton();
}

void MainWindow::readDays(const std::string& dayStr,
                         QGroupBox* dayGroup, QTimeEdit* basic,
                         QCheckBox* isFirst, QCheckBox* isSecond,
                         QTimeEdit* first, QTimeEdit* second )
{
  const std::string branchStr = std::string( "Week." ) + dayStr;
  boost::property_tree::ptree child = pt.get_child( branchStr,
    boost::property_tree::empty_ptree< boost::property_tree::ptree >() );
  // Zastapiono:
 // boost::property_tree::ptree child = pt.get_child( branchStr );
  
  QTime tmpTime = basic->time();
  QString tmpQString = tmpTime.toString( timeFormat );

  const QString basicStr = QString::fromStdString( child.get( "basic", tmpQString.toStdString() ) );

  tmpTime = tmpTime.fromString( basicStr, timeFormat );
  basic->setTime( tmpTime );
  //-------------------------------

  tmpTime = first->time();
  tmpQString = tmpTime.toString( timeFormat );

  const QString firstStr = QString::fromStdString( child.get( "first", tmpQString.toStdString() ) );

  tmpTime = tmpTime.fromString( firstStr, timeFormat );
  first->setTime( tmpTime );
  //-------------------------------

  tmpTime = second->time();
  tmpQString = tmpTime.toString( timeFormat );

  const QString secondStr = QString::fromStdString( child.get( "second", tmpQString.toStdString() ) );

  tmpTime = tmpTime.fromString( secondStr, timeFormat );
  second->setTime( tmpTime );
  //-------------------------------

  const bool isCheckBool = child.get( "isCheck", dayGroup->isChecked() );
  dayGroup->setChecked( isCheckBool );
  //-------------------------------

  const bool isFirstBool = child.get( "isFirst", isFirst->isChecked() );
  isFirst->setChecked( isFirstBool );
  //-------------------------------

  const bool isSecondBool = child.get( "isSecond", isSecond->isChecked() );
  isSecond->setChecked( isSecondBool );
  //-------------------------------
}

void MainWindow::readConfiguration()
{
  try {
    read_xml( xmlName, pt );
    //---------------------------------
    const int delay = pt.get( "Week.Delay", drawingForm->spinBoxDelay->value() );
    drawingForm->spinBoxDelay->setValue( delay );
    //------------------------
    readDays( "Monday",
      drawingForm->mMondayGroupBox, drawingForm->baseTimeMonday,
      drawingForm->firstCheckBoxMonday, drawingForm->secondCheckBoxMonday,
      drawingForm->firstTimeMonday, drawingForm->secondTimeMonday );
    //------------------------
    readDays( "Tuesday",
      drawingForm->mTuesdayGroupBox, drawingForm->baseTimeTuesday,
      drawingForm->firstCheckBoxTuesday, drawingForm->secondCheckBoxTuesday,
      drawingForm->firstTimeTuesday, drawingForm->secondTimeTuesday );
    //------------------------
    readDays( "Wednesday",
      drawingForm->mWednesdayGroupBox, drawingForm->baseTimeWednesday,
      drawingForm->firstCheckBoxWednesday, drawingForm->secondCheckBoxWednesday,
      drawingForm->firstTimeWednesday, drawingForm->secondTimeWednesday );
    //------------------------
    readDays( "Thursday",
      drawingForm->mThursdayGroupBox, drawingForm->baseTimeThursday,
      drawingForm->firstCheckBoxThursday, drawingForm->secondCheckBoxThursday,
      drawingForm->firstTimeThursday, drawingForm->secondTimeThursday );
    //------------------------
    readDays( "Friday",
      drawingForm->mFridayGroupBox, drawingForm->baseTimeFriday,
      drawingForm->firstCheckBoxFriday, drawingForm->secondCheckBoxFriday,
      drawingForm->firstTimeFriday, drawingForm->secondTimeFriday );
    //------------------------
    readDays( "Saturday",
      drawingForm->mSaturdayGroupBox, drawingForm->baseTimeSaturday,
      drawingForm->firstCheckBoxSaturday, drawingForm->secondCheckBoxSaturday,
      drawingForm->firstTimeSaturday, drawingForm->secondTimeSaturday );
    //------------------------
    readDays( "Sunday",
      drawingForm->mSundayGroupBox, drawingForm->baseTimeSunday,
      drawingForm->firstCheckBoxSunday, drawingForm->secondCheckBoxSunday,
      drawingForm->firstTimeSunday, drawingForm->secondTimeSunday );
  //---------------------------------
  const int n1 = pt.get( "settings.number1", form->spinBox_1->value() );
  const int n2 = pt.get( "settings.number2", form->spinBox_2->value() );
  const int n3 = pt.get( "settings.number3", form->spinBox_3->value() );
  const int n4 = pt.get( "settings.number4", form->spinBox_4->value() );
  const int n5 = pt.get( "settings.number5", form->spinBox_5->value() );
  const int n6 = pt.get( "settings.number6", form->spinBox_6->value() );

  form->spinBox_1->setValue( n1 );
  form->spinBox_2->setValue( n2 );
  form->spinBox_3->setValue( n3 );
  form->spinBox_4->setValue( n4 );
  form->spinBox_5->setValue( n5 );
  form->spinBox_6->setValue( n6 );

  const int rowsCount = pt.get( "settings.rows", 0 );
  boost::property_tree::ptree child = pt.get_child( "rows", boost::property_tree::empty_ptree< boost::property_tree::ptree >() );
  // Zastapiono:
  //boost::property_tree::ptree child = pt.get_child( "rows" );
  
  boost::property_tree::ptree::iterator it = child.begin();

  for( int i = 0; i < rowsCount; i++ ) {
    clickAdd( true );
    QLayoutItem* item_1 = gridLayout->itemAtPosition( i, 0);
    QLayoutItem* item_2 = gridLayout->itemAtPosition( i, 1);
    QLayoutItem* item_3 = gridLayout->itemAtPosition( i, 2);
    QLayoutItem* item_4 = gridLayout->itemAtPosition( i, 3);
    QLayoutItem* item_5 = gridLayout->itemAtPosition( i, 4);
    QLayoutItem* item_6 = gridLayout->itemAtPosition( i, 5);

    QLayoutItem* item_7 = gridLayout->itemAtPosition( i, 6); // checkbox
    QCheckBox* checkBox =  static_cast< QCheckBox* > ( item_7->widget() );

    QSpinBox* spinBox_1 =  static_cast< QSpinBox* > ( item_1->widget() );
    QSpinBox* spinBox_2 =  static_cast< QSpinBox* > ( item_2->widget() );
    QSpinBox* spinBox_3 =  static_cast< QSpinBox* > ( item_3->widget() );
    QSpinBox* spinBox_4 =  static_cast< QSpinBox* > ( item_4->widget() );
    QSpinBox* spinBox_5 =  static_cast< QSpinBox* > ( item_5->widget() );
    QSpinBox* spinBox_6 =  static_cast< QSpinBox* > ( item_6->widget() );
    //Load
    const int n1 = it->second.get( "number_1", form->spinBox_1->value() );
    const int n2 = it->second.get( "number_2", form->spinBox_2->value() );
    const int n3 = it->second.get( "number_3", form->spinBox_3->value() );
    const int n4 = it->second.get( "number_4", form->spinBox_4->value() );
    const int n5 = it->second.get( "number_5", form->spinBox_5->value() );
    const int n6 = it->second.get( "number_6", form->spinBox_6->value() );
    const bool check = it->second.get( "check", true );
    it++;

    spinBox_1->setValue( n1 );
    spinBox_2->setValue( n2 );
    spinBox_3->setValue( n3 );
    spinBox_4->setValue( n4 );
    spinBox_5->setValue( n5 );
    spinBox_6->setValue( n6 );
    checkBox->setChecked( check );
    if( check )
      checkCount++;
    } // for

    checkDeleteButton();

  } // try
  catch ( const std::exception &e ) {

  } // catch
}

void MainWindow::clickDelete()
{
  form->scrollAreaWidgetContents->setEnabled( false );

  // Delete selected rows:
  // Optional:
  if( !gridLayout->isEmpty() ) {
    QList< int > values;
    for( int i = numberOfRow; i < gridLayout->count(); i +=7 ) {
      QLayoutItem *child = gridLayout->itemAt(i);

      QCheckBox* checkbox = static_cast< QCheckBox* > ( child->widget() );
      if( checkbox && !checkbox->isChecked() ) {
        for( int j = i - numberOfRow; j < i; j++ ) {
          child = gridLayout->itemAt( j );
          QSpinBox* spin = static_cast< QSpinBox* > ( child->widget() );
          values.push_back( spin->value() );
        } //for

      }

    } // for

    const int rowCount = getRowCount() - checkCount;
    //delete everythink
    QLayoutItem *child = 0;
    while ( (child = gridLayout->takeAt(0) ) != 0) {
      gridLayout->removeWidget( child->widget() );
      child->widget()->close();
      child->widget()->deleteLater();
      gridLayout->removeItem( child );
      delete child;
    }
    boost::ptr_deque< SpinBoxDecorator >::iterator it = spinDecorators.begin();

    for( int i = 0; i < numberOfRow; i++ )
      it++;
    // iterator na 7 elemencie, kasowanie bez pierwszego wiersza
    spinDecorators.erase( it, spinDecorators.end() );
    // create widgets from copy value
    QList< int >::iterator iv = values.begin();
    for( int i = 0; i < rowCount; i++ ) {
      clickAdd( true );
      for( int j = 0; j < numberOfRow; j++ ) {
        QLayoutItem* item = gridLayout->itemAtPosition( i, j);
        QSpinBox* spinBox =  static_cast< QSpinBox* > ( item->widget() );
        spinBox->setValue( (*iv++) );
      }

      QLayoutItem* item_7 = gridLayout->itemAtPosition( i, numberOfRow);
      QCheckBox* checkBox =  static_cast< QCheckBox* > ( item_7->widget() );
      checkBox->setChecked( false );
    } // for
    checkCount = 0;
  } // if

  form->scrollAreaWidgetContents->resize(form->scrollAreaWidgetContents->sizeHint().width(), form->scrollAreaWidgetContents->sizeHint().height());

  gridLayout->update();
  checkDeleteButton();

  // delete old values from xml file:
  // Skasuj wszystkie  wiersze w xml zapisz od nowa:
  boost::property_tree::ptree child = pt.get_child( "rows", boost::property_tree::empty_ptree< boost::property_tree::ptree >() );
  // Zastapiono:
  //boost::property_tree::ptree child = pt.get_child( "rows" );

  pt.erase( child.begin(), child.end() );
  writeConfiguration();

  form->scrollAreaWidgetContents->setEnabled( true );
}

void MainWindow::showChildren()
{
  for( int i = 0; i < gridLayout->count(); i++ )
    gridLayout->itemAt( i )->widget()->show();
}

void MainWindow::checkDeleteButton()
{
  if( checkCount > 0 )
    form->pushButtonDelete->setEnabled( true );
  else
    form->pushButtonDelete->setEnabled( false );
}

void MainWindow::writeDays( const std::string& dayStr,
                            QGroupBox* dayGroup, QTimeEdit* basic,
                            QCheckBox* isFirst, QCheckBox* isSecond,
                            QTimeEdit* first, QTimeEdit* second )
{
  const std::string branchStr = std::string( "Week." ) + dayStr;
  boost::property_tree::ptree& child0 = pt.put_child( branchStr,
      boost::property_tree::empty_ptree< boost::property_tree::ptree >() );
//  Zastapiono:

  //get_child
  child0.put< bool >( "isCheck", dayGroup->isChecked() );

  QTime tmpTime = basic->time();
  QString tmpQString = tmpTime.toString( timeFormat );
  child0.put< std::string >( "basic", tmpQString.toStdString() );

  child0.put< bool >( "isFirst", isFirst->isChecked() );
  child0.put< bool >( "isSecond", isSecond->isChecked() );

  tmpTime = first->time();
  tmpQString = tmpTime.toString( timeFormat );
  child0.put< std::string >( "first", tmpQString.toStdString() );

  tmpTime = second->time();
  tmpQString = tmpTime.toString( timeFormat );
  child0.put< std::string >( "second", tmpQString.toStdString() );
}

void MainWindow::writeConfiguration()
{
  try {
    //------------------------
    writeDays( "Monday",
      drawingForm->mMondayGroupBox, drawingForm->baseTimeMonday,
      drawingForm->firstCheckBoxMonday, drawingForm->secondCheckBoxMonday,
      drawingForm->firstTimeMonday, drawingForm->secondTimeMonday );
    //------------------------
    writeDays( "Tuesday",
      drawingForm->mTuesdayGroupBox, drawingForm->baseTimeTuesday,
      drawingForm->firstCheckBoxTuesday, drawingForm->secondCheckBoxTuesday,
      drawingForm->firstTimeTuesday, drawingForm->secondTimeTuesday );
    //------------------------
    writeDays( "Wednesday",
      drawingForm->mWednesdayGroupBox, drawingForm->baseTimeWednesday,
      drawingForm->firstCheckBoxWednesday, drawingForm->secondCheckBoxWednesday,
      drawingForm->firstTimeWednesday, drawingForm->secondTimeWednesday );
    //------------------------
    writeDays( "Thursday",
      drawingForm->mThursdayGroupBox, drawingForm->baseTimeThursday,
      drawingForm->firstCheckBoxThursday, drawingForm->secondCheckBoxThursday,
      drawingForm->firstTimeThursday, drawingForm->secondTimeThursday );
    //------------------------
    writeDays( "Friday",
      drawingForm->mFridayGroupBox, drawingForm->baseTimeFriday,
      drawingForm->firstCheckBoxFriday, drawingForm->secondCheckBoxFriday,
      drawingForm->firstTimeFriday, drawingForm->secondTimeFriday );
    //------------------------
    writeDays( "Saturday",
      drawingForm->mSaturdayGroupBox, drawingForm->baseTimeSaturday,
      drawingForm->firstCheckBoxSaturday, drawingForm->secondCheckBoxSaturday,
      drawingForm->firstTimeSaturday, drawingForm->secondTimeSaturday );
    //------------------------
    writeDays( "Sunday",
      drawingForm->mSundayGroupBox, drawingForm->baseTimeSunday,
      drawingForm->firstCheckBoxSunday, drawingForm->secondCheckBoxSunday,
      drawingForm->firstTimeSunday, drawingForm->secondTimeSunday );
  //------------------------
  pt.put< int >( "Week.Delay", drawingForm->spinBoxDelay->value() );
  //------------------------
  pt.put< int >( "settings.number1", form->spinBox_1->value() );
  pt.put< int >( "settings.number2", form->spinBox_2->value() );
  pt.put< int >( "settings.number3", form->spinBox_3->value() );
  pt.put< int >( "settings.number4", form->spinBox_4->value() );
  pt.put< int >( "settings.number5", form->spinBox_5->value() );
  pt.put< int >( "settings.number6", form->spinBox_6->value() );

  const int rows = ( gridLayout->isEmpty() ? 0 : (gridLayout->count() / 7 ) );
  pt.put< int >( "settings.rows", rows);

  if( !gridLayout->isEmpty() ) {
    pt.put_child( "rows", boost::property_tree::empty_ptree< boost::property_tree::ptree >() );
    boost::property_tree::ptree& child = pt.get_child( "rows" );
    for( int i = 0; i < rows; i++ ) {
      QLayoutItem* item_1 = gridLayout->itemAtPosition( i, 0);
      QLayoutItem* item_2 = gridLayout->itemAtPosition( i, 1);
      QLayoutItem* item_3 = gridLayout->itemAtPosition( i, 2);
      QLayoutItem* item_4 = gridLayout->itemAtPosition( i, 3);
      QLayoutItem* item_5 = gridLayout->itemAtPosition( i, 4);
      QLayoutItem* item_6 = gridLayout->itemAtPosition( i, 5);

      QLayoutItem* item_7 = gridLayout->itemAtPosition( i, 6); // checkbox
      QCheckBox* checkBox =  static_cast< QCheckBox* > ( item_7->widget() );

      QSpinBox* spinBox_1 =  static_cast< QSpinBox* > ( item_1->widget() );
      QSpinBox* spinBox_2 =  static_cast< QSpinBox* > ( item_2->widget() );
      QSpinBox* spinBox_3 =  static_cast< QSpinBox* > ( item_3->widget() );
      QSpinBox* spinBox_4 =  static_cast< QSpinBox* > ( item_4->widget() );
      QSpinBox* spinBox_5 =  static_cast< QSpinBox* > ( item_5->widget() );
      QSpinBox* spinBox_6 =  static_cast< QSpinBox* > ( item_6->widget() );
      //save:
      boost::property_tree::ptree& child2 = pt.put_child( "rows.row",
             boost::property_tree::empty_ptree< boost::property_tree::ptree >(), true );

      child2.put( "number_1", spinBox_1->value(), true );
      child2.put( "number_2", spinBox_2->value(), true );
      child2.put( "number_3", spinBox_3->value(), true );
      child2.put( "number_4", spinBox_4->value(), true );
      child2.put( "number_5", spinBox_5->value(), true );
      child2.put( "number_6", spinBox_6->value(), true );
      child2.put( "check", checkBox->isChecked(), true );

    } // for
  } // if

  write_xml( xmlName, pt );
} // try
  catch ( const std::exception &e ) {

  } // catch
}

MainWindow::~MainWindow()
{

}

void MainWindow::checkPage( bool withShowMessage )
{
  timer->stop();
  form->scrollAreaWidgetContents->setEnabled( false );
  form->pushButtonCheck->setEnabled( false );
  form->pushButtonRandom->setEnabled( false );
  form->pushButtonAdd->setEnabled( false );
  //------------------------------

  const bool isErase = form->pushButtonDelete->isEnabled();
  form->pushButtonDelete->setEnabled( false );
  //------------------------------

  downloadPage();
  numbers = LottoTools::getLottoNumbers( pageHtlmText );
  //------------------------------

  form->lineEditLottoNumbers->setText( numbers.join( " " ) );
  const int countBase = LottoTools::compareNumbers( numbers,
    form->spinBox_1, form->spinBox_2, form->spinBox_3,
    form->spinBox_4, form->spinBox_5, form->spinBox_6 );

  if( withShowMessage )
    showMessageIfWin( countBase, 0 );
  //------------------------------

  // Optional:
  if( !gridLayout->isEmpty() ) {
    // Ten wiersz to problem poniewaz po skasownaiu wiersza rowCount nadal zwraca wartosc z tym wykasowanym wierszem
    //! const int rowCount = gridLayout->rowCount();// / 7; // tutaj byk
    const int rowCount = getRowCount();

    for( int i = 0; i < rowCount; i++ ) {
      // check row:
      QLayoutItem* item_1 = gridLayout->itemAtPosition( i, 0);
      QLayoutItem* item_2 = gridLayout->itemAtPosition( i, 1);
      QLayoutItem* item_3 = gridLayout->itemAtPosition( i, 2);
      QLayoutItem* item_4 = gridLayout->itemAtPosition( i, 3);
      QLayoutItem* item_5 = gridLayout->itemAtPosition( i, 4);
      QLayoutItem* item_6 = gridLayout->itemAtPosition( i, 5);
       //------------------------------

      QLayoutItem* item_7 = gridLayout->itemAtPosition( i, 6); // checkbox
      QCheckBox* checkBox =  static_cast< QCheckBox* > ( item_7->widget() );

      if( checkBox->isChecked() ) {
        QSpinBox* spinBox_1 =  static_cast< QSpinBox* > ( item_1->widget() );
        QSpinBox* spinBox_2 =  static_cast< QSpinBox* > ( item_2->widget() );
        QSpinBox* spinBox_3 =  static_cast< QSpinBox* > ( item_3->widget() );
        QSpinBox* spinBox_4 =  static_cast< QSpinBox* > ( item_4->widget() );
        QSpinBox* spinBox_5 =  static_cast< QSpinBox* > ( item_5->widget() );
        QSpinBox* spinBox_6 =  static_cast< QSpinBox* > ( item_6->widget() );
        //------------------------------

        const int count = LottoTools::compareNumbers( numbers,
          spinBox_1, spinBox_2, spinBox_3, spinBox_4, spinBox_5, spinBox_6 );

        showMessageIfWin( count, i );
      } // if


    } // for
  } // if
  //------------------------------

  form->pushButtonCheck->setEnabled( true );
  form->pushButtonRandom->setEnabled( true );
  form->pushButtonAdd->setEnabled( true );
  form->pushButtonDelete->setEnabled( isErase );
  form->scrollAreaWidgetContents->setEnabled( true );
  startNewTimer();
}

void MainWindow::showMessageIfWin( const int count, const int row )
{

  QString rowStr;
  if( row != 0 )
    rowStr = " Zestaw nr: " + QString::number( row );

  switch( count ) {
    case 3:
      windowAction->setEnabled( false );
      emit messageSignal( "Wygrana IV stopnia!" + rowStr, "Gratulacje!<BR>Masz <B>3</B> trafnie wytypowane liczby." );
      windowAction->setEnabled( true );
    break;

    case 4:
      windowAction->setEnabled( false );
      emit messageSignal( "Wygrana III stopnia!" + rowStr, "Gratulacje!<BR>Masz <B>4</B> trafnie wytypowane liczby." );
      windowAction->setEnabled( true );
    break;

    case 5:
      windowAction->setEnabled( false );
      emit messageSignal( "Wygrana II stopnia!" + rowStr, "Gratulacje!<BR>Masz <B>5</B> trafnie wytypowanych liczb." );
      windowAction->setEnabled( true );
    break;

    case 6:
      windowAction->setEnabled( false );
      emit messageSignal( "Wygrana I stopnia!" + rowStr, "Gratulacje!<BR>Masz <B>6</B> trafnie wytypowanych liczb." );
      windowAction->setEnabled( true );
    break;
    default:
      timer->start();
  };

}

void MainWindow::messageSlot( const QString& title, const QString& message )
{
  // MessageBox nie działa -> wywala aplikacje, nawet na watkach
  // zawsze jak rodzic jest ukryty, brak rodzica rowniez wywala
  //!QMessageBox::information( 0, title, message );
  const bool ishidden = isHidden();
  if( !ishidden )
    hide();
  msgdialog->setWindowTitle( title );
  msgdialog->setMessageText( message );
  msgdialog->setModal( true );
  msgdialog->show();
  msgdialog->activateWindow();
  msgdialog->setFocus();
  msgdialog->exec();
  if( !ishidden )
    show();
  timer->start();
}

// Wywolywany gdy zakonczono wykonywac zadanie
void MainWindow::httpRequestFinished( int requestid, bool error )
{
  // Obsluga bledu polaczenia z serwerem:
  if( error && ( http->state() == QHttp::Connecting || http->state() == QHttp::HostLookup ) ) {
    // Ukrycie okna z informacja o postepie pobierania pliku:
    progressDialog->hide();
    // Pobranie adresu url
    // Komunikat:
    QMessageBox::critical( this, "Błąd!", "Błąd podczas polaczenia z serwerem:<BR>" + url.host() );

  } // if

}

// Obsluga bledow po pobraniu naglowka html:
void MainWindow::httpResponseHeaderReceived( const QHttpResponseHeader& header )
{
  if( header.statusCode() != 200 ) { // status 200 oznacza ze nie ma bledow i wszystko jest ok
    // Ukrycie okna z informacja po postepie pobierania plikow:
    progressDialog->hide();
    // Komunikat:
    QMessageBox::critical( this, "Błąd!", "Błąd sprawdzanie numerow totolotka :(" );
  } // if

}

void MainWindow::setRandomNumbers()
{
  timer->stop();
  form->pushButtonCheck->setEnabled( false );
  form->spinBox_1->setEnabled( false );
  form->spinBox_2->setEnabled( false );
  form->spinBox_3->setEnabled( false );
  form->spinBox_4->setEnabled( false );
  form->spinBox_5->setEnabled( false );
  form->spinBox_6->setEnabled( false );
  //-----------------------------------------

  static unsigned start = ( ( 12542 * form->spinBox_6->value() )
     + ( form->spinBox_3->value() * timer->timerId() ) + 652 ) / form->spinBox_2->value();
  form->spinBox_1->setValue( LottoTools::randomNumber( time(0) + start ) );
  form->spinBox_2->setValue( LottoTools::randomNumber( ( form->spinBox_6->value() * timer->timerId() ) / start ) );
  form->spinBox_3->setValue( LottoTools::randomNumber( ( (timer->timerId() * 37 ) % rand() ) * ( start - 6078) ) );
  form->spinBox_4->setValue( LottoTools::randomNumber( timer->timerId() * start ) );
  form->spinBox_5->setValue( LottoTools::randomNumber( rand() * start ) );
  form->spinBox_6->setValue( LottoTools::randomNumber( form->spinBox_4->value() + rand() - start ) );

  start = LottoTools::randomNumber( start - 3127);
  //----------------------------------------

  LottoTools::compareNumbers( numbers,
    form->spinBox_1, form->spinBox_2, form->spinBox_3,
    form->spinBox_4, form->spinBox_5, form->spinBox_6 );
  //-----------------------------------------

  if( !gridLayout->isEmpty() ) {
    const int rowCount = getRowCount();
    for( int i = 0; i < rowCount; i++ ) {
      start = LottoTools::randomNumber( start + ( ( rand() % 783351 ) * timer->timerId() ) );
      // check row:
      QLayoutItem* item_1 = gridLayout->itemAtPosition( i, 0);
      QLayoutItem* item_2 = gridLayout->itemAtPosition( i, 1);
      QLayoutItem* item_3 = gridLayout->itemAtPosition( i, 2);
      QLayoutItem* item_4 = gridLayout->itemAtPosition( i, 3);
      QLayoutItem* item_5 = gridLayout->itemAtPosition( i, 4);
      QLayoutItem* item_6 = gridLayout->itemAtPosition( i, 5);

      QLayoutItem* item_7 = gridLayout->itemAtPosition( i, 6); // checkbox
      QCheckBox* checkBox =  static_cast< QCheckBox* > ( item_7->widget() );

      if( checkBox->isChecked() ) {
        QSpinBox* spinBox_1 =  static_cast< QSpinBox* > ( item_1->widget() );
        QSpinBox* spinBox_2 =  static_cast< QSpinBox* > ( item_2->widget() );
        QSpinBox* spinBox_3 =  static_cast< QSpinBox* > ( item_3->widget() );
        QSpinBox* spinBox_4 =  static_cast< QSpinBox* > ( item_4->widget() );
        QSpinBox* spinBox_5 =  static_cast< QSpinBox* > ( item_5->widget() );
        QSpinBox* spinBox_6 =  static_cast< QSpinBox* > ( item_6->widget() );
        //-----------------------------------------

        spinBox_1->setValue( LottoTools::randomNumber( start * timer->timerId() * form->spinBox_3->value()) );
        spinBox_2->setValue( LottoTools::randomNumber( start * form->spinBox_6->value()) );
        spinBox_3->setValue( LottoTools::randomNumber( start + 985213) );
        spinBox_4->setValue( LottoTools::randomNumber( ( time(0) * rand() * form->spinBox_1->value() ) / start) );
        spinBox_5->setValue( LottoTools::randomNumber( (start * timer->timerId()) % form->spinBox_4->value() ) );
        spinBox_6->setValue( LottoTools::randomNumber( start % (time(0) * timer->timerId() )) );
        //-------------------------------------
        LottoTools::compareNumbers( numbers,
          spinBox_1, spinBox_2, spinBox_3, spinBox_4, spinBox_5, spinBox_6 );
      } // if

    } // for
  } // if

  form->spinBox_1->setEnabled( true );
  form->spinBox_2->setEnabled( true );
  form->spinBox_3->setEnabled( true );
  form->spinBox_4->setEnabled( true );
  form->spinBox_5->setEnabled( true );
  form->spinBox_6->setEnabled( true );

  const int ms = timer->timerId();
  if( ms != -1 )
    timer->start( ms );
  else
    timer->start();
  form->pushButtonCheck->setEnabled( true );
}

void MainWindow::cancelcheckPage()
{
  // Przerwanie operacji na serwerze http:
  http->abort();
  form->scrollAreaWidgetContents->setEnabled( true );
}

//void MainWindow::Quit()
//{
//  writeConfiguration();
//  qApp->quit();
//}

void MainWindow::httpDataReadProgress( int bytesRead, int totalBytes )
{
  progressDialog->setMaximum( totalBytes );
  progressDialog->setValue( bytesRead );
}

int MainWindow::calculateNewTimerValue()
{
  std::multimap< DayOfWeek, QTime > lottoDays;
  LottoTools::fillLottoDaysWithHours( drawingForm.get(), lottoDays );
  LottoTools::sortLottoDays( lottoDays );
  QDateTime nextDateTime = LottoTools::getNextLottoDate( lottoDays );
  QDate lastLottoDate = LottoTools::getLottoDateFromWWW( pageHtlmText);
  QDateTime lastDateTime = LottoTools::getLastLottoDate( lastLottoDate, lottoDays );
  // Zwłoka po losowaniu 5 - 20 min;
  const int delay = drawingForm->spinBoxDelay->value() * 60 * 1000;
  return (lastDateTime.secsTo( nextDateTime ) * 1000) + delay;
}

void MainWindow::startNewTimer()
{
  timer->start( calculateNewTimerValue() );
}

void MainWindow::downloadPage()
{
  // Wydzielenie nazwy pliku z adresu url:
  QFileInfo fileInfo( url.path() );

  // Polaczenie z serwerem i pobranie wybranego pliku:
  http->setHost( url.host() );
  QByteArray buffers;
  QBuffer buffer( &buffers );
  http->get( url.path(), &buffer );

  progressDialog->setLabelText( "Sprawdzanie totka" );
  // Wyswietlenie informacji o postepie w pobieraniu pliku:
  progressDialog->exec();
  pageHtlmText = buffers;
}
