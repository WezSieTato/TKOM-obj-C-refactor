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
    Objects/methoddeclaration.cpp \
    Objects/methoddefinition.cpp \
    Bufor/sourcebuforexception.cpp \
    Bufor/sourcebuforoutofboundsexception.cpp \
    Parser/parserexpectedstring.cpp \
    Objects/synthesizedvariable.cpp \
    Objects/synthesizeblock.cpp \
    Objects/classinterface.cpp \
    Objects/classpart.cpp

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
    Objects/methoddeclaration.h \
    Objects/methoddefinition.h \
    Bufor/sourcebuforexception.h \
    Bufor/sourcebuforoutofboundsexception.h \
    Parser/parserexpectedstring.h \
    Objects/synthesizedvariable.h \
    Objects/synthesizeblock.h \
    Objects/classinterface.h \
    Objects/classpart.h

