#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
//#include <QtOpenGL>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class Object : public QObject
{
    Q_OBJECT
};

class Pacman : public Object, public QGraphicsItemGroup
{
    QGraphicsPixmapItem * drawPac;

public:
    explicit Pacman();
    QPointF baseCoordinates;
};


class Ghost : public Object
{

};


#endif // OBJECT_H
