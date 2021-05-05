#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(500, 400, 200, 100);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/BLACK-RECTANGLE.jpeg"));
    scene->addItem(pixItem);

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

