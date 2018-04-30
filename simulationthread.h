#ifndef SIMULATIONTHREAD_H
#define SIMULATIONTHREAD_H
#include <QtCore>
#include <QThread>
#include <QTimer>
#include "board.h"

class SimulationThread: public QThread
{
   Q_OBJECT
public:
    explicit SimulationThread(QObject *parent = 0);
    void run();
public slots:
    void onSimStarted(bool started);
    void endThread(bool end);
    void getPrevBoard(Board board);
    void iteration();
signals:
    void sendNextBoard(Board board);
private:
    bool started = false;
    bool end = false;
    Board board;
};

#endif // SIMULATIONTHREAD_H
