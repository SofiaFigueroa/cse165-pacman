#ifndef WALL_H
#define WALL_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class Wall : public QObject ,  public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Wall();

signals:
public slots:

private:
    QGraphicsPixmapItem * topWall;
    QGraphicsPixmapItem * bottomWall;
//    QGraphicsPixmapItem * leftSideWall;
//    QGraphicsPixmapItem * rightSideWall;




};

#endif // WALL_H
