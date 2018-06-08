#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"


//!  Definicja klasy Game.
/*!
  Klasa odpowiada za obsługę gry.
*/
class Game
{
private:
    /// pole zawieracjące obiekt przechowujący planszę do gry
    Board board;
    /// pole zawierające aktualną turę gry
    int turnNumber = 0;

public:
    //! Domyślny konstruktor
        /*!
        */
    Game();
    //! Tworzy nową grę
        /*!
          Tworzy planszę o podanym rozmiarze, zawierającą podane ilości ślimaków i roślin.
          \param size    rozmiar planszy
          \param lettuce    liczba tworzonych obiektów Lettuce na planszy
          \param cabbage    liczba tworzonych obiektów Cabbage na planszy
          \param grass      liczba tworzonych obiektów Grass na planszy
          \param helix      liczba tworzonych obiektów Helix na planszy
          \param slug       liczba tworzonych obiektów Slug na planszy
          \param worm       liczba tworzonych obiektów Worm na planszy
        */
    void newGame(int size, int lettuce, int cabbage, int grass, int helix, int slug, int worm);
    //! Plansza przechodzi w nową turę
        /*!
          Wywołuje wszystkie metody odpowiedzialne za poruszanie obiektów na planszy
        */
    void nextTurn();
    //! Dodaje nowy orgaizm we wskazanej pozycji
        /*!
          \param x  pierwsza współrzędna nowego organizmu.
          \param y  druga współrzędna nowego organizmu.
          \param index  gatunek dodawanego organizmu
          \param type typ dodawanego organizmu
        */
    void addOrganism(int x, int y, int index, string type);
    //! Zwraca numer aktualnej tury gry
        /*!
        */
    int getTurnNumber();
    //! Zwraca rozmiar planszy gry
        /*!
          \param rows   ilość wierszy planszy
          \param cols   ilość kolumn planszy
        */
    void getBoardSize(int& rows, int& cols);
    //! Zwraca informacje o polu planszy o podanych współrzędnych
        /*!
          \param x   pierwsza współrzędna pola
          \param y   druga współrzędna pola
          \returns informacje o podanym polu
        */
    string getFieldInfo(int x, int y);
    //! Zwraca zakodowane informacje o polach planszy
        /*!
          \returns wektor z zakodowanymi zawartościami poszczególnych pól
        */
    vector<int> getEncodedBoard();

    //! Zwraca aktualną liczbę wszystkich organizmów
        /*!
          \param lettuce    liczba obiektów Lettuce na planszy
          \param cabbage    liczba obiektów Cabbage na planszy
          \param grass      liczba obiektów Grass na planszy
          \param helix      liczba obiektów Helix na planszy
          \param slug       liczba obiektów Slug na planszy
          \param worm       liczba obiektów Worm na planszy
        */
    void getOrganismsNumber(int& lettuce, int& cabbage, int& grass, int& helix, int& slug, int& worm);

    //! Usuwa wszystkie rośliny z gry
    void removePlants();
};

#endif // GAME_H
