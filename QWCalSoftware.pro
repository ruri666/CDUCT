QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qwcalsoftware.cpp \
    qwparainput.cpp \
    qwparainput2.cpp \
    qwparainput3.cpp \
    qwparainput4.cpp \
    qwparainput5.cpp

HEADERS += \
    qwcalsoftware.h \
    qwparainput.h \
    qwparainput2.h \
    qwparainput3.h \
    qwparainput4.h \
    qwparainput5.h

FORMS += \
    qwcalsoftware.ui \
    qwparainput.ui \
    qwparainput2.ui \
    qwparainput3.ui \
    qwparainput4.ui \
    qwparainput5.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

INCLUDEPATH += D:\7777777\Software\eigen-3.4.0
