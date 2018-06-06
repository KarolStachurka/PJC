#ifndef SNAIL_H
#define SNAIL_H

#include <ctime>
#include <cstdlib>

#include "organism.h"

//!  Definicja klasy Snail.
/*!
  Klasa pochodna klasy abstrakcyjnej Organism
  Klasa zawierająca pola i funkcje wykorzystywane przez obiekty obsługujące zachowanie ślimaków.
*/
class Snail: public Organism
{
public:

    //! Domyślny konstruktor
    Snail();

    //! Destruktor
    ~Snail();

    //! Odpowiada za pożywianie się ślimaka
        /*!
          \param type informacje o typie zjadanej rośliny
        */
    virtual void eat(int type);

    //! Odpowiada za zdychanie ślimaka
    void die();

    //! Odpowiada za wzrost ślimaka
    void grow();

    //! Odpowiada za wyznaczenie nowej pozycji ślimaka
        /*!
          \param x pierwsza współrzędna nowej rośliny
          \param y druga współrzędna nowej rośliny
          \param maxX liczba kolumn planszy
          \param maxY liczba wierszy planszy
          \returns informacje czy znaleziono nowe dostępne pole
        */
    bool getNewPosition(int &x, int &y, int maxX, int maxY);

    //! Zwraca informacę o żarłoczności ślimaka
        /*!
          \returns żarłoczność ślimaka
        */
    int getHunger();

    //! Zwraca informacę o szybkości ślimaka
        /*!
          \returns szybkość ślimaka
        */
    int getSpeed();


    //! Zwraca informacę o zmęczeniu ślimaka
        /*!
          \returns zmęczenieżarłoczność ślimaka
        */
    bool isTired();

    //! Zwraca informacje o parametrach ślimaka
        /*!
          \returns informacje o ślimaku
        */
    string getSnailInfo();

    //! Ustawia zmęczenie ślimaka
        /*!
          \param tiredness  informacja o zmęczeniu ślimaka
        */
    void setTired(bool tiredness);

protected:

    ///Pole zawierające informacje o żarłoczności ślimaka
    int hunger;

    ///Pole zawierające informacje o szybkości ślimaka
    int speed;

    ///Pole zawierające informacje o zmęczeniu ślimaka
    bool tiredness;
};

#endif // SNAIL_H
