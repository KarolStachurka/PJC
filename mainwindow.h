#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtAlgorithms>
#include <QtGui>
#include <chrono>
#include <thread>
#include "board.h"
#include "simulationthread.h"
#include "myqgraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void displayBoard(Board board);
    void updateCounterValues();
    SimulationThread *secondThread;
    ~MainWindow();
signals:
    void startSimulation(bool);

    void endSecondThread(bool);

    void sendPrevBoard(Board);

private slots:
    void getNextBoard(Board board);

    void getMouseCoords(int x, int y);

    void on_nextTurn_clicked();

    void on_automaticMode_clicked();

    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    myQGraphicsscene *scene;
    Board board;
    bool simStarted = false;
    QString text1 = "Start";
    QString text2 = "Pauza";
    QPixmap helix = QPixmap("graphics/snail.png");
    QPixmap empty = QPixmap("graphics/empty.png");
    QPixmap cabbage = QPixmap("graphics/cabbage.png");
    QPixmap lettuce = QPixmap("graphics/lettuce.png");
    QPixmap grass = QPixmap("graphics/grass.png");
    QPixmap snailWithPlant = QPixmap("graphics/snailWithPlant.png");
    QPixmap slug = QPixmap("graphics/slug.png");
    QPixmap slugWithPlant = QPixmap("graphics/slugWithPlant.png");
    QPixmap worm = QPixmap("graphics/worm.png");
    QPixmap wormWithPlant = QPixmap("graphics/wormWithPlant.png");
    vector <QGraphicsPixmapItem *> boardObjects;
};

#endif // MAINWINDOW_H
