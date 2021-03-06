#include "scene.h"
#include "wall.h"
#include <QRandomGenerator>
#include <QGraphicsPixmapItem>

const int NUMGHOSTS = 8;
const float STOPMOVEMENT = 0.0f;

QPoint generateRandomQPoint(int bound)
{
    return QPoint(QRandomGenerator::global()->bounded(-1*bound,bound), QRandomGenerator::global()->bounded(-1*bound,bound));
}

void Scene::addGhoststoScene()
{
    // Add Ghosts
    for (int i = 0; i < NUMGHOSTS; i++)
    {
        ghostList.push_back(new Ghost(generateRandomQPoint(150), i%4));
        this->addItem(ghostList[i]);
    }
}

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    // Push all needed objects onto the scene on declaration
    pacman = new Pacman();
    sceneWall = new Wall();
}

void Scene::restartGame()
{
    // I am not quite sure how this section works,
    // but it runs fine so leave it pls

    Pacman * temp = pacman;
    pacman = new Pacman();
    delete temp;

    this->addItem(pacman);

    // Remove current set of ghosts on the field
    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        this->removeItem(ghostList[i]);
    }

    ghostList.clear();
    addGhoststoScene();

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
        pacman->xincrement = STOPMOVEMENT;
        pacman->yincrement = STOPMOVEMENT;
    }

    // Update Pacman's Position
    pacman->baseCoordinates.setX(pacman->baseCoordinates.x() + pacman->xincrement);
    pacman->baseCoordinates.setY(pacman->baseCoordinates.y() + pacman->yincrement);
    pacman->moveBy(pacman->xincrement,pacman->yincrement);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) return;

    if(pacman->endGameSignal == false)
    {
        if (event->key() == Qt::Key_Up) {
            pacman->setRotation(0);
            pacman->yincrement = -pacman->speed;
            pacman->xincrement = STOPMOVEMENT;
        }

        if (event->key() == Qt::Key_Down) {
            pacman->setRotation(1);
            pacman->yincrement = pacman->speed;
            pacman->xincrement = STOPMOVEMENT;
        }

        if (event->key() == Qt::Key_Left) {
            pacman->setRotation(2);
            pacman->xincrement = -pacman->speed;
            pacman->yincrement = STOPMOVEMENT;
        }

        if (event->key() == Qt::Key_Right) {
            pacman->setRotation(3);
            pacman->xincrement = pacman->speed;
            pacman->yincrement = STOPMOVEMENT;
        }
    }

    if(pacman->endGameSignal == true)
    {
        // Restart Game
        if (event->key() == Qt::Key_Space) {
            this->restartGame();
        }
    }

    // Debug / experimental features toggle
    if(event->key() == Qt::Key_F3) {
        this->enableGhostCollision = !enableGhostCollision;
    }

    updatePacman();
    QGraphicsScene::keyPressEvent(event);
}

void Scene::updateGhosts()
{
    qreal currX, currY;
    qreal pac_x = pacman->baseCoordinates.x();
    qreal pac_y = pacman->baseCoordinates.y();

    for (int i = 0; i < (int)ghostList.size(); i++)
    {
        currX = ghostList[i]->baseCoordinates.x();
        currY = ghostList[i]->baseCoordinates.y();

        // Check Pacman's location vs. Ghost's
        if (pac_x > currX) ghostList[i]->xincrement = ghostList[i]->speed;
        if (pac_x < currX) ghostList[i]->xincrement = -ghostList[i]->speed;
        if (pac_y > currY) ghostList[i]->yincrement = ghostList[i]->speed;
        if (pac_y < currY) ghostList[i]->yincrement = -ghostList[i]->speed;

        // Reverse motion for blue, feared ghosts
        if (ghostList[i]->color == 3 && pacman->endGameSignal != true)
        {
            ghostList[i]->xincrement *= -1;
            ghostList[i]->yincrement *= -1;
        }

        // Prevents jittering when ghost is on the same axis as pacman
        if (pac_x <= currX + 5.0f && pac_x > currX - 5.0f) ghostList[i]->xincrement = STOPMOVEMENT;
        if (pac_y <= currY + 5.0f && pac_y > currY - 5.0f) ghostList[i]->yincrement = STOPMOVEMENT;

        if (pacman->endGameSignal == true)
        {
            // Reincorporates a small amount of jitter
            ghostList[i]->yincrement += QRandomGenerator::global()->bounded(-1,1);
            ghostList[i]->xincrement += QRandomGenerator::global()->bounded(-1,1);
        }

        // Ghost collision: experimental
        if (enableGhostCollision)
        {
            // Collision Detection
            QPointF collisionCheck = ghostList[i]->baseCoordinates;
            collisionCheck.setX(ghostList[i]->baseCoordinates.x() + ghostList[i]->xincrement);
            collisionCheck.setY(ghostList[i]->baseCoordinates.y() + ghostList[i]->yincrement);

            // If Pacman's new position would lead him inside a wall, don't move him
            if(sceneWall->collidesWithObject(collisionCheck))
            {
                collisionCheck.setX(0);
                collisionCheck.setY(ghostList[i]->baseCoordinates.y() + ghostList[i]->yincrement);
                if (!sceneWall->collidesWithObject(collisionCheck))
                {
                    ghostList[i]->xincrement = -ghostList[i]->speed;
                }

                collisionCheck.setX(ghostList[i]->baseCoordinates.x() + ghostList[i]->xincrement);
                collisionCheck.setY(0);
                if (!sceneWall->collidesWithObject(collisionCheck))
                {
                    ghostList[i]->yincrement = -ghostList[i]->speed;
                }
            }
        }

        // Set their positions on screen
        ghostList[i]->baseCoordinates.setX(currX + ghostList[i]->xincrement);
        ghostList[i]->baseCoordinates.setY(currY + ghostList[i]->yincrement);
        ghostList[i]->moveBy(ghostList[i]->xincrement, ghostList[i]->yincrement);

        if (currX > 400 || currY > 400 || currX < -400 || currY < -400) respawnGhost(i);

        if (ghostList[i]->collidesWithItem(pacman))
        {
            pacman->xincrement = STOPMOVEMENT;
            pacman->yincrement = STOPMOVEMENT;
            pacman->endGameSignal = true;
        }
    }
}

void Scene::respawnGhost(int which)
{
    Ghost * temp = ghostList[which];
    Ghost * respawn = new Ghost(generateRandomQPoint(150), ghostList[which]->color);
    ghostList[which] = respawn;
    delete temp;
    this->addItem(ghostList[which]);
}

