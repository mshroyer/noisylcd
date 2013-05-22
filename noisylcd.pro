#-------------------------------------------------
#
# Project created by QtCreator 2013-05-07T21:10:42
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -Wall

TARGET = noisylcd
TEMPLATE = app


SOURCES += main.cpp\
        noisylcd.cpp \
    noisysettings.cpp \
    tonespinbox.cpp

HEADERS  += noisylcd.h \
    noisysettings.h \
    tonespinbox.h

FORMS    += \
    noisysettings.ui
