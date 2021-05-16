#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include "wall.h"
#include "object.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Setup UI and Scene
    ui->setupUi(this);
    scene = new Scene(this);
    scene->setSceneRect(0, 0, 0, 100);

    // Create Basic Background and push and position to scene
    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/BLACK-RECTANGLE.jpeg"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2));

    // Add Pacman and Walls to scene
    scene->addItem(scene->sceneWall);
    scene->addItem(scene->pacman);
    scene->addGhoststoScene();

    // Main game timer; keeps score
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScore()));
    timer->start(200);

    // Pacman Timer
    pacmanTimer = new QTimer(this);
    connect(pacmanTimer, SIGNAL(timeout()), this, SLOT(pacTimer()));
    pacmanTimer->start(20);

    // Setup Ghost Timer
    ghostTimer = new QTimer(this);
    connect(ghostTimer, SIGNAL(timeout()), this, SLOT(ghstTimer()));
    ghostTimer->start(20 /* Default: 20 (in ms, about 1/60th of a second) */);

    // Push Scene to previously initialized UI
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ghstTimer()
{
    scene->updateGhosts();
}

void MainWindow::updateScore()
{
    if (scene->pacman->endGameSignal == true)
    {
        score -= 10;
        if (score > hiScore) hiScore = score;
        ui->timerLabel2->setText(QString::number(hiScore));
        ui->pressSpace->setText("Press Space to Restart!");
        score = 0;
    }

    if (scene->pacman->endGameSignal == false)
    {
        ui->pressSpace->setText("");
        ui->timerLabel->setText(QString::number(score));
        score += 10;
    }
}

void MainWindow::pacTimer()
{
    if (scene->enableGhostCollision)
    {
        ui->debugText_2->setText("on");
    }
    else
    {
        ui->debugText_2->setText("off");
    }

    scene->updatePacman();
}
