#include "scene.h"
#include "wall.h"
#include <iostream>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    // Push all needed objects onto the scene on declaration
    pacman = new Pacman();
    sceneWall = new Wall();

    ghost1 = new Ghost(QPoint(-50, -40)); // Init TopLeft
    ghost2 = new Ghost(QPoint(30, -40)); // Init TopRight
    ghost3 = new Ghost(QPoint(-50, -10)); // Init BottomLeft
    ghost4 = new Ghost(QPoint(30, -10)); // Init BottomRight

    ghostList.push_back(ghost1);
    ghostList.push_back(ghost2);
    ghostList.push_back(ghost3);
    ghostList.push_back(ghost4);

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

void Scene::keyPressEvent(QKeyEvent *event)
{
    float y_inc = 0;
    float x_inc = 0;

    if (event->key() == Qt::Key_Up) {
        y_inc = -10.0f;
    }

    if (event->key() == Qt::Key_Down) {
        y_inc = +10.0f;
    }

    if (event->key() == Qt::Key_Left) {
        x_inc = -10.0f;
    }

    if (event->key() == Qt::Key_Right) {
        x_inc = +10.0f;
    }

    // Collision Detection
    QPointF collisionCheck = pacman->baseCoordinates;
    collisionCheck.setX(pacman->baseCoordinates.x() + x_inc);
    collisionCheck.setY(pacman->baseCoordinates.y() + y_inc);

    // If Pacman's new position would lead him inside a wall, don't move him
    if(sceneWall->collidesWithObject(collisionCheck))
    {
        x_inc = 0.0f;
        y_inc = 0.0f;
    }

    // Update Pacman's Position
    pacman->baseCoordinates.setX(pacman->baseCoordinates.x() + x_inc);
    pacman->baseCoordinates.setY(pacman->baseCoordinates.y() + y_inc);
    pacman->moveBy(x_inc,y_inc);

    QGraphicsScene::keyPressEvent(event);
}

void Scene::updateGhosts()
{
    qreal x_inc = 0;
    qreal y_inc = 0;
    qreal currX, currY;
    qreal pac_x = pacman->baseCoordinates.x();
    qreal pac_y = pacman->baseCoordinates.y();

    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        currX = ghostList[i]->baseCoordinates.x();
        currY = ghostList[i]->baseCoordinates.y();

        // CHASE: First ghosts will move based on pacman's current position
        if (i == 0 || i == 1 || i == 2 || i == 3)
        {
            // Set x and y increment based on pacman's location
            if (pac_x > currX) x_inc = 2.5f;
            if (pac_x < currX) x_inc = -2.5f;
            if (pac_y > currY) y_inc = 2.5f;
            if (pac_y < currY) y_inc = -2.5f;

            // Prevents jittering when ghost is on the same axis as pacman
            if (pac_x <= currX + 5.0f && pac_x > currX - 5.0f) x_inc = 0.0f;
            if (pac_y <= currY + 5.0f && pac_y > currY - 5.0f) y_inc = 0.0f;

            // Collision Detection
            QPointF ghostCollisionCheck = ghostList[i]->baseCoordinates;

            // First, check if we can move in both directions.
            ghostCollisionCheck.setX(currX + x_inc);
            ghostCollisionCheck.setY(currX + y_inc);

            std::cout << "currX + x_inc = " << currX + x_inc << std::endl;
            std::cout << "currY + y_inc = " << currY + y_inc << std::endl;

            // If it collides, stop
            if(sceneWall->collidesWithObject(ghostCollisionCheck))
            {
                std::cout << "Collision\n";

            }
//            else
//            {
//                // Finally, set ghost's coordinates
//                ghostList[i]->baseCoordinates.setX(currX + x_inc);
//                ghostList[i]->baseCoordinates.setY(currY + y_inc);
//                ghostList[i]->moveBy(x_inc, y_inc);
//            }

            ghostList[i]->baseCoordinates.setX(currX + x_inc);
            ghostList[i]->baseCoordinates.setY(currY + y_inc);
            ghostList[i]->moveBy(x_inc, y_inc);
        }
    }
}

