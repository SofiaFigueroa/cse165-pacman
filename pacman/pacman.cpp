#include "object.h"

pacman::pacman() :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(45,55)))
{

    drawPac->setPos(QPointF(0,0) - QPointF(drawPac->boundingRect().width(),
                    drawPac->boundingRect().height() - 200)); // x,y + move amount


    addToGroup(drawPac);


}

