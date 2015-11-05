TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vector.cpp \
    matrix4x3.cpp \
    rotationmatrix.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vector.h \
    matrix4x3.h \
    rotationmatrix.h

