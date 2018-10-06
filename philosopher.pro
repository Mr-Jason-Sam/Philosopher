TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    philosopher.cpp \
    waiter.cpp

HEADERS += \
    philosopher.h \
    waiter.h

LIBS += -pthread
