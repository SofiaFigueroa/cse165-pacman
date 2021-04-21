#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
