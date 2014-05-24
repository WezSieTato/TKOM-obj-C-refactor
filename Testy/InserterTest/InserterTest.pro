#-------------------------------------------------
#
# Project created by QtCreator 2014-05-24T12:48:01
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_insertertesttest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_insertertesttest.cpp \
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
    ../../Refactorer/Objects/methoddefinition.cpp \
    ../../Refactorer/Bufor/sourcebuforexception.cpp \
    ../../Refactorer/Bufor/sourcebuforoutofboundsexception.cpp \
    ../../Refactorer/Parser/parserexpectedstring.cpp \
    ../../Refactorer/Objects/synthesizeblock.cpp \
    ../../Refactorer/Objects/synthesizedvariable.cpp \
    ../../Refactorer/Objects/classinterface.cpp \
    ../../Refactorer/Objects/classpart.cpp \
    ../../Refactorer/Objects/classimplementation.cpp \
    ../../Refactorer/Files/file.cpp \
    ../../Refactorer/Inserter/inserter.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
