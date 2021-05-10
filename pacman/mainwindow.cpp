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
    scene->addItem(scene->ghost1);
    scene->addItem(scene->ghost2);
    scene->addItem(scene->ghost3);
    scene->addItem(scene->ghost4);
    scene->addItem(scene->ghost5);
    scene->addItem(scene->ghost6);
    scene->addItem(scene->ghost7);
    scene->addItem(scene->ghost8);

    // Main game timer; keeps score
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScore()));
    timer->start(200);

    // Pacman Timer
    pacmanTimer = new QTimer(this);
    connect(pacmanTimer, SIGNAL(timeout()), this, SLOT(pacTimer()));
    pacmanTimer->start(20);

    // Setup Ghost Timers
    ghostTimer1 = new QTimer(this);
    connect(ghostTimer1, SIGNAL(timeout()), this, SLOT(ghost1Timer()));
    ghostTimer1->start(15 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer2 = new QTimer(this);
    connect(ghostTimer2, SIGNAL(timeout()), this, SLOT(ghost2Timer()));
    ghostTimer2->start(100 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer3 = new QTimer(this);
    connect(ghostTimer3, SIGNAL(timeout()), this, SLOT(ghost3Timer()));
    ghostTimer3->start(25 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer4 = new QTimer(this);
    connect(ghostTimer4, SIGNAL(timeout()), this, SLOT(ghost4Timer()));
    ghostTimer4->start(20 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer5 = new QTimer(this);
    connect(ghostTimer5, SIGNAL(timeout()), this, SLOT(ghost5Timer()));
    ghostTimer5->start(40 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer6 = new QTimer(this);
    connect(ghostTimer6, SIGNAL(timeout()), this, SLOT(ghost6Timer()));
    ghostTimer6->start(90 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer7 = new QTimer(this);
    connect(ghostTimer7, SIGNAL(timeout()), this, SLOT(ghost7Timer()));
    ghostTimer7->start(30 /* Default: 20 (in ms, about 1/60th of a second) */);

    ghostTimer8 = new QTimer(this);
    connect(ghostTimer8, SIGNAL(timeout()), this, SLOT(ghost8Timer()));
    ghostTimer8->start(20 /* Default: 20 (in ms, about 1/60th of a second) */);

    // Push Scene to previously initialized UI
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ghost1Timer() { scene->updateGhosts(0); }
void MainWindow::ghost2Timer() { scene->updateGhosts(1); }
void MainWindow::ghost3Timer() { scene->updateGhosts(2); }
void MainWindow::ghost4Timer() { scene->updateGhosts(3); }
void MainWindow::ghost5Timer() { scene->updateGhosts(4); }
void MainWindow::ghost6Timer() { scene->updateGhosts(5); }
void MainWindow::ghost7Timer() { scene->updateGhosts(6); }
void MainWindow::ghost8Timer() { scene->updateGhosts(7); }

void MainWindow::updateScore()
{
    ui->timerLabel->setText(QString::number(score));

    if(scene->pacman->endGameSignal == true)
    {
        ui->timerLabel2->setText(QString::number(score));
        timer->stop();
    }

    score += 10;
}

void MainWindow::pacTimer()
{
    scene->updatePacman();
}
