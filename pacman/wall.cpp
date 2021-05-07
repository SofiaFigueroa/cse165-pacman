#include "wall.h"

Wall::Wall() :
    topWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    bottomWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    leftSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(45,550))),
    rightSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(45,550))),
    inerBoxRight(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(15, 90))),
    inerBoxLeft(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(15, 90))),
    inerBoxBottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(175, 15))),
    inerBoxTop1(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(50, 15))),
    inerBoxTop2(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(50, 15))),
    rightBoxTop(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 13))),
    rightBoxleft(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 41))),
    rightBoxright(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 41))),
    rightBoxbottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 14))),
    leftLine1(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(90, 20))),
    rightBox2Top(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 13))),
    rightBox2left(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 41))),
    rightBox2right(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 41))),
    rightBox2bottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 14)))



{
    //general layout
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

    //inner box
    inerBoxRight->setPos(QPointF(400,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxRight->boundingRect().height() + -40));
    inerBoxLeft->setPos(QPointF(240,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxLeft->boundingRect().height() + -40));
    inerBoxBottom->setPos(QPointF(240,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxBottom->boundingRect().height() + -40));
    inerBoxTop1->setPos(QPointF(362,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxTop1->boundingRect().height() + 50));
    inerBoxTop2->setPos(QPointF(243,1) - QPointF(topWall->boundingRect().width()/2,
                    inerBoxTop2->boundingRect().height() + 50));

    addToGroup(inerBoxRight);
    addToGroup(inerBoxLeft);
    addToGroup(inerBoxBottom);
    addToGroup(inerBoxTop1);
    addToGroup(inerBoxTop2);

    //box to the further top left
    rightBoxTop->setPos(QPointF(90,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxTop->boundingRect().height() + 150));
    rightBoxleft->setPos(QPointF(90, 1) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxleft->boundingRect().height() + 110));
    rightBoxright->setPos(QPointF(180,10) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxright->boundingRect().height() + 120));
    rightBoxbottom->setPos(QPointF(90,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxbottom->boundingRect().height() + 100));

    addToGroup(rightBoxTop);
    addToGroup(rightBoxleft);
    addToGroup(rightBoxright);
    addToGroup(rightBoxbottom);

    //line after the further top box to the left
    leftLine1->setPos(QPointF(90,1) - QPointF(topWall->boundingRect().width()/2,
                    leftLine1->boundingRect().height() + 30));

    addToGroup(leftLine1);

    // box to the the upper right
    rightBox2Top->setPos(QPointF(500,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2Top->boundingRect().height() + 150));
    rightBox2left->setPos(QPointF(500, 1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2left->boundingRect().height() + 110));
    rightBox2right->setPos(QPointF(590,9) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2right->boundingRect().height() + 120));
    rightBox2bottom->setPos(QPointF(500,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2bottom->boundingRect().height() + 100));

    addToGroup(rightBox2Top);
    addToGroup(rightBox2left);
    addToGroup(rightBox2right);
    addToGroup(rightBox2bottom);
}
