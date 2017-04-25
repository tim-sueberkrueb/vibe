TARGET = polkitplugin
TARGETPATH = Vibe/PolicyKit
IMPORT_VERSION = 1.0

QT += core core-private dbus qml quick

CONFIG += no_keywords link_pkgconfig
PKGCONFIG += polkit-qt5-1 polkit-qt5-core-1 polkit-qt5-agent-1

SOURCES += \
    $$PWD/listener_p.cpp \
    $$PWD/logging_p.cpp \
    $$PWD/policykitagent.cpp \
    $$PWD/plugin.cpp

CONFIG += no_cxx_module
load(liri_qml_plugin)
