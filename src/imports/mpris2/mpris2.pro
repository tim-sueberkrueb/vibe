TARGET = mpris2plugin
TARGETPATH = Vibe/Mpris
IMPORT_VERSION = 1.0

QT += dbus qml quick

dbus_interfaces.files = \
    $$PWD/org.freedesktop.DBus.Properties.xml \
    $$PWD/org.mpris.MediaPlayer2.Player.xml \
    $$PWD/org.mpris.MediaPlayer2.xml
dbus_interfaces.header_flags = -N
DBUS_INTERFACES += dbus_interfaces

SOURCES += \
    $$PWD/mpris2engine.cpp \
    $$PWD/mpris2player.cpp \
    $$PWD/plugin.cpp

CONFIG += no_cxx_module
load(liri_qml_plugin)
