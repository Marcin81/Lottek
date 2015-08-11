#include "messagedialog.h"

MessageDialog::MessageDialog( QWidget* pParent )
  : QDialog( pParent )
{
  mydialog = new Ui::Dialog;
  mydialog->setupUi( this );
  setWindowFlags( Qt::Tool
    | Qt::WindowTitleHint
    | Qt::CustomizeWindowHint);

  // Sygnaly:
  connect( mydialog->pushButtonOK, SIGNAL(clicked()), this, SLOT(hide()) );
}

MessageDialog::~MessageDialog()
{

}

void MessageDialog::setMessageText( const QString& message )
{
  mydialog->textEdit->setText( message );
}
