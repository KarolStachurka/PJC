#ifndef SIMULATIONTHREAD_H
#define SIMULATIONTHREAD_H
#include <QtCore>
#include <QThread>
#include <QTimer>
#include "board.h"
#include "game.h"

//!  Definicja klasy SimulationThread
/*!
  Klasa rozszerza działanie klasy QThread
  Klasa obsługuje wątek odpowiedzialny za trwanie gry
*/
class SimulationThread: public QThread
{
   Q_OBJECT
public:
    //! Domyślny konstruktor
        /*!
        */
    explicit SimulationThread(QObject *parent = 0);

    void run();
public slots:
    //!  Slot odbierający sygnały o rozpoczęciu i zatrzymanu gry
    /*!
      \param started    wartość zawierająca informację czy symulacja ma byc uruchomiona
    */
    void onSimStarted(bool started);

    //!  Slot odbierający sygnały o zatrzymaniu wątku
    /*!
      \param end    wartość zawierająca czy wątek ma być wyłączony
    */
    void endThread(bool end);

    //!  Slot odbierający obecny stan gry
    /*!
      \param game   obiekt zawierający obecny stan symulacji
    */
    void getCurrentGame(Game game);

    //!  Służy do wywoływania kolejnych tur w symulacji
    /*!
    */
    void iteration();
signals:
    //!  Wysyła uaktualniony stan gry
    /*!
      \param Game   obiekt zawierający obecny stan symulacji
    */
    void sendUpdatedGame(Game);
private:
    /// pole zawierające informację o rozpoczęciu symulacji
    bool started = false;

    ///pole zawierające informację o żądaniu wyłączenia wątku
    bool end = false;

    ///pole z obiektem zawierającym aktualny stan symualcji
    Game game;
};

#endif // SIMULATIONTHREAD_H
