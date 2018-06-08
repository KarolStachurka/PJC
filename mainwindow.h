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

//!  Definicja klasy MainWindow.
/*!
  Klasa rozszerza działanie klasy QMainWindow i odpowiada za interface fraficzny programu.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Konstruktor
        /*!
          Rozpoczyna działanie programu i tworzy drugi wątek do obsługi symulacji.
        */
    explicit MainWindow(QWidget *parent = 0);

    //! Wyświetla aktualny stan planszy z grą
        /*!
        */
    void displayBoard();

    //! Aktualizuje liczniki z liczbą organizmów na planszy
        /*!
        */
    void updateCounterValues();

    //! Destruktor
        /*!
        */
    ~MainWindow();
signals:
    //!  Sygnał wysyłający informację o rozpoczęciu i zatrzymanu gry
    /*!
      \param started    wartość zawierająca informację czy symulacja ma byc uruchomiona
    */
    void startSimulation(bool);

    //!  Sygnał wysyłający informację o zakończeniu drugiego wątku
    /*!
      \param started    wartość zawierająca informację czy symulacja ma byc uruchomiona
    */
    void endSecondThread(bool);

    //!  Sygnał wysyłający aktualny stan gry
    /*!
      \param game   obiekt zawierający aktualny stan symulacji
    */
    void sendCurrentGame(Game);

private slots:
    //!  Slot odbierający nowy stan gry
    /*!
      \param game   obiekt zawierający nowy stan symulacji
    */
    void getUpdatedGame(Game game);

    //!  Slot odbierający współrzędne kliknięcia myszy
    /*!
      \param x  pierwsza współrzędna miejsca kliknięcia
      \param y  druga współrzędna miejsca kliknięcia
    */
    void getMouseCoords(int x, int y);

    //!  Slot obsługujący wydarzenia po kliknięciu przycisku Następna Tura
    void on_nextTurn_clicked();

    //!  Slot obsługujący wydarzenia po kliknięciu przycisku Start
    void on_automaticMode_clicked();

    //!  Slot obsługujący wydarzenia po kliknięciu przycisku Nowa Gra
    void on_resetButton_clicked();

    //!  Slot obsługujący wydarzenia po kliknięciu przycisku Usuń rośliny
    void on_killPlantsButton_clicked();

private:
    /// drugi wątek służący do obsługi symulacji
    SimulationThread *secondThread;

    ///Pole zawierające wskaźnik do GUI
    Ui::MainWindow *ui;

    /// Pole zawierające wskaźnik do wyświatlanej planszy
    myQGraphicsscene *scene;

    ///Pole zawierające obiekt z aktualną grą
    Game game;

    ///Pole zawierające informację o rozpoczęciu symulacji
    bool simStarted = false;

    ///Pole zawierające treść napisu z przycisku
    QString text1 = "Start";

    ///Pole zawierające treść napisu z przycisku
    QString text2 = "Pauza";

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap helix = QPixmap("graphics/snail.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap empty = QPixmap("graphics/empty.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap cabbage = QPixmap("graphics/cabbage.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap lettuce = QPixmap("graphics/lettuce.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap grass = QPixmap("graphics/grass.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap snailWithPlant = QPixmap("graphics/snailWithPlant.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap slug = QPixmap("graphics/slug.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap slugWithPlant = QPixmap("graphics/slugWithPlant.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap worm = QPixmap("graphics/worm.png");

    ///Pole zawierające ścieżkę do pliku z grafiką
    QPixmap wormWithPlant = QPixmap("graphics/wormWithPlant.png");

    ///Pole zawierające wektor z grafikami poszczególnych pól na planszy
    vector <QGraphicsPixmapItem *> boardObjects;
};

#endif // MAINWINDOW_H
