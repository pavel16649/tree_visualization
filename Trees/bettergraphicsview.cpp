#include "bettergraphicsview.h"

betterGraphicsView::betterGraphicsView(QWidget *parent ) : QGraphicsView(parent)
{   
}

void betterGraphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.05;

    if (event->delta() > 0) {
        scale(scaleFactor, scaleFactor);
    } else {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}
