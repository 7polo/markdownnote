#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T10:02:50
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    titlebar.cpp \
    nlabel.cpp \
    connector.cpp \
    niconprovider.cpp \
    ndirfiltermodel.cpp \
    ndirtreeview.cpp \
    notetreeview.cpp \
    markdowneditor.cpp \
    settingdialog.cpp

HEADERS  += mainwindow.h \
    user.h \
    titlebar.h \
    nlabel.h \
    connector.h \
    niconprovider.h \
    ndirfiltermodel.h \
    ndirtreeview.h \
    notetreeview.h \
    markdowneditor.h \
    settingdialog.h

FORMS    += mainwindow.ui \
    titlebar.ui \
    settingdialog.ui

RESOURCES += \
    res.qrc
