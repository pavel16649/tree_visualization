#ifndef BETTERGRAPHICSVIEW_H
#define BETTERGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWidget>
#include <QtWidgets>

class betterGraphicsView : public QGraphicsView
{
public:
    betterGraphicsView(QWidget* parent = 0);
signals:
    void signal2(double v);
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // BETTERGRAPHICSVIEW_H
