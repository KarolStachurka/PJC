#include "simulationthread.h"

SimulationThread::SimulationThread(QObject *parent) : QThread(parent)
{
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(iteration()));
    timer->start(250);
}
void SimulationThread::run()
{

}
void SimulationThread::onSimStarted(bool started)
{
    this->started = started;
}
void SimulationThread::endThread(bool end)
{
    this->end = end;
}
void SimulationThread::getPrevBoard(Board board)
{
    this->board = board;
}
void SimulationThread::iteration()
{
    if(started)
    {
        board.nextTurn();
        emit sendNextBoard(board);
    }
}
