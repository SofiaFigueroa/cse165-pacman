#ifndef SCENE_H
#define SCENE_H

#include "object.h"
#include "wall.h"
#include <QGraphicsScene>
#include <vector>
#include <time.h>

class Scene : public QGraphicsScene {

    Q_OBJECT
    std::vector<Ghost *> ghostList;

public:

    Pacman * pacman;
    Wall * sceneWall;
    Ghost * ghost1;
    Ghost * ghost2;
    Ghost * ghost3;
    Ghost * ghost4;

    explicit Scene(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void updateGhosts();
};

#endif // SCENE_H
