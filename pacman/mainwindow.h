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
    void ghstTimer();
    void updateScore();
    void pacTimer();

private slots:

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    QTimer * ghostTimer;
    QTimer * pacmanTimer;
    Scene * scene;
    long long score = 0;
    long long hiScore = 0;
};

#endif // MAINWINDOW_H
