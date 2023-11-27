QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aed.cpp \
    analysisStage.cpp \
    cprStage.cpp \
    electrodeStage.cpp \
    helpStage.cpp \
    main.cpp \
    mainwindow.cpp \
    responsivenessStage.cpp \
    shockStage.cpp \
    victim.cpp \
    aedStage.cpp

HEADERS += \
    aed.h \
    analysisStage.h \
    constants.h \
    cprStage.h \
    electrodeStage.h \
    helpStage.h \
    mainwindow.h \
    responsivenessStage.h \
    shockStage.h \
    victim.h \
    aedStage.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
