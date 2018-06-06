#ifndef SLUG_H
#define SLUG_H

#include "snail.h"

//!  Definicja klasy Helix.
/*!
  Klasa odpowiada za zachowanie obiektów klasy Slug, która jest pochodną klasy Snail na planszy.
  Klasa definiuje parametry i zachowanie ślimaków stawowych na mapie.
*/
class Slug: public Snail
{
public:
    //! Domyślny konstruktor
        /*!
          Ustawia parametry początkowe nowo tworzonego obiektu Slug.
        */
    Slug();
     //!  Odpowiada za rośnięcie ślimaka stawowego
    void grow();

        //!  Odpowiada za zdychanie ślimaka stawowego
    void die();

        //!  Odpowiada za żywienie się ślimaka stawowego
    void eat(int type);
};

#endif // SLUG_H
