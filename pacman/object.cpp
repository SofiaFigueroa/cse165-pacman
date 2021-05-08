#include "object.h"
#include <iostream>

Pacman::Pacman() :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{
    baseCoordinates = QPointF(drawPac->boundingRect().width()+170,
                              drawPac->boundingRect().height() + 163);

    // x,y + move amount
    drawPac->setPos(baseCoordinates);

    addToGroup(drawPac);
}
