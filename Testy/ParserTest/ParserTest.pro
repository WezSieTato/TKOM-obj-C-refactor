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
    ../../Refactorer/Objects/propertydeclaration.cpp \
    ../../Refactorer/Objects/variabledeclaration.cpp \
    ../../Refactorer/Parser/parserexception.cpp \
    ../../Refactorer/Parser/parserexpectedchar.cpp \
    ../../Refactorer/Objects/variabletype.cpp \
    ../../Refactorer/Objects/methodheaderpart.cpp \
    ../../Refactorer/Objects/methodheader.cpp \
    ../../Refactorer/Objects/methoddeclaration.cpp \
    ../../Refactorer/Objects/methoddefinition.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
