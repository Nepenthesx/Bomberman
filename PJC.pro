QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomb.cpp \
    bomber.cpp \
    bombupgrade.cpp \
    character.cpp \
    crossbomb.cpp \
    dynamicobject.cpp \
    floortile.cpp \
    gamemanager.cpp \
    gameobject.cpp \
    graphicobject.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    movableobject.cpp \
    player.cpp \
    powerupgrade.cpp \
    rocktile.cpp \
    squarebomb.cpp \
    staticobject.cpp \
    temporaryobject.cpp \
    walltile.cpp

HEADERS += \
    bomb.h \
    bomber.h \
    bombupgrade.h \
    character.h \
    crossbomb.h \
    dynamicobject.h \
    floortile.h \
    gamemanager.h \
    gameobject.h \
    graphicobject.h \
    item.h \
    mainwindow.h \
    movableobject.h \
    player.h \
    powerupgrade.h \
    rocktile.h \
    squarebomb.h \
    staticobject.h \
    temporaryobject.h \
    walltile.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH += "eigen-3.4.0"
