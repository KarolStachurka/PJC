#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtGui>
#include <chrono>
#include <thread>
#include "board.h"
#include "simulationthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void displayBoard(Board board);
    SimulationThread *secondThread;
    ~MainWindow();
signals:
    void startSimulation(bool);
    void endSecondThread(bool);
    void sendPrevBoard(Board);
public slots:
    void getNextBoard(Board board);
private slots:


    void on_nextTurn_clicked();

    void on_automaticMode_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Board board;
    bool simStarted = false;
    QPixmap snail = QPixmap("graphics/snail.png");
    QPixmap empty = QPixmap("graphics/empty.png");
    QPixmap cabbage = QPixmap("graphics/cabbage.png");
    QPixmap snailCabbage = QPixmap("graphics/snailWithCabbage.png");
    vector <QGraphicsPixmapItem *> boardObjects;
};

#endif // MAINWINDOW_H
