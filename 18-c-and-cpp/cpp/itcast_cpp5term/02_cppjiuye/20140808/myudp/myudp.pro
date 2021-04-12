TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#add WS2_32.Lib
LIBS += -lWs2_32

SOURCES += main.cpp \
    udp.c

HEADERS += \
    udp.h
