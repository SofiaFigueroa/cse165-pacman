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
    qreal xincrement;
    qreal yincrement;
    float speed = 10;
};

class Pacman : public Object, public QGraphicsItemGroup
{
    QGraphicsPixmapItem * drawPac;

public:    
    explicit Pacman();
    explicit Pacman(QPointF);
    void setRotation(int);
    bool endGameSignal = false;
};

class Ghost : public Object, public QGraphicsItemGroup
{
    QGraphicsPixmapItem * drawGhost;

public:
    explicit Ghost();
    explicit Ghost(QPointF, int type);
    int color = 0; // 0 Red; 1 Orange; 2 Pink; 3 Blue; else, Blue
};

#endif // OBJECT_H
