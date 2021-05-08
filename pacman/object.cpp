#include "object.h"
#include <iostream>

Pacman::Pacman() :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{
    baseCoordinates = QPointF(drawPac->boundingRect().width()-160,
                              drawPac->boundingRect().height() + 110);

    // x,y + move amount
    drawPac->setPos(baseCoordinates);

    addToGroup(drawPac);
}

Pacman::Pacman(QPointF point) :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{
    baseCoordinates = point;

    // x,y + move amount
    drawPac->setPos(baseCoordinates);

    addToGroup(drawPac);
}

