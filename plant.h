#ifndef PLANT_H
#define PLANT_H

#include <ctime>
#include <cstdlib>

#include "organism.h"

//!  Definicja klasy Plant.
/*!
  Klasa pochodna klasy abstrakcyjnej Organism
  Klasa zawierająca pola i funkcje wykorzystywane przez obiekty obsługujące zachowanie roślin.
*/
class Plant: public Organism
{
public:
    //! Domyślny konstruktor
    Plant();

    //! Destruktor
    ~Plant();

    //! Odpowiada za konsumowanie rośliny
        /*!
          \param energyLoss informacje o ubytku energii rośliny
        */
    void beEaten(int energyLoss);

    //! Odpowiada za wyznaczenie pozycji nowej rośliny
        /*!
          \param x pierwsza współrzędna nowej rośliny
          \param y druga współrzędna nowej rośliny
          \param maxX liczba kolumn planszy
          \param maxY liczba wierszy planszy
          \returns informacje czy znaleziono nowe dostępne pole
        */
    bool getNewPosition(int &x, int &y, int maxX, int maxY);

    //! Odpowiada za wzrost rośliny
    void grow();

    //! Odpowiada za więdnięcie rośliny
    void die();

    //! Zwraca informacje o czy roślina jest aktualnie zjadana
        /*!
          \returns informacje o byciu zjadanym
        */
    bool isEaten();

    //! Zwraca informacje o rozmiarze rośliny
        /*!
          \returns rozmiar rośliny
        */
    int getSize();

    //! Zwraca informacje o parametrach rośliny
        /*!
          \returns informacje o roślinie
        */
    string getPlantInfo();


protected:
    /// Pole zawierające rozmiar rośliny
    int size;

    /// Pole zawierające zasięg rozmnażania się rośliny
    int range;

    /// Pole zawierające informację czy roślina jest aktualnie zjadana
    bool eaten;

};

#endif // PLANT_H
