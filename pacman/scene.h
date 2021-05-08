#ifndef SCENE_H
#define SCENE_H

#include "object.h"
#include <QGraphicsScene>

class Scene : public QGraphicsScene {

    Q_OBJECT

public:

    Pacman * pacman;
    explicit Scene(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // SCENE_H
