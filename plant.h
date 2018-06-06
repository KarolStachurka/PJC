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

    void beEaten(int energyLoss);

    bool getNewPosition(int &x, int &y, int maxX, int maxY);

    //! Odpowiada za wzrost rośliny
    void grow();

    //! Odpowiada za więdnięcie rośliny
    void die();

    bool isEaten();
    int getSize();
    string getPlantInfo();


protected:

    int size;
    int range;

    bool eaten;

};

#endif // PLANT_H
