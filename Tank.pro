#-------------------------------------------------
#
# Project created by QtCreator 2022-04-11T21:24:00
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

RC_ICONS = TankWar.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    GameRecord.cpp \
        main.cpp \
        StartWidget.cpp \
    Tank.cpp \
    EveryThing.cpp \
    MainWidget.cpp \
    Map.cpp \
    Wall.cpp \
    Bullet.cpp \
    HelpWidget.cpp \
    SmallBullet.cpp \
    Weapon.cpp \
    BigBullet.cpp \
    Prop.cpp \
    Gartin.cpp \
    BombProp.cpp

HEADERS += \
    GameRecord.h \
        StartWidget.h \
    Tank.h \
    EveryThing.h \
    MainWidget.h \
    Map.h \
    Wall.h \
    Bullet.h \
    HelpWidget.h \
    SmallBullet.h \
    Weapon.h \
    BigBullet.h \
    Prop.h \
    Gartin.h \
    BombProp.h

FORMS += \
    GameRecord.ui \
        StartWidget.ui \
    HelpWidget.ui

RESOURCES += \
    picture.qrc \
    sound.qrc

DISTFILES +=
