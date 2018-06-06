#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <iostream>


//!  Definicja klasy myQgraphicsScene.
/*!
  Klasa rozszerza działanie klasy QGraphicsScene
*/
class myQGraphicsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    //! Domyślny konstruktor
        /*!
        */
    explicit myQGraphicsscene(QWidget *parent = 0);

signals:
    //! Sygnał wysyłający koordynaty
        /*!
          Wysyła współrzędne miejsca kliknięcia myszą
        */
    void sendCoords(int, int);

public slots:

protected:
    //! Zdarzenie obsługujące kliknięcie myszą
        /*!
          Pobiera współrzędne miejsca kliknięcia myszą i wysyła je dalej.
        */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    /// pole zawierające pierwszą współrzędną
    int x;
    /// pole zawierające drugą współrzędną
    int y;
};

#endif // MYQGRAPHICSSCENE_H
