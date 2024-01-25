QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET      = QWCalSoftware
TEMPLATE    = app

SOURCES += \
    main.cpp \
    qwcalsoftware.cpp \

HEADERS += \
    head.h \
    qwcalsoftware.h \

FORMS += \
    qwcalsoftware.ui \

HEADERS += head.h
UI_DIR=./UI

RESOURCES   += $$PWD/core_qss/qss.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

INCLUDEPATH += D:\7777777\Software\eigen-3.4.0
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/core_base
include ($$PWD/core_base/core_base.pri)
