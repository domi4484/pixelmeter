#-------------------------------------------------
#
# Project PixelMeter
#
# (C) 2014 Damiano Lombardi
#
#-------------------------------------------------

TEMPLATE  = app

TARGET    = PixelMeter

QT       += core gui sql network script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += debug

MOC_DIR            = build
RCC_DIR            = build
UI_DIR             = build
!win32:OBJECTS_DIR = build

SOURCES += main.cpp\
    MainWindow.cpp \
    Slider.cpp \
    Ruler.cpp \
    RulerGraphicsView.cpp \
    RulerDialog.cpp

HEADERS  += MainWindow.h \
    Slider.h \
    Ruler.h \
    RulerGraphicsView.h \
    RulerDialog.h

FORMS    += MainWindow.ui \
    Ruler.ui

