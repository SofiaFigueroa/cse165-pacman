#ifndef WALL_H
#define WALL_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>


class Wall : public QObject , public QGraphicsItemGroup
{
    Q_OBJECT

public:
    explicit Wall();
    bool collidesWithObject(QPointF);

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
    QGraphicsPixmapItem * rightBox2left2;
    QGraphicsPixmapItem * rightBoxMiddle;
    QGraphicsPixmapItem * rightBoxMiddleLeft;
    QGraphicsPixmapItem * rightBoxMiddleTop;
    QGraphicsPixmapItem * rightBox2right;
    QGraphicsPixmapItem * rightBox2bottom;
    QGraphicsPixmapItem * bottomLine;
    QGraphicsPixmapItem * bottomRightLine;
    QGraphicsPixmapItem * bottomBoxRightTop;
    QGraphicsPixmapItem * bottomBoxRightSideR;
    QGraphicsPixmapItem * bottomBoxRightSideL;
    QGraphicsPixmapItem * bottomBoxRightDown;
    QGraphicsPixmapItem * MiddleBottomBoxTop;
    QGraphicsPixmapItem * MiddleBottomBoxR;
    QGraphicsPixmapItem * leftBox3Right;
    QGraphicsPixmapItem * leftBox3left2;
    QGraphicsPixmapItem * MiddleTopLineCenter;
    QPropertyAnimation * xAnimation;

};

#endif // WALL_H
