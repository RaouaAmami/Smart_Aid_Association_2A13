QT += printsupport
QT       += core gui
QT       += core gui sql
QT += core gui network
QT       += charts serialport multimedia multimediawidgets  widgets

TARGET = mail
CONFIG += c++11
QT       += core gui \
    quick
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    benevol.cpp \
    chefprotocol.cpp \
    employee.cpp \
    enfant.cpp \
    main.cpp \
    connection.cpp \
    mainwindow.cpp \
    parking.cpp \
    rania.cpp \
    rawaa.cpp \
    stat.cpp \
    stmp.cpp \
    video.cpp

HEADERS += \
    arduino.h \
    benevol.h \
    chefprotocol.h \
    employee.h \
    enfant.h \
    mainwindow.h \
    connection.h \
    parking.h \
    rania.h \
    rawaa.h \ \
    stat.h \
    stmp.h \
    video.h

FORMS += \
    chefprotocol.ui \
    mainwindow.ui \
    rania.ui \
    rawaa.ui \
    stat.ui \
    video.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

