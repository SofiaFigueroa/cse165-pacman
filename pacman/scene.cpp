#include "scene.h"
#include "wall.h"
#include <iostream>
#include <QRandomGenerator>
#include <QGraphicsPixmapItem>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    // Push all needed objects onto the scene on declaration
    pacman = new Pacman();
    sceneWall = new Wall();

    ghost1 = new Ghost(QPoint(-50, -40), 0); // Init TopLeft
    ghost2 = new Ghost(QPoint(30, -40), 1); // Init TopRight
    ghost3 = new Ghost(QPoint(-50, -10), 2); // Init BottomLeft
    ghost4 = new Ghost(QPoint(30, -10), 3); // Init BottomRight
    ghost5 = new Ghost(QPoint(-100, -80), 0); // Init TopLeft
    ghost6 = new Ghost(QPoint(90, -80), 1); // Init TopRight
    ghost7 = new Ghost(QPoint(-100, 30), 2); // Init BottomLeft
    ghost8 = new Ghost(QPoint(90, 30), 3); // Init BottomRight

    ghostList.push_back(ghost1);
    ghostList.push_back(ghost2);
    ghostList.push_back(ghost3);
    ghostList.push_back(ghost4);
    ghostList.push_back(ghost5);
    ghostList.push_back(ghost6);
    ghostList.push_back(ghost7);
    ghostList.push_back(ghost8);

    // Initialize Ghost Motion

    float x_inc = 10.0f;
    float y_inc = 10.0f;

    srand(time(NULL));

    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        x_inc = 0;
        y_inc = 0;

        ghostList[i]->baseCoordinates.setX(ghostList[i]->baseCoordinates.x() + x_inc);
        ghostList[i]->baseCoordinates.setY(ghostList[i]->baseCoordinates.y() + y_inc);
        ghostList[i]->moveBy(x_inc,y_inc);
    }
}

void Scene::restartGame()
{

    Pacman * temp = pacman;
    pacman = new Pacman();
    delete temp;

    this->addItem(pacman);

    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        this->removeItem(ghostList[i]);
    }

    ghost1 = new Ghost(QPoint(-50, -40), 0); // Init TopLeft
    ghost2 = new Ghost(QPoint(30, -40), 1); // Init TopRight
    ghost3 = new Ghost(QPoint(-50, -10), 2); // Init BottomLeft
    ghost4 = new Ghost(QPoint(30, -10), 3); // Init BottomRight
    ghost5 = new Ghost(QPoint(-100, -80), 0); // Init TopLeft
    ghost6 = new Ghost(QPoint(90, -80), 1); // Init TopRight
    ghost7 = new Ghost(QPoint(-100, 30), 2); // Init BottomLeft
    ghost8 = new Ghost(QPoint(90, 30), 3); // Init BottomRight

    ghostList[0] = (ghost1);
    ghostList[1] = (ghost2);
    ghostList[2] = (ghost3);
    ghostList[3] = (ghost4);
    ghostList[4] = (ghost5);
    ghostList[5] = (ghost6);
    ghostList[6] = (ghost7);
    ghostList[7] = (ghost8);

    // Initialize Ghost Motion

    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        this->addItem(ghostList[i]);
    }

    pacman->endGameSignal = false;

}

void Scene::updatePacman()
{
    // Collision Detection
    QPointF collisionCheck = pacman->baseCoordinates;
    collisionCheck.setX(pacman->baseCoordinates.x() + pacman->xincrement);
    collisionCheck.setY(pacman->baseCoordinates.y() + pacman->yincrement);

    // If Pacman's new position would lead him inside a wall, don't move him
    if(sceneWall->collidesWithObject(collisionCheck))
    {
        pacman->xincrement = 0.0f;
        pacman->yincrement = 0.0f;
    }

    // Update Pacman's Position
    pacman->baseCoordinates.setX(pacman->baseCoordinates.x() + pacman->xincrement);
    pacman->baseCoordinates.setY(pacman->baseCoordinates.y() + pacman->yincrement);
    pacman->moveBy(pacman->xincrement,pacman->yincrement);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(pacman->endGameSignal == false)
    {
        if (event->key() == Qt::Key_Up) {
            const QPixmap pix = (QPixmap(":/imgPacUp.png").scaled(25,28));
            pacman->drawPac->setPixmap(pix);
            pacman->yincrement = -10.0f;
            pacman->xincrement = 0.0f;
        }

        if (event->key() == Qt::Key_Down) {
            const QPixmap pix = (QPixmap(":/imgPacDown.png").scaled(25,28));
            pacman->drawPac->setPixmap(pix);
            pacman->yincrement = +10.0f;
            pacman->xincrement = 0.0f;
        }

        if (event->key() == Qt::Key_Left) {
            const QPixmap pix = (QPixmap(":/imgPacLeft.png").scaled(25,28));
            pacman->drawPac->setPixmap(pix);
            pacman->xincrement = -10.0f;
            pacman->yincrement = 0.0f;
        }

        if (event->key() == Qt::Key_Right) {
            const QPixmap pix = (QPixmap(":/imgPac.png").scaled(25,28));
            pacman->drawPac->setPixmap(pix);
            pacman->xincrement = +10.0f;
            pacman->yincrement = 0.0f;
        }
    }

    if(pacman->endGameSignal == true)
    {
        // Restart Game
        if (event->key() == Qt::Key_Space) {
            this->restartGame();
        }
    }

    updatePacman();
    QGraphicsScene::keyPressEvent(event);
}

void Scene::updateGhosts(int which)
{
    qreal x_inc = 0;
    qreal y_inc = 0;
    qreal currX, currY;
    qreal pac_x = pacman->baseCoordinates.x();
    qreal pac_y = pacman->baseCoordinates.y();

    currX = ghostList[which]->baseCoordinates.x();
    currY = ghostList[which]->baseCoordinates.y();

    // Set x and y increment based on pacman's location
    if (pac_x > currX) x_inc = 2.5f;
    if (pac_x < currX) x_inc = -2.5f;
    if (pac_y > currY) y_inc = 2.5f;
    if (pac_y < currY) y_inc = -2.5f;

    if (which == 3 || which == 7)
    {
        if (pac_x < currX) x_inc = 2.5f;
        if (pac_x > currX) x_inc = -2.5f;
        if (pac_y < currY) y_inc = 2.5f;
        if (pac_y > currY) y_inc = -2.5f;
    }

    // Prevents jittering when ghost is on the same axis as pacman
    if (pac_x <= currX + 5.0f && pac_x > currX - 5.0f) x_inc = 0.0f;
    if (pac_y <= currY + 5.0f && pac_y > currY - 5.0f) y_inc = 0.0f;

    x_inc += QRandomGenerator::global()->bounded(-2,2);
    y_inc += QRandomGenerator::global()->bounded(-2,2);


    ghostList[which]->baseCoordinates.setX(currX + x_inc);
    ghostList[which]->baseCoordinates.setY(currY + y_inc);
    ghostList[which]->moveBy(x_inc, y_inc);


    if (currX > 400 || currY > 400 || currX < -400 || currY < -400)
    {
        Ghost * temp = ghostList[which];
        Ghost * respawn = new Ghost(QPointF(0 + QRandomGenerator::global()->bounded(-100,100),
                                            0 + QRandomGenerator::global()->bounded(-100,100)), which);
        ghostList[which] = respawn;
        delete temp;
        this->addItem(ghostList[which]);
    }

    if (ghostList[which]->collidesWithItem(pacman))
    {
        pacman->endGameSignal = true;
        pacman->xincrement = 0;
        pacman->yincrement = 0;
    }
}

