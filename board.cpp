#include "board.h"

Board::Board()
{
//    vector<Field> vec;
//    vec.resize(boardRowsNumber*boardColumnsNumber);
//    this->board = vec;
//    setStartingPosition(200, 200);
}
Board::Board(int rows, int columns, int snails, int plants)
{
    setBoardColumnsNumber(columns);
    setBoardRowsNumber(rows);
    board.resize(boardRowsNumber*boardColumnsNumber);
    int it = 0;
    for(auto &i:board)
    {
        i.setCoordinates(it/boardRowsNumber, it%boardColumnsNumber);
        it++;
    }
    if(columns*rows < snails || columns*rows < plants)
        setStartingPosition(1,1);
    else
    setStartingPosition(snails, plants);
}
void Board::setBoardColumnsNumber(int columns)
{
    this->boardColumnsNumber = columns;
}
void Board::setBoardRowsNumber(int rows)
{
    this->boardRowsNumber = rows;
}

vector<Field> Board::getBoard()
{
    return board;
}
int Board::getBoardRowsNumber()
{
    return boardRowsNumber;
}
int Board::getBoardColumnsNumber()
{
    return boardColumnsNumber;
}
int Board::getTurn()
{
    return turn;
}
int Board::getPlantNumber(){
    return plantVector.size();
}
int Board::getSnailNumber(){
    return snailVector.size();
}
string Board::testBoard()
{
    string helper = "";
    for (int row = 0; row < boardRowsNumber; row++) {
        for (int col = 0; col < boardColumnsNumber; col++) {
            Field current = board[row * boardColumnsNumber + col];
            if(current.getSnailExistence() && current.getPlantExistence())
                helper += "F";
            else if (current.getSnailExistence())
                helper += "@";
            else if(current.getPlantExistence())
                helper+= "0";
            else
                helper += "x";
        }
        helper +="\n";
    }
    return helper;
}
void Board::setStartingPosition(int numberOfSnails, int numberOfPlants)
{
    int snailCounter = 0, plantCounter = 0;
    srand(time(0));
    while(snailCounter < numberOfSnails)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.getSnailExistence())
        {
            current.setSnailExistence(true);
            Helix helix;
            helix.setX(current.getX());
            helix.setY(current.getY());
            snailVector.push_back(helix);
            board.at(fieldNumber) = current;
            snailCounter++;
        }
    }
    while(plantCounter < numberOfPlants)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.getPlantExistence())
        {
            current.setPlantExistence(true);
            Lettuce lettuce;
            lettuce.setX(current.getX());
            lettuce.setY(current.getY());
            plantVector.push_back(lettuce);
            board.at(fieldNumber) = current;
            plantCounter++;
        }
    }
}
void Board::plantsNextTurn()
{
    for(auto &i :plantVector)
    {
       Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
       if(current.getSnailExistence())
           i.beEaten(2);
       i.grow();
       i.die();
       if(i.isDead())
       {
           current.setPlantExistence(false);
       }
       if(i.isReproduction() && !i.isDead())
       {
           int newX = i.getX();
           int newY = i.getY();
           bool isReady = i.getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
           if(isReady)
           {
               Field next = board.at(boardColumnsNumber*newX + newY);
               if(!next.getPlantExistence())
               {
                   next.setPlantExistence(true);
                   Lettuce lettuce;
                   lettuce.setCoordinates(next.getX(), next.getY());
                   plantVector.push_back(lettuce);
               }
               board.at(boardColumnsNumber*newX + newY) = next;
           }
       }
       board.at(boardColumnsNumber*current.getX() + current.getY()) = current;

    }
    plantVector.erase(std::remove_if(plantVector.begin(), plantVector.end(),[](Plant &i){return i.isDead();}), plantVector.end());
}
void Board::snailsNextTurn()
{
    for(auto &i :snailVector)
    {
        Field current = board[boardColumnsNumber*(i.getX()) + i.getY()];
        current.setSnailExistence(true);
        Field next;
        int direction = rand()%4;
        i.grow();
        i.die();
        if(i.isDead())
        {
            current.setSnailExistence(false);
        }
        board[boardColumnsNumber*(current.getX()) + current.getY()] = current;
        if(current.getPlantExistence() && !i.isDead())
        {
            i.eat();
        }
        else if(!i.isDead())
        {
            if(direction == 0 && i.getX() > 0)
            {
                next = board[boardColumnsNumber*(i.getX() - 1) + i.getY()];
                if(!next.getSnailExistence())
                {
                    next.setSnailExistence(true);
                    i.move(next.getX(),next.getY());
                    current.setSnailExistence(false);
                    if(i.isReproduced())
                    {
                        Helix newHelix;
                        newHelix.setX(current.getX());
                        newHelix.setY(current.getY());
                        snailVector.push_back(newHelix);
                        i.setReproduction(false);
                        current.setSnailExistence(true);
                    }
                    board[boardColumnsNumber*next.getX() + next.getY()] = next;
                }
            }
            else if(direction == 1 && i.getY() > 0)
            {
                next = board[boardColumnsNumber*(i.getX()) + i.getY() - 1];
                if(!next.getSnailExistence())
                {
                    next.setSnailExistence(true);
                    i.move(next.getX(),next.getY());
                    current.setSnailExistence(false);
                    if(i.isReproduced())
                    {
                        Helix newHelix;
                        newHelix.setX(current.getX());
                        newHelix.setY(current.getY());
                        snailVector.push_back(newHelix);
                        i.setReproduction(false);
                        current.setSnailExistence(true);
                    }
                    board[boardColumnsNumber*next.getX() + next.getY()] = next;
                }
            }
            else if(direction == 2 && i.getX() < boardColumnsNumber - 1)
            {
                next = board[boardColumnsNumber*(i.getX() + 1) + i.getY()];
                if(!next.getSnailExistence())
                {
                    next.setSnailExistence(true);
                    i.move(next.getX(),next.getY());
                    current.setSnailExistence(false);
                    if(i.isReproduced())
                    {
                        Helix newHelix;
                        newHelix.setX(current.getX());
                        newHelix.setY(current.getY());
                        snailVector.push_back(newHelix);
                        i.setReproduction(false);
                        current.setSnailExistence(true);
                    }
                    board[boardColumnsNumber*next.getX() + next.getY()] = next;
                }
            }
            else if(direction == 3 && i.getY() < boardRowsNumber - 1)
            {
                next = board[boardColumnsNumber*(i.getX()) + i.getY() + 1];
                if(!next.getSnailExistence())
                {
                    next.setSnailExistence(true);
                    i.move(next.getX(),next.getY());
                    current.setSnailExistence(false);
                    if(i.isReproduced())
                    {
                        Helix newHelix;
                        newHelix.setX(current.getX());
                        newHelix.setY(current.getY());
                        snailVector.push_back(newHelix);
                        i.setReproduction(false);
                        current.setSnailExistence(true);
                    }
                    board[boardColumnsNumber*next.getX() + next.getY()] = next;
                }
            }
            board[boardColumnsNumber*(current.getX()) + current.getY()] = current;
        }

    }
    snailVector.erase(std::remove_if(snailVector.begin(), snailVector.end(),[](Snail &i){return i.isDead();}), snailVector.end());
}

void Board::nextTurn()
{
    plantsNextTurn();
    snailsNextTurn();
    turn++;
}
void Board::addSnail(int x, int y){
    Field current = board[boardColumnsNumber*(x) + y];
    current.setSnailExistence(true);
    board[boardColumnsNumber*(x) + y] = current;
    Helix newHelix;
    newHelix.setX(current.getX());
    newHelix.setY(current.getY());
    snailVector.push_back(newHelix);
}
