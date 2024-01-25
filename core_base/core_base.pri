QT += network
greaterThan(QT_MAJOR_VERSION,4){
lessThan(QT_MAJOR_VERSION,6){
android {QT += androidextras}
} else {
QT += core-private
}}

MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj

!android {
!wasm {
DESTDIR = $$PWD/../bin
}}

CONFIG += warn_off
CONFIG += resources_big

include($$PWD/h3.pri)
INCLUDEPATH += $$PWD

HEADERS += $$PWD/iconhelper.h
SOURCES += $$PWD/iconhelper.cpp

HEADERS += $$PWD/quihelper.h
SOURCES += $$PWD/quihelper.cpp

!contains(DEFINES,no_qrc_image){
RESOURCES += $$PWD/qrc/image.qrc
}

!contains(DEFINES,no_qrc_qm){
RESOURCES += $$PWD/qrc/qm.qrc
}

!contains(DEFINES,no_qrc_font){
RESOURCES += $$PWD/qrc/font.qrc
}
