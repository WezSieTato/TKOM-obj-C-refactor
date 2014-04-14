#-------------------------------------------------
#
# Project created by QtCreator 2014-04-03T15:50:51
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_bufortest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_bufortest.cpp \
            ../../Refactorer/Bufor/sourcebufor.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
