#ifndef FIELD_H
#define FIELD_H
#include "snail.h"
#include "plant.h"



//!  Definicja klasy Field.
/*!
  Klasa odpowiada za obsługę pojedynczego pola na planszy do gry.
*/
class Field
{
public:
    //! Domyślny konstruktor
        /*!
        */
    Field();
    //! Destruktor
        /*!
          Odpowiada za czyszczenie pamięci po usunięciu pola.
        */
    ~Field();

    /// pole zawierające wskaźnik na roślinę
    Plant* plant;

    /// pole zawierające wskaźnik na ślimaka
    Snail* snail;

    //! Ustawia współrzędne pola na planszy
        /*!
          \param x  pierwsza współrzędna pola.
          \param y  druga współrzędna pola.
        */
    void setCoordinates(int x, int y);

    //! Zwraca informacje o pierwszej współrzędnej
        /*!
          \returns informacje o wartości współrzędnej x
        */
    int getX();

    //! Zwraca informacje o drugiej współrzędnej
        /*!
          \returns informacje o wartości współrzędnej y
        */
    int getY();
protected:

    /// pole zawierające pierwszą współrzędną pola
    int coordinateX;

        /// pole zawierające drugą współrzędną pola
    int coordinateY;
};
#endif // FIELD_H
