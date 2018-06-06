#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "field.h"

#include "lettuce.h"
#include "cabbage.h"
#include "grass.h"

#include "helix.h"
#include "slug.h"
#include "worm.h"

using namespace std;

//!  Definicja klasy Board.
/*!
  Klasa odpowiada za obsługę planszy do gry i zależności zachodzące między obiektami na niej.
*/
class Board
{
private:
    /// pole zawierające liczbę wierszy pól na planszy
    int boardRowsNumber;

    /// pole zawierające liczbę kolumn pól na planszy
    int boardColumnsNumber;

    /// pole zawierające wektor przechowujące wszystkie pola planszy
    vector<Field> board;

public:
    //! Domyślny konstruktor
        /*!
        */
    Board();
    //! Destruktor
        /*!
          Odpowiada za czyszczenie pamięci po usunięciu planszy.
        */
    ~Board();
    //! Konstruktor
        /*!
          Tworzy planszę o podanym rozmiarze, zawierającą podane ilości ślimaków i roślin.
          \param rows   liczba wierszy planszy
          \param columns    liczba kolumn planszy
          \param lettuce    liczba tworzonych obiektów Lettuce na planszy
          \param cabbage    liczba tworzonych obiektów Cabbage na planszy
          \param grass      liczba tworzonych obiektów Grass na planszy
          \param helix      liczba tworzonych obiektów Helix na planszy
          \param slug       liczba tworzonych obiektów Slug na planszy
          \param worm       liczba tworzonych obiektów Worm na planszy
        */
    Board(int rows, int columns, int lettuce, int cabbage, int grass, int helix, int slug, int worm);

    //! Dodaje ślimaka we wskazanej pozycji
        /*!
          \param x  pierwsza współrzędna nowego ślimaka.
          \param y  druga współrzędna nowego ślimaka.
          \param index  typ dodawanego ślimaka
        */
    void addSnail(int x, int y, int index);

    //! Dodaje roślinę we wskazanej pozycji
        /*!
          \param x  pierwsza współrzędna nowej rośliny.
          \param y  druga współrzędna nowej rośliny.
          \param index  typ dodawanej rośliny
        */
    void addPlant(int x, int y, int index);

    //! Wykonująca ruchy roślin
        /*!
          Odpowiada za wykonanie wszystkich ruchów każdej rośliny na planszy.
        */
    void plantsNextTurn();

    //! Wykonująca ruchy ślimaków
        /*!
          Odpowiada za wykonanie wszystkich ruchów każdego ślimaka na planszy.
        */
    void snailsNextTurn();

    //! Ustawia wartość pola boardRowsNumber
        /*!
          \param rows   nowa wartość pola boardRowsNumber
        */
    void setBoardRowsNumber(int rows);

    //! Ustawia wartość pola boardColumnsNumber
        /*!
          \param columns   nowa wartość pola boardColumnsNumber
        */
    void setBoardColumnsNumber(int columns);

    //! Ustawia początkową ilość ślimaków na planszy
        /*!
          \param helix      liczba tworzonych obiektów Helix na planszy
          \param slug       liczba tworzonych obiektów Slug na planszy
          \param worm       liczba tworzonych obiektów Worm na planszy
        */
    void setSnailStartingPosition(int helix, int slug, int worm);

    //! Ustawia początkową ilość roślin na planszy
        /*!
          \param lettuce    liczba tworzonych obiektów Lettuce na planszy
          \param cabbage    liczba tworzonych obiektów Cabbage na planszy
          \param grass      liczba tworzonych obiektów Grass na planszy
        */
    void setPlantStartingPosition(int lettuce, int cabbage, int grass);

    //! Zwraca wartość pola boardRowsNumber
        /*!
          \returns wartość pola boardRowsNumber
        */
    int getBoardRowsNumber();

    //! Zwraca wartość pola boardColumnsNumber
        /*!
          \returns wartość pola boardColumnsNumber
        */
    int getBoardColumnsNumber();

    //! Zwraca ilość ślimaków na planszy
        /*!
          \param helix      liczba obiektów Helix na planszy
          \param slug       liczba obiektów Slug na planszy
          \param worm       liczba obiektów Worm na planszy
        */
    void getSnailNumber(int& helix, int& slug, int& worm);

    //! Zwraca ilość roślin na planszy
        /*!
          \param lettuce    liczba obiektów Lettuce na planszy
          \param cabbage    liczba obiektów Cabbage na planszy
          \param grass      liczba obiektów Grass na planszy
        */
    void getPlantNumber(int& lettuce, int& cabbage, int& grass);
    //! Zwraca informacje o podanym polu
        /*!
          \param x  pierwsza współrzędna pola.
          \param y  druga współrzędna pola.
          \returns informacje o zawartości podanego pola
        */
    string getFieldInfo(int x, int y);

    //! Zwraca zakodowaną zawartość wszystkich pól planszy
        /*!
          \returns wektor liczb którymi zakodowana jest zawartość pól
        */
    vector<int> getEncodedBoard();
};

#endif // BOARD_H
