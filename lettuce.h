#ifndef LETTUCE_H
#define LETTUCE_H

#include "plant.h"


//!  Definicja klasy Lettuce.
/*!
  Klasa odpowiada za zachowanie obiektów klasy Lettuce, która jest pochodną klasy Plant na planszy.
  Klasa definiuje parametry i zachowanie sałaty na mapie.
*/

class Lettuce: public Plant
{
public:
    //! Domyślny konstruktor
        /*!
          Ustawia parametry początkowe nowo tworzonego obiektu Lettuce.
        */
    Lettuce();

    //! Odpowiada za wzrost sałaty
    void grow();

    //! Odpowiada za więdnięcie sałaty
    void die();
};

#endif // LETTUCE_H
