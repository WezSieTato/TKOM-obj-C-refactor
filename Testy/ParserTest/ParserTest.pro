#-------------------------------------------------
#
# Project created by QtCreator 2014-04-14T16:48:32
#
#-------------------------------------------------
include(../../Refactorer/ObjC-refactor.pri)
QT       += testlib
QT       -= gui

TARGET = tst_parsertest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += tst_parsertest.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
