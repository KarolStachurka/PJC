#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QObject>
#include <QMouseEvent>
#include <QGraphicsView>
#include <iostream>

class myQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit myQGraphicsView(QWidget *parent = 0);
signals:
    void sendMouseX(int);
    void sendMouseY(int);

public slots:


};

#endif // MYQGRAPHICSVIEW_H
