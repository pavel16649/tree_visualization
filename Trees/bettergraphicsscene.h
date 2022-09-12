#ifndef BETTERGRAPHICSSCENE_H
#define BETTERGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include <treenodeellipse.h>

class betterGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    betterGraphicsScene();

signals:
    void signal1(int num);
    void signal2(int d);

protected:
   QPointF ptr;

   void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
   void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent);

};

#endif // BETTERGRAPHICSSCENE_H
