#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "field.h"
#include "snail.h"
#include "helix.h"

using namespace std;

class Board
{
private:
    int boardRowsNumber = 100;
    int boardColumnsNumber = 100;
    vector<Field> board;
    vector<Snail> snailVector;

public:
    Board();
    Board(int rows, int columns, int snails, int plants);
    void setBoardRowsNumber(int rows);
    void setBoardColumnsNumber(int columns);
    void setStartingPosition(int numberOfSnails, int numberOfPlants);
    int getBoardRowsNumber();
    int getBoardColumnsNumber();
    vector<Field> getBoard();
    string testBoard();
};

#endif // BOARD_H
