#include "wall.h"

Wall::Wall() :
    topWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    bottomWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    leftSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(45,550))),
    rightSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(45,550)))
{
    topWall->setPos(QPointF(0,0) - QPointF(topWall->boundingRect().width()/2,
                    topWall->boundingRect().height() + 200)); // x,y + move amount
    bottomWall->setPos(QPointF(0,0) - QPointF(topWall->boundingRect().width()/2,
                    bottomWall->boundingRect().height() + -320)); // x,y + move amount
    leftSideWall->setPos(QPointF(0,0) - QPointF(topWall->boundingRect().width()/1.79,
                    leftSideWall->boundingRect().height() + -320));

    rightSideWall->setPos(QPointF(0,0) - QPointF(topWall->boundingRect().width()/-2,
                    rightSideWall->boundingRect().height() + -320));

    addToGroup(topWall);
    addToGroup(bottomWall);
    addToGroup(leftSideWall);
    addToGroup(rightSideWall);

}
