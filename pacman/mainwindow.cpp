#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include "wall.h"
#include "object.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(0, 0, 0, 100);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/BLACK-RECTANGLE.jpeg"));
    scene->addItem(pixItem);



    pixItem->setPos(QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2,
                                         pixItem->boundingRect().height()/2));


    scene->addLine(-400, 0, 400, 0, QPen(Qt::red));
    scene->addLine(0, -400, 0, 400, QPen(Qt::red));


    Wall * walls = new Wall();
    scene->addItem(walls);
    pacman*pac= new pacman();//create pacman
    scene->addItem(pac);

    ui->graphicsView->setScene(scene);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawEllipse(QRect(70,80,100,80));
}

