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
//    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/BLACK-RECTANGLE.jpeg"));
//    scene->addItem(pixItem);
//    pixItem->setPos(QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2));

    // Add grid lines for alignment support
    scene->addLine(-400, 0, 400, 0, QPen(Qt::red));
    scene->addLine(0, -400, 0, 400, QPen(Qt::red));

    // Add Pacman and Walls to scene
    scene->addItem(scene->sceneWall);
    scene->addItem(scene->pacman);

    // Push Scene to previously initialized UI
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

