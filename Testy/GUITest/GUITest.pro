#-------------------------------------------------
#
# Project created by QtCreator 2014-05-25T10:34:44
#
#-------------------------------------------------
include(../../Refactorer/ObjC-refactor.pri)
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUITest
TEMPLATE = app


SOURCES += main.cpp\
        refactorerwindow.cpp

HEADERS  += refactorerwindow.h

FORMS    += refactorerwindow.ui
