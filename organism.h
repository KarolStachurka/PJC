#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>

using namespace std;

//!  Definicja klasy Organism.
/*!
  Klasa abstrakcyjna zawierająca pola i funkcje wykorzystywane przez obiekty obsługujące zachowanie ślimaków i roślin.
*/
class Organism

{
public:
    //! Domyślny konstruktor
    Organism();

    //! Deklaracja wirtualnego destruktora
    virtual ~Organism();

    //! Deklaracja abstrakcyjnej metody grow
    virtual void grow() = 0;

    //! Deklaracja abstrakcyjnej metody die
    virtual void die() = 0;

    //! Deklaracja wirtualnego metody służącej do wyznaczanej nowej pozycji obiektu
    virtual bool getNewPosition(int &x, int &y, int maxX, int maxY) = 0;

    //! Ustawia informację o rozmnożeniu się obiektu
    void reproduce();

    //! Zwraca informacje o wieku organizmu
        /*!
          \returns wiek organizmu
        */
    int getAge();

    //! Zwraca informacje o typie organizmu
        /*!
          \returns gatunek organizmu
        */
    int getType();

    //! Zwraca informacje o nazwie organizmu
        /*!
          \returns nazwa organizmu
        */
    string getName();

    //! Zwraca informacje o czy organizm się rozmnożył
        /*!
          \returns informacje o rozmnożeniu się organizmu
        */
    bool isReproduced();

    //! Zwraca informacje o czy organizm jest martwy
        /*!
          \returns informacje o życiu organizmu
        */
    bool isDead();

protected:
    /// Pole zawierające informację o energii organizmu
    int energy;

    /// Pole zawierające informację o wieku organizmu
    int age;

    /// Pole zawierające informację o czasie ostatniego rozmnażenia sie organizmu
    int lastReproduction;

    /// Pole zawierające informację o typie organizmu
    int type;

    /// Pole zawierające informację o nazwie organizmu
    string name;

    /// Pole zawierające informację o stanie życia organizmu
    bool dead;

    /// Pole zawierające informację o tym czy organizm się rozmnożył
    bool reproduction;

};

#endif // ORGANISM_H
