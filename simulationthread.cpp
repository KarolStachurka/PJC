#include "simulationthread.h"

SimulationThread::SimulationThread(QObject *parent) : QThread(parent)
{

}
void SimulationThread::run()
{
    while(true)
    {
        if(started)
        {
            board.nextTurn();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            emit sendNextBoard(board);
        }
        if(end)
            break;

    }
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
