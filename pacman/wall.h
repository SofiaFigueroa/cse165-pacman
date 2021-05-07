#ifndef WALL_H
#define WALL_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class Wall : public QObject ,  public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Wall();

signals:
public slots:

private:
    QGraphicsPixmapItem * topWall;
    QGraphicsPixmapItem * bottomWall;
    QGraphicsPixmapItem * leftSideWall;
    QGraphicsPixmapItem * rightSideWall;
    QGraphicsPixmapItem * inerBoxRight;
    QGraphicsPixmapItem * inerBoxLeft;
    QGraphicsPixmapItem * inerBoxBottom;
    QGraphicsPixmapItem * inerBoxTop1;
    QGraphicsPixmapItem * inerBoxTop2;
    QGraphicsPixmapItem * rightBoxTop;
    QGraphicsPixmapItem * rightBoxleft;
    QGraphicsPixmapItem * rightBoxright;
    QGraphicsPixmapItem * rightBoxbottom;
    QGraphicsPixmapItem * leftLine1;
    QGraphicsPixmapItem * rightBox2Top;
    QGraphicsPixmapItem * rightBox2left;
    QGraphicsPixmapItem * rightBox2right;
    QGraphicsPixmapItem * rightBox2bottom;












};

#endif // WALL_H
