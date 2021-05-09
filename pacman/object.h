#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
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
    explicit Pacman(QPointF);
    QPointF baseCoordinates;
};

class Ghost : public Object, public QGraphicsItemGroup
{
    QGraphicsPixmapItem * drawGhost;

public:
    explicit Ghost();
    explicit Ghost(QPointF);
    QPointF baseCoordinates;
    //bool GhostCollidesWithPacman(QPointF);
};


#endif // OBJECT_H
