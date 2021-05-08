#include "wall.h"
#include "object.h"
#include <iostream>

Wall::Wall() :
    topWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    bottomWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png"))),
    leftSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(35,540))),
    rightSideWall(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(35,540))),
    inerBoxRight(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(15, 90))),
    inerBoxLeft(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(15, 90))),
    inerBoxBottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(175, 15))),
    inerBoxTop1(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(50, 15))),
    inerBoxTop2(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(50, 15))),
    rightBoxTop(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(110, 13))),
    rightBoxleft(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 35))),
    rightBoxright(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 35))),
    rightBoxbottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(110, 14))),
    leftLine1(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(120, 20))),
    rightBox2Top(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 13))),
    rightBox2left(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 20))),
    rightBox2left2(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 75))),
    rightBoxMiddle(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(60, 13))),
    rightBoxMiddleLeft(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 20))),
    rightBoxMiddleTop(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(60, 13))),
    rightBox2right(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 120))),
    rightBox2bottom(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 14))),
    bottomLine(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 20))),
    bottomRightLine(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(170, 20))),
    bottomBoxRightTop(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 13))),
    bottomBoxRightSideR(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 90))),
    bottomBoxRightSideL(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(13, 90))),
    bottomBoxRightDown(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(100, 14))),
    MiddleBottomBoxTop(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(90, 20))),
    MiddleBottomBoxR(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(20, 90))),
    leftBox3Right(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(20, 102))),
    leftBox3left2(new QGraphicsPixmapItem(QPixmap(":/NeonWall2.png").scaled(20, 102))),
    MiddleTopLineCenter(new QGraphicsPixmapItem(QPixmap(":/NeonWall.png").scaled(120, 20)))

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
    rightBoxTop->setPos(QPointF(80,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxTop->boundingRect().height() + 130));
    rightBoxleft->setPos(QPointF(70, 1) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxleft->boundingRect().height() + 105));
    rightBoxright->setPos(QPointF(180,10) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxright->boundingRect().height() + 110));
    rightBoxbottom->setPos(QPointF(75,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxbottom->boundingRect().height() + 95));

    addToGroup(rightBoxTop);
    addToGroup(rightBoxleft);
    addToGroup(rightBoxright);
    addToGroup(rightBoxbottom);

    //line after the further top box to the left
    leftLine1->setPos(QPointF(0,1) - QPointF(topWall->boundingRect().width()/2,
                    leftLine1->boundingRect().height() + 30));

    addToGroup(leftLine1);

    // box to the the upper right
    rightBox2Top->setPos(QPointF(485,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2Top->boundingRect().height() + 140));
    rightBox2left->setPos(QPointF(485, 1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2left->boundingRect().height() + 120));
    rightBox2left2->setPos(QPointF(535, 5) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2left2->boundingRect().height() + 50));
    rightBoxMiddle->setPos(QPointF(485,3) - QPointF(topWall->boundingRect().width()/2,
                    rightBoxMiddle->boundingRect().height() + 120));
    rightBoxMiddleLeft->setPos(QPointF(485, 10) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2left->boundingRect().height() + 30));
    rightBoxMiddleTop->setPos(QPointF(485, 1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2left->boundingRect().height() + 25));
    rightBox2right->setPos(QPointF(575,9) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2right->boundingRect().height() + 30));
    rightBox2bottom->setPos(QPointF(485,1) - QPointF(topWall->boundingRect().width()/2,
                    rightBox2bottom->boundingRect().height() + 10));

    addToGroup(rightBox2Top);
    addToGroup(rightBox2left);
    addToGroup(rightBox2left2);
    addToGroup(rightBoxMiddle);
    addToGroup(rightBoxMiddleLeft);
    addToGroup(rightBoxMiddleTop);
    addToGroup(rightBox2right);
    addToGroup(rightBox2bottom);

    //line at the bottom
    bottomLine->setPos(QPointF(70,1) - QPointF(topWall->boundingRect().width()/2,
                    bottomLine->boundingRect().height() + -50));

    addToGroup(bottomLine);

    //line at the bottom to the right
    bottomRightLine->setPos(QPointF(480,1) - QPointF(topWall->boundingRect().width()/2,
                    bottomLine->boundingRect().height() + -70));

    addToGroup(bottomRightLine);

    // bottom right box
    bottomBoxRightTop->setPos(QPointF(470,1) - QPointF(topWall->boundingRect().width()/2,
                    bottomBoxRightTop->boundingRect().height() + -140));
    bottomBoxRightSideR->setPos(QPointF(560, 1) - QPointF(topWall->boundingRect().width()/2,
                    bottomBoxRightSideR->boundingRect().height() + -220));
    bottomBoxRightSideL->setPos(QPointF(470,10) - QPointF(topWall->boundingRect().width()/2,
                    bottomBoxRightSideL->boundingRect().height() + -220));
    bottomBoxRightDown->setPos(QPointF(470,1) - QPointF(topWall->boundingRect().width()/2,
                    bottomBoxRightDown->boundingRect().height() + -230));

    addToGroup(bottomBoxRightTop);
    addToGroup(bottomBoxRightSideR);
    addToGroup(bottomBoxRightSideL);
    addToGroup(bottomBoxRightDown);

    // Middle bottom shape
    MiddleBottomBoxTop->setPos(QPointF(280,1) - QPointF(topWall->boundingRect().width()/2,
                    MiddleBottomBoxTop->boundingRect().height() + -230));
    MiddleBottomBoxR->setPos(QPointF(370,1) - QPointF(topWall->boundingRect().width()/2,
                    MiddleBottomBoxR->boundingRect().height() + -225));

    addToGroup(MiddleBottomBoxTop);
    addToGroup(MiddleBottomBoxR);

    // box to the the bottom left

    leftBox3Right->setPos(QPointF(150, 1) - QPointF(topWall->boundingRect().width()/2,
                    leftBox3Right->boundingRect().height() + -233));
    leftBox3left2->setPos(QPointF(65, 5) - QPointF(topWall->boundingRect().width()/2,
                    leftBox3left2->boundingRect().height() + -230));


    addToGroup(leftBox3Right);
    addToGroup(leftBox3left2);

    // Middle Top line
    MiddleTopLineCenter->setPos(QPointF(260,1) - QPointF(topWall->boundingRect().width()/2,
                    MiddleTopLineCenter->boundingRect().height() + 120));
    addToGroup(MiddleTopLineCenter);


}

