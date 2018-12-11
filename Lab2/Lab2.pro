#-------------------------------------------------
#
# Project created by QtCreator 2018-11-14T13:26:54
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    timerwindow.cpp \
    alarmwindow.cpp \
    ring.cpp \
    element_alarm.cpp \
    element_timer.cpp \
    element_timer.cpp \
    notdisturb.cpp

HEADERS += \
        mainwindow.h \
    timerwindow.h \
    alarmwindow.h \
    ring.h \
    element_alarm.h \
    element_timer.h \
    element_timer.h \
    notdisturb.h

FORMS += \
        mainwindow.ui \
    timerwindow.ui \
    alarmwindow.ui \
    element_alarm.ui \
    ring.ui \
    element_timer.ui \
    element_timer.ui \
    notdisturb.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
