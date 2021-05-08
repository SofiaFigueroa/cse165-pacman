QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = MYGL
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    scene.cpp \
    wall.cpp

HEADERS += \
    mainwindow.h \
    object.h \
    scene.h \
    wall.h

FORMS += \
    mainwindow.ui

#LIBS  += -lopengl32
LIBS    +=  -framework OpenGL #added for Mac

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
