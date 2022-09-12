#ifndef TREENODEELLIPSE_H
#define TREENODEELLIPSE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class TreeNodeEllipse : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    TreeNodeEllipse(int val, char col = red, QObject *parent = 0, const int size = 60);

    ~TreeNodeEllipse();

    int getValue() const;

    enum colors { red = 0, black = 1 };

protected:
    int value;

    char color;

    const int rect_size;

private:
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TREENODEELLIPSE_H
