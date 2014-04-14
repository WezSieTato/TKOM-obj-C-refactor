TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Bufor/sourcebufor.cpp \
    Parser/parser.cpp

HEADERS += \
    Bufor/sourcebufor.h \
    Parser/parser.h

