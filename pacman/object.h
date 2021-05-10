#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <vector>

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
    QPointF baseCoordinates;
};

#endif // OBJECT_H
