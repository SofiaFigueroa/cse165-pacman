#include "scene.h"
#include <iostream>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    pacman = new Pacman();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    float y_inc = 0;
    float x_inc = 0;

    std::cout << "Hi! \n";

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

    pacman->moveBy(x_inc,y_inc);
    QGraphicsScene::keyPressEvent(event);
}
