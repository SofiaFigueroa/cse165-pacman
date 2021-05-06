#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <QtOpenGL>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"
//#include <OpenGL/glu.h> //added for mac


class object : public QOpenGLWidget
{
    Q_OBJECT

public:    

};

class pacman : public object, public QGraphicsItemGroup
{
//   Q_OBJECT


public:

    // On Keypress
    void setTranslation();
    explicit pacman();

signals:
public slots:
private:
    QGraphicsPixmapItem * drawPac;
};




class ghost : public object
{
public:
    // Controled by AI, as opposed to keypress
    void setTranslation();
};


#endif // OBJECT_H
