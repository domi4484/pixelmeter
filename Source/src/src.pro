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

linux-g++-64:                                 PLATFORM = "linux-g++-64"
else:linux-g++:                               PLATFORM = "linux-g++-32"
else:linux-arm*:                              PLATFORM = "linux-arm"
else:win32 {
   contains      (QMAKE_TARGET.arch, x86_64): PLATFORM = "win64"
   else:contains (QMAKE_TARGET.arch, x86)     PLATFORM = "win32-msvc"
   else:                                      PLATFORM = "win32-mingw"
}
isEmpty (PLATFORM):   error (PLATFORM is undefined.)

INCLUDEPATH *= "$$_PRO_FILE_PWD_/"
DESTDIR = "$$_PRO_FILE_PWD_/../bin/$$PLATFORM"
# Installation on the target
target.path = "$$_PRO_FILE_PWD_/../bin/$$PLATFORM"
INSTALLS *= target

SOURCES += main.cpp\
    MainWindow.cpp \
    Slider.cpp \
    Ruler.cpp \
    RulerDialog.cpp

HEADERS  += MainWindow.h \
    Slider.h \
    Ruler.h \
    RulerDialog.h

FORMS    += MainWindow.ui \
    Ruler.ui

RESOURCES += \
    Resources/Resources.qrc

