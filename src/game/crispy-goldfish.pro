#-------------------------------------------------
#
# Project created by QtCreator 2013-05-21T21:22:29
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = crispy-goldfish
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lallegro -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_ttf -lallegro_color


SOURCES += main.cpp \
    button.cpp \
    game_menu.cpp

HEADERS += \
    button.h \
    game_menu.h \
    globals.h

OTHER_FILES += \
    arial.ttf
