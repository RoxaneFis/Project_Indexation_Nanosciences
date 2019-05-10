TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

SOURCES += \\
        main.cpp \
    kdtree.cpp \
    noeud.cpp \
    point.cpp \
    proteine.cpp \
    result.cpp

HEADERS += \
    kdtree.h \
    noeud.h \
    point.h \
    proteine.h \
    result.h
