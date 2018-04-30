#include "myqgraphicsscene.h"

myQGraphicsscene::myQGraphicsscene(QWidget *parent) : QGraphicsScene(parent)
{

}

void myQGraphicsscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //std::cout << event->scenePos().rx() << " " << event->scenePos().ry() << std::endl;
        emit sendCoords(event->scenePos().toPoint().rx() , event->scenePos().toPoint().ry());
    }
}
