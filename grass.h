#ifndef GRASS_H
#define GRASS_H

#include "plant.h"


//!  Definicja klasy Grass.
/*!
  Klasa odpowiada za zachowanie obiektów klasy Grass, która jest pochodną klasy Plant na planszy.
  Klasa definiuje parametry i zachowanie trawy na mapie.
*/
class Grass: public Plant
{
public:
    //! Domyślny konstruktor
        /*!
          Ustawia parametry początkowe nowo tworzonego obiektu Grass.
        */
    Grass();

    //! Odpowiada za wzrost trawy
    void grow();

    //! Odpowiada za więdnięcie trawy
    void die();

};
#endif // GRASS_H
