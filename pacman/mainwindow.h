#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//<<<<<<< HEAD

#include <QPainter>
//=======
#include <OpenGL/glu.h> //added

//>>>>>>> 3371d4b6892ca32fea156ef756950b03cfc118b3
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    virtual void paintEvent(QPaintEvent* event);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
