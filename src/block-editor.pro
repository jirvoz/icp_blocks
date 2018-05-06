# Block editor project to ICP course
# Authors: Jiri Vozar
#          Vaclav Dolezal

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blockeditor
TEMPLATE = app

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    blockitem.cpp \
    blockscene.cpp \
    blockslot.cpp \
    blockpipe.cpp \
    datacontainer.cpp \
    inputdialog.cpp

HEADERS += \
    mainwindow.h \
    blockitem.h \
    blockscene.h \
    blockslot.h \
    blockpipe.h \
    datacontainer.h \
    inputdialog.h

FORMS += \
    mainwindow.ui
