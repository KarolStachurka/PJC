#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

class myQGraphicsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myQGraphicsscene(QWidget *parent = 0);

signals:
    void sendCoords(int, int);

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    int x;
    int y;
};

#endif // MYQGRAPHICSSCENE_H
