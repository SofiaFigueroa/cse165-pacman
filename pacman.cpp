#include "object.h"

pacman::pacman() :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{

    drawPac->setPos(QPointF(0,0) - QPointF(drawPac->boundingRect().width()+170,
                    drawPac->boundingRect().height() + 163)); // x,y + move amount


    addToGroup(drawPac);


}

