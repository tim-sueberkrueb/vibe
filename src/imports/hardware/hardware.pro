TARGET = hardwareplugin
TARGETPATH = Vibe/Hardware
IMPORT_VERSION = 1.0

QT += qml quick Solid
CONFIG += link_pkgconfig
PKGCONFIG += Fluid

SOURCES += \
    $$PWD/battery.cpp \
    $$PWD/hardwareengine.cpp \
    $$PWD/plugin.cpp \
    $$PWD/storagedevice.cpp

CONFIG += no_cxx_module
load(liri_qml_plugin)
