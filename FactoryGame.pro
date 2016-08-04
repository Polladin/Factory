#-------------------------------------------------
#
# Project created by QtCreator 2016-07-28T23:33:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FactoryGame
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        factorygamemainwindow.cpp \
    factorymap.cpp \
    factorycell.cpp \
    factoryobject.cpp \
    factoryobjectwall.cpp \
    factoryobjectdisplay.cpp \
    factoryobjectfloor.cpp \
    buildmenu.cpp \
    buildironbuyer.cpp \
    builditem.cpp \
    menuitem.cpp \
    menuironbuyer.cpp \
    menudisplay.cpp \
    factoryobjectfloorpixel.cpp \
    factoryobjectwallpixel.cpp \
    factoryobjectroadpixel.cpp \
    factoryobjectroad.cpp \
    menuironbuyerpixel.cpp \
    factoryview.cpp \
    factorymapobserver.cpp \
    factoryobjectbuilder.cpp \
    factoryobjectpixelbuilder.cpp \
    factoryobjectpixel.cpp \
    testmap1.cpp \
    factoryobjectgrass.cpp \
    factoryobjectgrasspixel.cpp

HEADERS  += factorygamemainwindow.h \
    factorymap.h \
    factorycell.h \
    factoryobject.h \
    factoryobjectwall.h \
    factoryobjectdisplay.h \
    factoryobjectfloor.h \
    buildmenu.h \
    buildironbuyer.h \
    builditem.h \
    menuitem.h \
    menuironbuyer.h \
    menudisplay.h \
    factoryobjectfloorpixel.h \
    factoryobjectwallpixel.h \
    factoryobjectroadpixel.h \
    factoryobjectroad.h \
    menuironbuyerpixel.h \
    factoryview.h \
    factorymapobserver.h \
    factoryobjectbuilder.h \
    factoryobjectpixelbuilder.h \
    factoryobjectpixel.h \
    testmap1.h \
    factoryobjectgrass.h \
    factoryobjectgrasspixel.h

FORMS    += factorygamemainwindow.ui

RESOURCES += \
    resources.qrc
