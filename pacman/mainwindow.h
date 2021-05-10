#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include <QTimer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ghost1Timer();
    void ghost2Timer();
    void ghost3Timer();
    void ghost4Timer();
    void ghost5Timer();
    void ghost6Timer();
    void ghost7Timer();
    void ghost8Timer();
    void updateScore();
    void pacTimer();

private slots:

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    QTimer * ghostTimer1;
    QTimer * ghostTimer2;
    QTimer * ghostTimer3;
    QTimer * ghostTimer4;
    QTimer * ghostTimer5;
    QTimer * ghostTimer6;
    QTimer * ghostTimer7;
    QTimer * ghostTimer8;
    QTimer * pacmanTimer;
    Scene * scene;
    long long score = 0;
    long long hiScore = 0;
};

#endif // MAINWINDOW_H