bool Wall::collidesWithPacMan()
{
    QList<QGraphicsItem*> collidingItems = topWall->collidingItems();
    collidingItems.append(bottomWall->collidingItems());
    collidingItems.append(leftSideWall->collidingItems());
    collidingItems.append(rightSideWall->collidingItems());
    collidingItems.append(inerBoxRight->collidingItems());
    collidingItems.append(inerBoxLeft->collidingItems());
    collidingItems.append(inerBoxBottom->collidingItems());
    collidingItems.append(inerBoxTop1->collidingItems());
    collidingItems.append(inerBoxTop2->collidingItems());
    collidingItems.append(rightBoxTop->collidingItems());
    collidingItems.append(rightBoxleft->collidingItems());
    collidingItems.append(rightBoxright->collidingItems());
    collidingItems.append(rightBoxbottom->collidingItems());
    collidingItems.append(leftLine1->collidingItems());
    collidingItems.append(rightBox2Top->collidingItems());
    collidingItems.append(rightBox2left->collidingItems());
    collidingItems.append(rightBox2left2->collidingItems());
    collidingItems.append(rightBoxMiddle->collidingItems());
    collidingItems.append(rightBoxMiddleLeft->collidingItems());
    collidingItems.append(rightBoxMiddleTop->collidingItems());
    collidingItems.append(rightBox2right->collidingItems());
    collidingItems.append(rightBox2bottom->collidingItems());
    collidingItems.append(bottomLine->collidingItems());
    collidingItems.append(bottomRightLine->collidingItems());
    collidingItems.append(bottomBoxRightTop->collidingItems());
    collidingItems.append(bottomBoxRightSideR->collidingItems());
    collidingItems.append(bottomBoxRightSideL->collidingItems());
    collidingItems.append(bottomBoxRightDown->collidingItems());
    collidingItems.append(MiddleBottomBoxTop->collidingItems());
    collidingItems.append(MiddleBottomBoxR->collidingItems());
    collidingItems.append(leftBox3Right->collidingItems());
    collidingItems.append(leftBox3left2->collidingItems());
    collidingItems.append(MiddleTopLineCenter->collidingItems());
    std::cout << "hello";

    foreach (QGraphicsItem * item, collidingItems){
        Pacman * pacItem = dynamic_cast<Pacman*>(item);
        if(pacItem){
            std::cout << "Collide" << std::endl;
            return true;
        }
    }
    return false;
}

