#ifndef CABBAGE_H
#define CABBAGE_H

#include "plant.h"

//!  Definicja klasy Cabbage.
/*!
  Klasa odpowiada za zachowanie obiektów klasy Cabbage, która jest pochodną klasy Plant na planszy.
  Klasa definiuje parametry i zachowanie kapusty na mapie.
*/
class Cabbage: public Plant
{
public:
    //! Domyślny konstruktor
        /*!
          Ustawia parametry początkowe nowo tworzonego obiektu Cabbage.
        */
    Cabbage();

    //! Odpowiada za wzrost kapusty
    void grow();

    //! Odpowiada za więdnięcie kapusty
    void die();

};

#endif // CABBAGE_H
