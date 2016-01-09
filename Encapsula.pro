#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T13:18:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Encapsula
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_features2d -lopencv_xfeatures2d -lopencv_calib3d

SOURCES += main.cpp\
        mainwindow.cpp \
    ocv_descriptor.cpp \
    ocv_capturer.cpp \
    ocv_player.cpp \
    ocv_detector.cpp \
    bow.cpp \
    imageonimage.cpp

HEADERS  += mainwindow.h \
    ocv_descriptor.h \
    ocv_capturer.h \
    ocv_player.h \
    ocv_detector.h \
    bow.h \
    imageonimage.h

FORMS    += mainwindow.ui
