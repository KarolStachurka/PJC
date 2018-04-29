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
            std::cout << end << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
