TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vector.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vector.h

