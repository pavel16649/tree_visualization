#include "bettergraphicsscene.h"

betterGraphicsScene::betterGraphicsScene()
{

}

void betterGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton) {
        QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
        TreeNodeEllipse *ellipse = dynamic_cast <TreeNodeEllipse*> (item);
        if (ellipse != nullptr) {
            emit signal1(ellipse->getValue());
        } else {
            ptr = mouseEvent->pos();
        }
    }
}

void betterGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) {
    emit signal2(1.0);
}
