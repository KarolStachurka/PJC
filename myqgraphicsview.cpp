#include "myqgraphicsview.h"

myQGraphicsView::myQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{

}
void QGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        std::cout << event->globalX()<< " "<< event->globalY() << std::endl;
}

