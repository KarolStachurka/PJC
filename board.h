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
    int boardRowsNumber;
    int boardColumnsNumber;
    int turn = 0;
    vector<Field> board;

public:
    Board();
    ~Board();
    Board(int rows, int columns, int lettuce, int cabbage, int grass, int helix, int slug, int worm);
    void addSnail(int x, int y, int index);
    void addPlant(int x, int y, int index);
    void nextTurn();
    void plantsNextTurn();
    void snailsNextTurn();

    //setters
    void setBoardRowsNumber(int rows);
    void setBoardColumnsNumber(int columns);
    void setSnailStartingPosition(int helix, int slug, int worm);
    void setPlantStartingPosition(int lettuce, int cabbage, int grass);

    //getters
    int getBoardRowsNumber();
    int getBoardColumnsNumber();
    int getTurn();
    void getSnailNumber(int& helix, int& slug, int& worm);
    void getPlantNumber(int& lettuce, int& cabbage, int& grass);
    vector<Field> getBoard();
};

#endif // BOARD_H
