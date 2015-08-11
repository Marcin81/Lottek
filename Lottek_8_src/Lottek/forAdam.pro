# -------------------------------------------------
# Project created by QtCreator 2009-03-25T12:07:31
# License: GPL 
# Owner: Marcin Brysz
# Contact: unemployed81@gmail.com / bryszmarcin@gmail.com

# -------------------------------------------------
QT += network
TARGET = Lottek
ICON = ball.icns
SOURCES += main.cpp \
    mainwindow.cpp \
    messagedialog.cpp \
    dayofweek.cpp \
    lottotools.cpp \
    spinboxdecorator.cpp \
    colorchanger.cpp
HEADERS += mainwindow.h \
    messagedialog.h \
    dayofweek.h \
    lottotools.h \
    filtermodifiedchange.h \
    spinboxdecorator.h \
    colorchanger.h
RESOURCES += translations.qrc \
    icons.qrc
FORMS += messagedialog.ui \
    drawingform.ui \
    about.ui
unix {
  INCLUDEPATH += /opt/local/include;/Users/marcinbrysz/zrodla/boost-trunk_53033
  QMAKE_LIBDIR += /opt/local/lib
}

win32 {
  INCLUDEPATH += c:\zrodla\boost_svn_53033\
  DEFINES += QT_DLL
}
