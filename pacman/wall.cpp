#include "wall.h"

Wall::Wall() :
    topWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    bottomWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png")))
//    leftSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
//    rightSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png")))
{

    addToGroup(topWall);
    addToGroup(bottomWall);
//    addToGroup(leftSideWall);
//    addToGroup(rightSideWall);



}
