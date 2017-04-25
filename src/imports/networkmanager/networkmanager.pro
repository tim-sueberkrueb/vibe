TARGET = nmplugin
TARGETPATH = Vibe/NetworkManager
IMPORT_VERSION = 1.0

QT += core dbus network qml quick NetworkManagerQt ModemManagerQt

CONFIG += no_keywords link_pkgconfig
DEFINES += WITH_MODEMMANAGER_SUPPORT=1
PKGCONFIG += NetworkManager libnm libnm-glib
PKGCONFIG += ModemManager mm-glib

QT.ModemManagerQt.includes += /usr/include/KF5

SOURCES += \
    $$PWD/appletproxymodel.cpp \
    $$PWD/availabledevices.cpp \
    $$PWD/connectionicon.cpp \
    $$PWD/debug.cpp \
    $$PWD/enabledconnections.cpp \
    $$PWD/enums.cpp \
    $$PWD/handler.cpp \
    $$PWD/networkitemslist.cpp \
    $$PWD/networkmodel.cpp \
    $$PWD/networkmodelitem.cpp \
    $$PWD/networkstatus.cpp \
    $$PWD/plugin.cpp \
    $$PWD/uiutils.cpp

CONFIG += no_cxx_module
load(liri_qml_plugin)
