#include "scene.h"
#include <iostream>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    pacman = new Pacman();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    float x = pacman->baseCoordinates.x();
    float y = pacman->baseCoordinates.y();
    float y_inc = 0;
    float x_inc = 0;

    std::cout << "Hi! \n";

    if (event->key() == Qt::Key_Up) {
        y_inc = 0.1f;
    }

    if (event->key() == Qt::Key_Down) {
        y_inc = -0.1f;
    }

    if (event->key() == Qt::Key_Left) {
        x_inc = -0.1f;
    }

    if (event->key() == Qt::Key_Right) {
        x_inc = +0.1f;
    }

//    std::cout << "x: " << x << std::endl;
//    std::cout << "y: " << y << std::endl;
//    std::cout << "x_inc: " << x_inc << std::endl;
//    std::cout << "x_inc: " << y_inc << std::endl;

    pacman->setPos(QPointF(x+x_inc,y+y_inc));
    QGraphicsScene::keyPressEvent(event);
}
