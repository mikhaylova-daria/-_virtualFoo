TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    macrosBase.h \
    macrosDerived.h

CONFIG += rtti_off
