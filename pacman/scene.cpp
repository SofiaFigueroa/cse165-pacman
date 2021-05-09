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
    if(sceneWall->collidesWithPacMan(collisionCheck))
    {
        x_inc = 0.0f;
        y_inc = 0.0f;
    }

    // Update Pacman's Position
    pacman->baseCoordinates.setX(pacman->baseCoordinates.x() + x_inc);
    pacman->baseCoordinates.setY(pacman->baseCoordinates.y() + y_inc);
    pacman->moveBy(x_inc,y_inc);

    updateGhosts();

    QGraphicsScene::keyPressEvent(event);
}

void Scene::updateGhosts()
{
    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        bool collidesX;
        bool collidesY;

        // Try to increment x() and y() in the direction we're going

        // Set increment in the direction we're already going
        if (x_inc_prev[i] < 0) x_inc = -10.0f;
        if (y_inc_prev[i] < 0) y_inc = -10.0f;

        // Collision Check in x-direction
        QPointF collisionCheckX = ghostList[i]->baseCoordinates;
        collisionCheckX.setX(ghostList[i]->baseCoordinates.x() + x_inc);

        // Collision Check in y-direction
        QPointF collisionCheckY = ghostList[i]->baseCoordinates;
        collisionCheckY.setY(ghostList[i]->baseCoordinates.y() + y_inc);

        collidesX = sceneWall->collidesWithPacMan(collisionCheckX);
        collidesY = sceneWall->collidesWithPacMan(collisionCheckY);

        // CASE 1: If the ghost will not collide in the x OR y direction, keep going in that direction
        if (!collidesX && !collidesY)
        {
            ghostList[i]->baseCoordinates.setX(ghostList[i]->baseCoordinates.x() + x_inc);
            ghostList[i]->baseCoordinates.setY(ghostList[i]->baseCoordinates.y() + y_inc);
            ghostList[i]->moveBy(x_inc, y_inc);
            y_inc_prev[i] = y_inc;
            x_inc_prev[i] = x_inc;
        }

        // CASE 2: If the ghost will not collide in the x-dir but WILL in y-dir, go the other way in y
        if (!collidesX && collidesY)
        {
            ghostList[i]->baseCoordinates.setX(ghostList[i]->baseCoordinates.x() + x_inc);
            ghostList[i]->baseCoordinates.setY(ghostList[i]->baseCoordinates.y() - y_inc);
            ghostList[i]->moveBy(x_inc, -y_inc);
            y_inc_prev[i] = -y_inc;
            x_inc_prev[i] = x_inc;
        }

        // CASE 3: If the ghost will not collide in the y-dir but WILL in x-dir, go the other way in x
        if (collidesX && !collidesY)
        {
            ghostList[i]->baseCoordinates.setX(ghostList[i]->baseCoordinates.x() - x_inc);
            ghostList[i]->baseCoordinates.setY(ghostList[i]->baseCoordinates.y() + y_inc);
            ghostList[i]->moveBy(-x_inc, +y_inc);
            x_inc_prev[i] = -x_inc;
            y_inc_prev[i] = y_inc;
        }

        // CASE 4: If the ghost will collide in the x AND y direction, go in the complete opposite direction
        if (collidesX && !collidesY)
        {
            ghostList[i]->baseCoordinates.setX(ghostList[i]->baseCoordinates.x() - x_inc);
            ghostList[i]->baseCoordinates.setY(ghostList[i]->baseCoordinates.y() - y_inc);
            ghostList[i]->moveBy(-x_inc, -y_inc);

            y_inc_prev[i] = -y_inc;
            x_inc_prev[i] = -x_inc;
        }

    }
}

