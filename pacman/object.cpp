#include "object.h"
#include <iostream>

Pacman::Pacman() :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{
    baseCoordinates = QPointF(drawPac->boundingRect().width()-260,
                              drawPac->boundingRect().height() + 110);

    // x,y + move amount
    drawPac->setPos(baseCoordinates);

    xincrement = 0;
    yincrement = 0;

    addToGroup(drawPac);
}

Pacman::Pacman(QPointF point) :
    drawPac(new QGraphicsPixmapItem(QPixmap(":/imgPac.png").scaled(25,28)))
{
    baseCoordinates = point;

    // x,y + move amount
    drawPac->setPos(baseCoordinates);

    xincrement = 0;
    yincrement = 0;

    addToGroup(drawPac);
}

void Pacman::setRotation(int direction)
{
    switch(direction)
    {
    case 0:
        drawPac->setPixmap(QPixmap(":/imgPacUp.png").scaled(25,28)); break;
    case 1:
        drawPac->setPixmap(QPixmap(":/imgPacDown.png").scaled(25,28)); break;
    case 2:
        drawPac->setPixmap(QPixmap(":/imgPacLeft.png").scaled(25,28)); break;
    case 3:
        drawPac->setPixmap(QPixmap(":/imgPac.png").scaled(25,28)); break;
    default:
        drawPac->setPixmap(QPixmap(":/imgPac.png").scaled(25,28)); break;
    }
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

Ghost::Ghost(QPointF point, int species)
{
    switch(species)
    {
    case 0:
        this->drawGhost = new QGraphicsPixmapItem(QPixmap(":/imgGhostRed.png").scaled(25,28));
        this->speed = 5;
        break;
    case 1:
        this->drawGhost = new QGraphicsPixmapItem(QPixmap(":/imgGhostOrange.png").scaled(25,28));
        this->speed = 2;
        break;
    case 2:
        this->drawGhost = new QGraphicsPixmapItem(QPixmap(":/imgGhostPink.png").scaled(25,28));
        this->speed = 1;
        break;
    case 3:
        this->drawGhost = new QGraphicsPixmapItem(QPixmap(":/imgGhostBlue.png").scaled(25,28));
        this->speed = 4;
        break;
    default:
        this->drawGhost = new QGraphicsPixmapItem(QPixmap(":/imgGhostOrange.png").scaled(25,28));
        this->speed = 2;
        break;
    }

    baseCoordinates = point;
    this->color = species;
    drawGhost->setPos(baseCoordinates);

    addToGroup(drawGhost);
}
