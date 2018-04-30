#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "field.h"
#include "lettuce.h"
#include "helix.h"

using namespace std;

class Board
{
private:
    int boardRowsNumber = 100;
    int boardColumnsNumber = 100;
    int turn = 0;
    vector<Field> board;
    vector<Snail> snailVector;
    vector<Plant> plantVector;

public:
    Board();
    Board(int rows, int columns, int snails, int plants);
    void addSnail(int x, int y);
    void addPlant(int x, int y);
    vector<Field> findNearSnails(int range);
    vector<Field> findNearPlants(int range);
    vector<Field> findNearNoPlants(int range);
    void setBoardRowsNumber(int rows);
    void setBoardColumnsNumber(int columns);
    void setStartingPosition(int numberOfSnails, int numberOfPlants);
    void plantsNextTurn();
    void snailsNextTurn();
    int getBoardRowsNumber();
    int getBoardColumnsNumber();
    int getTurn();
    int getSnailNumber();
    int getPlantNumber();
    vector<Field> getBoard();
    string testBoard();
    void nextTurn();
};

#endif // BOARD_H
