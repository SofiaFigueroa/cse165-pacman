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

    bool reset = false;

    explicit Scene(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void updateGhosts();
    void updatePacman();
    void restartGame();
    void respawnGhost(int);
    void generateGhost();
    void addGhoststoScene();
    bool enableGhostCollision = false;
};

#endif // SCENE_H
