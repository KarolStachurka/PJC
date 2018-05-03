#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
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

class Board
{
private:
    int boardRowsNumber = 100;
    int boardColumnsNumber = 100;
    int turn = 0;
    vector<Field> board;

public:
    Board();
    ~Board();
    Board(int rows, int columns, int snails, int plants);
    void addSnail(int x, int y, int index);
    void addPlant(int x, int y, int index);
    void nextTurn();
    void plantsNextTurn();
    void snailsNextTurn();

    //setters
    void setBoardRowsNumber(int rows);
    void setBoardColumnsNumber(int columns);
    void setStartingPosition(int numberOfSnails, int numberOfPlants);

    //getters
    int getBoardRowsNumber();
    int getBoardColumnsNumber();
    int getTurn();
    int getSnailNumber();
    int getPlantNumber();
    vector<Field> getBoard();
};

#endif // BOARD_H
