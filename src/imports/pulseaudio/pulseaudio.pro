TARGET = pulseaudioplugin
TARGETPATH = Vibe/PulseAudio
IMPORT_VERSION = 1.0

QT += qml quick

CONFIG += link_pkgconfig
PKGCONFIG += libpulse libpulse-mainloop-glib

QML_FILES += \
    $$files(*.qml)

SOURCES += \
    $$PWD/plugin.cpp \
    $$PWD/qpulseaudio/card.cpp \
    $$PWD/qpulseaudio/client.cpp \
    $$PWD/qpulseaudio/context.cpp \
    $$PWD/qpulseaudio/device.cpp \
    $$PWD/qpulseaudio/maps.cpp \
    $$PWD/qpulseaudio/operation.cpp \
    $$PWD/qpulseaudio/port.cpp \
    $$PWD/qpulseaudio/profile.cpp \
    $$PWD/qpulseaudio/pulseaudio.cpp \
    $$PWD/qpulseaudio/pulseobject.cpp \
    $$PWD/qpulseaudio/ref.cpp \
    $$PWD/qpulseaudio/sink.cpp \
    $$PWD/qpulseaudio/sinkinput.cpp \
    $$PWD/qpulseaudio/source.cpp \
    $$PWD/qpulseaudio/sourceoutput.cpp \
    $$PWD/qpulseaudio/stream.cpp \
    $$PWD/qpulseaudio/volumeobject.cpp \
    $$PWD/qpulseaudio/debug.cpp \
    $$PWD/qpulseaudio/server.cpp \
    $$PWD/qpulseaudio/streamrestore.cpp

INCLUDEPATH += $$PWD $$PWD/qpulseaudio

CONFIG += no_cxx_module
load(liri_qml_plugin)
