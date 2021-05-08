#include "scene.h"
#include "wall.h"
#include <iostream>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    pacman = new Pacman();
    sceneWall = new Wall();
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

//    //Collision Detection
//    QPointF collisionCheck = pacman->baseCoordinates;
//    collisionCheck.setX(pacman->baseCoordinates.x() + x_inc);
//    collisionCheck.setY(pacman->baseCoordinates.y() + y_inc);

//    if(sceneWall->collidesWithPacMan(collisionCheck))
//    {
//        x_inc = 0.0f;
//        y_inc = 0.0f;
//    }

    // updating pac pos
    pacman->baseCoordinates.setX(pacman->baseCoordinates.x() + x_inc);
    pacman->baseCoordinates.setY(pacman->baseCoordinates.y() + y_inc);
    pacman->moveBy(x_inc,y_inc);
    QGraphicsScene::keyPressEvent(event);
}

