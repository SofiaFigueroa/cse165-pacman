#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <vector>

class Object : public QObject
{
    Q_OBJECT

public:
    QPointF baseCoordinates;
    float speed = 10;
};

class Pacman : public Object, public QGraphicsItemGroup
{
    QGraphicsPixmapItem * drawPac;

public:    
    explicit Pacman();
    explicit Pacman(QPointF);
    void setRotation(int);

    qreal xincrement;
    qreal yincrement;
    bool endGameSignal = false;
};

class Ghost : public Object, public QGraphicsItemGroup
{
    QGraphicsPixmapItem * drawGhost;

public:
    explicit Ghost();
    explicit Ghost(QPointF, int type);

    //TODO: Turn this into an enum.
    int color = 0; // 0 Red; 1 Orange; 2 Pink; 3 Blue; else, Blue
};

#endif // OBJECT_H
