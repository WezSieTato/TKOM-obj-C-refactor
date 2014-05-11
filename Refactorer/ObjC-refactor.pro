TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Bufor/sourcebufor.cpp \
    Parser/parser.cpp \
    Objects/codeobject.cpp \
    Objects/variabledeclaration.cpp \
    Objects/propertydeclaration.cpp \
    Parser/parserexception.cpp \
    Parser/parserexpectedchar.cpp \
    Objects/methodheaderpart.cpp \
    Objects/variabletype.cpp \
    Objects/methodheader.cpp \
    Objects/methodheaderdeclaration.cpp

HEADERS += \
    Bufor/sourcebufor.h \
    Parser/parser.h \
    Objects/codeobject.h \
    Objects/variabledeclaration.h \
    Objects/codeobjects.h \
    Objects/propertydeclaration.h \
    Parser/parserexception.h \
    Parser/parserexpectedchar.h \
    Objects/methodheaderpart.h \
    Objects/variabletype.h \
    Objects/methodheader.h \
    Objects/methodheaderdeclaration.h

