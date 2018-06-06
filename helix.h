#ifndef HELIX_H
#define HELIX_H

#include "snail.h"

//!  Definicja klasy Helix.
/*!
  Klasa odpowiada za zachowanie obiektów klasy Helix, która jest pochodną klasy Snail na planszy.
  Klasa definiuje parametry i zachowanie ślimaków winniczków na mapie.
*/

class Helix:public Snail
{
public:
    //! Domyślny konstruktor
        /*!
          Ustawia parametry początkowe nowo tworzonego obiektu Helix.
        */
    Helix();
    //!  Odpowiada za rośnięcie ślimaka winniczka
    void grow();

    //!  Odpowiada za zdychanie ślimaka winniczka
    void die();

    //!  Odpowiada za żywienie się ślimaka winniczka
    void eat(int type);
};

#endif // HELIX_H
