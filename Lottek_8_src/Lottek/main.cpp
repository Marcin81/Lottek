#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTranslator>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE( icons );
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
    QApplication app(argc, argv);
    QTranslator qtTranslator;
    qtTranslator.load( ":/translations/qt_pl.qm" );
    app.installTranslator( &qtTranslator );
    const QString path = QCoreApplication::applicationDirPath()
      + QDir::separator() + QString("settings.xml");
    
    MainWindow w( 0, path.toStdString() );
    return app.exec();
}
// program ma bug'a pod windą na domyslnych ustawieniach wykryl wygrana 6 cyframi, a nic nie bylo, ale przerwalem pobieranie liczb oraz dalem recznie sprawdz, nie uzywalem wylosuj
// do weryfikacji
