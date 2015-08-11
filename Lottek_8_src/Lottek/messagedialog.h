/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
*/
#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H
#include "ui_messagedialog.h"
#include <QDialog>

class MessageDialog : public QDialog
{
  Q_OBJECT
public:
    MessageDialog( QWidget* pParent = 0 );
    virtual ~MessageDialog();

    void setMessageText( const QString& message );
    void useParentPulpit();
    void useParentWindow();
private:
  Ui_Dialog* mydialog;
};

#endif // MESSAGEDIALOG_H
