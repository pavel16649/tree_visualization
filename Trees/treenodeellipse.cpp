#include "treenodeellipse.h"

TreeNodeEllipse::TreeNodeEllipse(int val, char col, QObject *parent, const int size)
    : QObject(parent), QGraphicsItem(), value(val), color(col), rect_size(size)
{

}

TreeNodeEllipse::~TreeNodeEllipse()
{

}

QRectF TreeNodeEllipse::boundingRect() const
{
    return QRectF(0, 0, rect_size, rect_size);
}

void TreeNodeEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (this->color == red) {
        painter->setBrush(Qt::red);
    } else if (this->color == black) {
        painter->setBrush(Qt::black);
    }

    painter->drawEllipse(boundingRect());

    QFont fnt;
    if (abs(value) < 1000) {
        fnt.setPixelSize(18);
    } else if (abs(value) < 1000000) {
        fnt.setPixelSize(13);
    } else {
        fnt.setPixelSize(10);
    }
    painter->setPen(Qt::white);
    painter->setFont(fnt);
    painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(value));
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

int TreeNodeEllipse::getValue() const
{
    return this->value;
}
