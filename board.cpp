#include "board.h"

Board::Board()
{
    vector<Field> vec;
    vec.resize(boardRowsNumber*boardColumnsNumber);
    this->board = vec;
    setStartingPosition(200, 200);
}
Board::Board(int rows, int columns, int snails, int plants)
{
    setBoardColumnsNumber(columns);
    setBoardRowsNumber(rows);
    vector<Field> vec;
    vec.resize(boardRowsNumber*boardColumnsNumber);
    int it = 0;
    for(auto &i:vec)
    {
        i.setCoordinates(it/boardRowsNumber,it%boardColumnsNumber);
        it++;
    }
    this->board = vec;
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
        Field current = board[fieldNumber];
        if(!current.getSnailExistence())
        {
            current.setSnailExistence(true);
            Helix helix;
            helix.setX(fieldNumber / boardRowsNumber);
            helix.setY(fieldNumber % boardColumnsNumber);
            snailVector.push_back(helix);
            board[fieldNumber] = current;
            snailCounter++;
        }
    }
    while(plantCounter < numberOfPlants)
    {
        int fieldNumber = rand()%board.size();
        Field current = board[fieldNumber];
        if(!current.getPlantExistence())
        {
            current.setPlantExistence(true);
            Lettuce lettuce;
            lettuce.setX(fieldNumber / boardRowsNumber);
            lettuce.setY(fieldNumber % boardColumnsNumber);
            plantVector.push_back(lettuce);
            board[fieldNumber] = current;
            plantCounter++;
        }
    }
}
void Board::plantsNextTurn()
{
    for(auto &i :plantVector)
    {
       Field current = board[boardColumnsNumber*(i.getX()) + i.getY()];
       if(current.getSnailExistence())
           i.beEaten();
       i.grow();
       if(i.isDead())
       {           current.setPlantExistence(false);
           board[boardColumnsNumber*(i.getX()) + i.getY()] = current;
       }
       if(i.getReproduction())
       {
          int direction = rand()%4;
          if(direction == 0 && i.getX() > 0)
          {
              current = board[boardColumnsNumber*(i.getX() - 1) + i.getY()];
              if(!current.getPlantExistence())
              {
                  Lettuce lettuce;
                  lettuce.setX(i.getX() - 1);
                  lettuce.setY(i.getY());
                  current.setPlantExistence(true);
                  i.resetReproducion();
                  board[boardColumnsNumber*lettuce.getX()+lettuce.getY()] = current;
                  plantVector.push_back(lettuce);
              }
          }
          else if(direction == 1 && i.getY() > 0)
          {
              current = board[boardColumnsNumber*(i.getX()) + i.getY() - 1];
              if(!current.getPlantExistence())
              {
                  Lettuce lettuce;
                  lettuce.setX(i.getX());
                  lettuce.setY(i.getY() - 1);
                  current.setPlantExistence(true);
                  i.resetReproducion();
                  board[boardColumnsNumber*lettuce.getX()+lettuce.getY()] = current;
                  plantVector.push_back(lettuce);
              }
          }
          else if(direction == 2 && i.getX() < boardColumnsNumber - 1)
          {
              current = board[boardColumnsNumber*(i.getX() + 1) + i.getY()];
              if(!current.getPlantExistence())
              {
                  Lettuce lettuce;
                  lettuce.setX(i.getX() + 1);
                  lettuce.setY(i.getY());
                  current.setPlantExistence(true);
                  i.resetReproducion();
                  board[boardColumnsNumber*lettuce.getX()+lettuce.getY()] = current;
                  plantVector.push_back(lettuce);
              }
          }
          else if(direction == 3 && i.getY() < boardRowsNumber - 1)
          {
              current = board[boardColumnsNumber*(i.getX()) + i.getY() + 1];
              if(!current.getPlantExistence())
              {
                  Lettuce lettuce;
                  lettuce.setX(i.getX());
                  lettuce.setY(i.getY() + 1);
                  current.setPlantExistence(true);
                  i.resetReproducion();
                  board[boardColumnsNumber*lettuce.getX()+lettuce.getY()] = current;
                  plantVector.push_back(lettuce);
              }
          }

       }

    }
    plantVector.erase(std::remove_if(plantVector.begin(), plantVector.end(),[](Plant &i){return i.isDead();}), plantVector.end());
}
void Board::snailsNextTurn()
{
    for(auto &i :snailVector)
    {
        Field current = board[boardColumnsNumber*(i.getX()) + i.getY()];
        Field next;
        int direction = rand()%4;
        if(direction == 0 && i.getX() > 0)
        {
            next = board[boardColumnsNumber*(i.getX() - 1) + i.getY()];
            if(!next.getSnailExistence())
            {
                next.setSnailExistence(true);
                i.move(next.getX(),next.getY());

                current.setSnailExistence(false);
                board[boardColumnsNumber*i.getX() + i.getY()] = next;
            }
        }
        else if(direction == 1 && i.getY() > 0)
        {
            next = board[boardColumnsNumber*(i.getX()) + i.getY() - 1];
            if(!next.getSnailExistence())
            {
                next.setSnailExistence(true);
                current.setSnailExistence(false);
                i.move(next.getX() ,next.getY());
                board[boardColumnsNumber*i.getX() + i.getY()] = next;
            }
        }
        else if(direction == 2 && i.getX() < boardColumnsNumber - 1)
        {
            next = board[boardColumnsNumber*(i.getX() + 1) + i.getY()];
            if(!next.getSnailExistence())
            {
                next.setSnailExistence(true);
                current.setSnailExistence(false);
                i.move(next.getX() ,next.getY());
                board[boardColumnsNumber*i.getX() + i.getY()] = next;
            }
        }
        else if(direction == 3 && i.getY() < boardRowsNumber - 1)
        {
            next = board[boardColumnsNumber*(i.getX()) + i.getY() + 1];
            if(!next.getSnailExistence())
            {
                next.setSnailExistence(true);
                current.setSnailExistence(false);
                i.move(next.getX() ,next.getY());
                board[boardColumnsNumber*i.getX() + i.getY()] = next;
            }
        }
        board[boardColumnsNumber*(current.getX()) + current.getY()] = current;

    }
}

void Board::nextTurn()
{
    plantsNextTurn();
    snailsNextTurn();
    turn++;
}
