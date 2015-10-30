TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vector.cpp \
    matrix3x3.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vector.h \
    matrix3x3.h

