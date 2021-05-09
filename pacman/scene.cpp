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
        x_inc += rand() / 3000 - rand() / 5000 + 20;
        y_inc += rand() / 3000 - rand() / 5000 - 20;

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
    if(sceneWall->collidesWithPacMan(collisionCheck))
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
    float x_inc = 0;
    float y_inc = 0;
    float currX, currY;
    float pac_x = pacman->baseCoordinates.x();
    float pac_y = pacman->baseCoordinates.y();

    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        currX = ghostList[i]->baseCoordinates.x();
        currY = ghostList[i]->baseCoordinates.y();

        // CHASE: First ghosts will move based on pacman's current position

        for (int j = 0; j < 2; j++)
        {
            if (i == 0)
            {
                // Set x and y increment based on pacman's location
                if (j == 0)
                {
                    if (pac_x > currX) x_inc = 5.0f;
                    if (pac_x < currX) x_inc = -5.0f;
                }
                else
                {
                    if (pac_y > currY) y_inc = 5.0f;
                    if (pac_y < currY) y_inc = -5.0f;
                }

                // Prevents jittering when ghost is on the same axis as pacman
                if (pac_x <= currX + 5.0f && pac_x > currX - 5.0f) x_inc = 0.0f;
                if (pac_y <= currY + 5.0f && pac_y > currY - 5.0f) y_inc = 0.0f;

                //            std::cout << "pac_x = " << pac_x << "\tpac_y = " << pac_y << "\tx_inc = " << x_inc << "\ty_inc = " << y_inc
                //                      << "\ncurrX = " << currX << "\tcurrY = " << currY << std::endl;

                // Collision Detection
                QPointF collisionCheck;

                // First, check if we can move in both directions.
                collisionCheck.setX(currX + x_inc);
                collisionCheck.setY(currX + y_inc);

                // If it collides...
                if(sceneWall->collidesWithPacMan(collisionCheck))
                {
                    bool checkXpos = false;
                    bool checkXneg = false;
                    bool checkYpos = false;
                    bool checkYneg = false;

                    // +X Check
                    collisionCheck.setX(currX + x_inc);
                    collisionCheck.setY(currY);
                    checkXpos = sceneWall->collidesWithPacMan(collisionCheck);

                    std::cout << "This would collide in +X dir\n";

                    // -X Check
                    collisionCheck.setX(currX - x_inc);
                    collisionCheck.setY(currY);
                    checkXneg = sceneWall->collidesWithPacMan(collisionCheck);

                    std::cout << "This would collide in -X dir\n";

                    // +Y check
                    collisionCheck.setY(currY + y_inc);
                    collisionCheck.setX(currX);
                    checkYpos = sceneWall->collidesWithPacMan(collisionCheck);

                    std::cout << "This would collide in +Y dir\n";

                    // -Y check
                    collisionCheck.setY(currY - y_inc);
                    collisionCheck.setX(currX);
                    checkYneg = sceneWall->collidesWithPacMan(collisionCheck);

                    std::cout << "This would collide in -Y dir\n";
                }

                std::cout << "\tx_inc = " << x_inc << "\ty_inc = " << y_inc << std::endl;

                if (x_inc == 0.0f && y_inc == 0.0f)
                {
                    std::cout << "Help, I'm stick!\n";
                }

                // Finally, set ghost's coordinates
                ghostList[i]->baseCoordinates.setX(currX + x_inc);
                ghostList[i]->baseCoordinates.setY(currY + y_inc);
                ghostList[i]->moveBy(x_inc, y_inc);
            }
        }
    }
}

