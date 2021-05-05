#include "wall.h"

Wall::Wall() :
    topWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    bottomWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    leftSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(45,550))),
    rightSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(45,550))),
    inerBoxRight(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(10, 100))),
    inerBoxLeft(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(10, 100))),
    inerBoxBottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(170, 10)))




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


    inerBoxRight->setPos(QPointF(400,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxRight->boundingRect().height() + -50));
    inerBoxLeft->setPos(QPointF(240,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxLeft->boundingRect().height() + -50));
    inerBoxBottom->setPos(QPointF(240,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxBottom->boundingRect().height() + -50));


    addToGroup(inerBoxRight);
    addToGroup(inerBoxLeft);
    addToGroup(inerBoxBottom);


}
