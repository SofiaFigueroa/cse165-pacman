#include "wall.h"

Wall::Wall() :
    topWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    bottomWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png")))
//    leftSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
//    rightSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png")))
{
    topWall->setPos(QPointF(0,0) - QPointF(topWall->boundingRect().width()/2,
                    topWall->boundingRect().height() + 200)); // x,y + move amount
    addToGroup(topWall);
    addToGroup(bottomWall);
//    addToGroup(leftSideWall);
//    addToGroup(rightSideWall);



}
