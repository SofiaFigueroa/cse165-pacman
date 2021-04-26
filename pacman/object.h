#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <QtOpenGL>
#include "mainwindow.h"
//#include <OpenGL/glu.h> //added for mac


class object : public QOpenGLWidget
{
    Q_OBJECT

public:    

};

class pacman : public object
{
public:

    // On Keypress
    void setTranslation();
};

class ghost : public object
{
public:
    // Controled by AI, as opposed to keypress
    void setTranslation();
};


#endif // OBJECT_H
