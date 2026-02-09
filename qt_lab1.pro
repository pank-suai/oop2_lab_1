QT += core gui widgets

TARGET = qt_lab1
TEMPLATE = app

CONFIG += c++23

SOURCES += \
    src/main.cpp \
    src/greetingform.cpp \
    src/calculatorform.cpp

HEADERS += \
    src/greetingform.hpp \
    src/calculatorform.hpp

FORMS += \
    src/greetingform.ui \
    src/calculatorform.ui

DESTDIR = build
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
UI_DIR = build/ui
