#-------------------------------------------------
#
# Project created by QtCreator 2014-04-14T16:48:32
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_parsertest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_parsertest.cpp \
            ../../Refactorer/Bufor/sourcebufor.cpp \
            ../../Refactorer/Parser/parser.cpp \
    ../../Refactorer/Objects/codeobject.cpp \
    ../../Refactorer/Objects/variabledeclaration.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
