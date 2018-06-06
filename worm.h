#ifndef WORM_H
#define WORM_H

#include "snail.h"

//!  Definicja klasy Helix.
/*!
  Klasa odpowiada za zachowanie obiektów klasy Worm, która jest pochodną klasy Snail na planszy.
  Klasa definiuje parametry i zachowanie śliników luzytańskich na mapie.
*/
class Worm: public Snail
{
public:
    //! Domyślny konstruktor
        /*!
          Ustawia parametry początkowe nowo tworzonego obiektu Worm.
        */
    Worm();

    //!  Odpowiada za rośnięcie ślimaka drapieżnego
    void grow();

    //!  Odpowiada za zdychanie ślimaka drapieżnego
    void die();

    //!  Odpowiada za żywienie się ślimaka drapieżnego
    void eat(int type);
};

#endif // WORM_H
