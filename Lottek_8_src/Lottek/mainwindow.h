/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include <QtGui/QProgressDialog>
#include <QErrorMessage>
#include <QtNetwork>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_deque.hpp>
#include <QGridLayout>

class QSystemTrayIcon;
class QTimer;
class QDialog;
class MessageDialog;
class Ui_Form;
class Ui_drawingform;
class QSpinBox;
class QMenu;
class QGroupBox;
class QTimeEdit;
class QCheckBox;
class ColorChanger;
class SpinBoxDecorator;

class MainWindow : public QWidget
{
    Q_OBJECT
    boost::scoped_ptr< Ui_Form > form;
    boost::scoped_ptr< Ui_drawingform > drawingForm;
public:
    MainWindow( QWidget *parent = 0, const std::string& xmlFile = "settings.xml" );
    virtual ~MainWindow();
protected slots:
  void checkPage( bool withShowMessage = true );
  void cancelcheckPage();
  //void Quit();
  void httpRequestFinished( int requestid, bool error );
  void httpResponseHeaderReceived( const QHttpResponseHeader& header );
  void httpDataReadProgress( int bytesRead, int totalBytes );
  void messageSlot( const QString& title, const QString& message );
  void setRandomNumbers();
  void clickAdd( const bool ignoreCount = false );
  void clickDelete();
  void setCheckBoxState( const bool state );
  void showOrHideDrawingFormMenuAction( bool on = true );
  void showOrHideFormMenuAction( bool on = true );
  void startNewTimer();
  void changeColorAndValue();
  void showAbout();
  void showAboutAction();
  void readConfiguration();
  void writeConfiguration();
signals:
   void messageSignal( const QString& title, const QString& message );
private:
  void showMessageIfWin( const int count, const int row );
  void checkDeleteButton();
  void showChildren();
  int calculateNewTimerValue();
  void downloadPage();
  void configureColorsWinLotto();
  void prepareStandardRowDecorator();
  void pushSpinBoxToDecorators( QSpinBox* spin, const int rowl );
  bool canChangeColor( QSpinBox* spinbox  ) const;
  const int getRowCount() const { return gridLayout->count() / 7; }

  void writeDays( const std::string& dayStr,
                  QGroupBox* dayGroup, QTimeEdit* basic,
                  QCheckBox* isFirst, QCheckBox* isSecond,
                  QTimeEdit* first, QTimeEdit* second );

  void readDays(const std::string& dayStr,
                QGroupBox* dayGroup, QTimeEdit* basic,
                QCheckBox* isFirst, QCheckBox* isSecond,
                QTimeEdit* first, QTimeEdit* second );

  QGridLayout* gridLayout;
  QUrl url;
  QHttp* http;
  QProgressDialog* progressDialog;
  QAction* quitAction;
  QAction* windowAction;
  QAction* drawingFormAction;
  QAction* aboutAction;
  QSystemTrayIcon* trayIcon;
  QMenu* trayIconMenu;
  QTimer* timer;
  QString pageHtlmText;
  QStringList numbers;
  QWidget* drawingFormParent;
  boost::scoped_ptr< ColorChanger > colorChanger;
  boost::scoped_ptr< MessageDialog > msgdialog;
  int checkCount;
  const short numberOfRow;
  boost::property_tree::ptree pt;
  const std::string xmlName;
  const QString timeFormat;
  boost::ptr_deque< SpinBoxDecorator > spinDecorators;
  Qt::WindowFlags flags;
};

#endif // MAINWINDOW_H
