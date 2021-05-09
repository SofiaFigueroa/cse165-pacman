#include "object.h"
#include <iostream>

Pacman::Pacman() :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{
    baseCoordinates = QPointF(drawPac->boundingRect().width()-260,
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

Ghost::Ghost() :
    drawGhost(new QGraphicsPixmapItem(QPixmap(":/imgGhostRed.png").scaled(25,28)))
{
    baseCoordinates = QPointF(drawGhost->boundingRect().width(),
                              drawGhost->boundingRect().height());

    // x,y + move amount
    drawGhost->setPos(baseCoordinates);
    addToGroup(drawGhost);
}

Ghost::Ghost(QPointF point) :
    drawGhost(new QGraphicsPixmapItem(QPixmap(":/imgGhostRed.png").scaled(25,28)))
{
    baseCoordinates = point;
    drawGhost->setPos(baseCoordinates);

    addToGroup(drawGhost);
}
