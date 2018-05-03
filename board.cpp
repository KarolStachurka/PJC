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
    srand(time(0));
    int it = 0;
    for(auto &i: board)
    {
        i.setCoordinates(it/boardRowsNumber, it%boardColumnsNumber);
        it++;
    }

    if(columns*rows < snails || columns*rows < plants)
        setStartingPosition(1,1);

    else
        setStartingPosition(snails, plants);
}
Board::~Board()
{
    board.clear();
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
void Board::setStartingPosition(int numberOfSnails, int numberOfPlants)
{
    int snailCounter = 0, plantCounter = 0;
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
        if(!current.plant)
        {
            switch (rand()%3) {
            case 0:
            {
                Lettuce *plant = new Lettuce;
                plant->setCoordinates(current.getX(), current.getY());
                current.plant = plant;
                plant = NULL;
                delete plant;
                break;
            }
            case 1:
            {
                Grass *plant = new Grass;
                plant->setCoordinates(current.getX(), current.getY());
                current.plant = plant;
                plant = NULL;
                delete plant;
                break;
            }
            case 2:
            {
                Grass *plant = new Grass;
                plant->setCoordinates(current.getX(), current.getY());
                current.plant = plant;
                plant = NULL;
                delete plant;
                break;
            }
            default:
                break;
            }
            board.at(fieldNumber) = current;
            plantCounter++;
        }
    }
}
void Board::plantsNextTurn()
{
    for(auto &i: board)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        if(current.plant != NULL)
        {
            Plant *temp = current.plant;
            if(current.getSnailExistence())
                temp->beEaten(2);
            temp->grow();
            temp->die();
            if(temp->isDead())
            {
                delete current.plant;
                current.plant = NULL;
            }
            if(temp->isReproduction() && !temp->isDead())
            {
                int newX = temp->getX();
                int newY = temp->getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(next.plant == NULL)
                    {
                        switch (temp->getPlantType()) {
                        case 1:
                        {
                            Lettuce *plant = new Lettuce;
                            plant->setCoordinates(next.getX(), next.getY());
                            next.plant = plant;
                            plant = NULL;
                            delete plant;
                            break;
                        }
                        case 3:
                        {
                            Grass *plant = new Grass;
                            plant->setCoordinates(next.getX(), next.getY());
                            next.plant = plant;
                            plant = NULL;
                            delete plant;
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    board.at(boardColumnsNumber*newX + newY) = next;
                }
            }
            temp = NULL;
            delete temp;
        }
        board.at(boardColumnsNumber*current.getX() + current.getY()) = current;
    }
}
void Board::snailsNextTurn()
{
    for(auto &i : board)
        i.setSnailExistence(false);

    for(auto &i :snailVector)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        current.setSnailExistence(true);
        Field next;
        i.grow();
        i.die();
        if(i.isDead())
        {
            current.setSnailExistence(false);
        }
        if(current.getPlantExistence() && !i.isDead())
        {
            i.eat();
        }
        else if(!i.isDead() && i.isReproduced())
        {
            int newX = i.getX();
            int newY = i.getY();
            bool isReady = i.getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
            if(isReady)
            {
                next = board.at(boardColumnsNumber*newX + newY);
                if(!next.getSnailExistence())
                {
                    next.setSnailExistence(true);
                    Helix helix;
                    helix.setCoordinates(newX, newY);
                    snailVector.push_back(helix);
                    i.setReproduction(false);
                }
                board.at(boardColumnsNumber*newX + newY) = next;
            }
        }
        else if(!i.isDead())
        {
            int newX = i.getX();
            int newY = i.getY();
            bool isReady = i.getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
            if(isReady)
            {
                next = board.at(boardColumnsNumber*newX + newY);
                if(!next.getSnailExistence())
                {
                    next.setSnailExistence(true);
                    current.setSnailExistence(false);
                    i.move(newX, newY);

                }
                board.at(boardColumnsNumber*newX + newY) = next;
            }
        }
        board.at(boardColumnsNumber*(current.getX()) + current.getY()) = current;

    }
    snailVector.erase(std::remove_if(snailVector.begin(), snailVector.end(),[](Snail &i){return i.isDead();}), snailVector.end());
}

void Board::nextTurn()
{
    plantsNextTurn();
    snailsNextTurn();
    turn++;
}
void Board::addSnail(int x, int y)
{
    Field current = board[boardColumnsNumber*(x) + y];
    current.setSnailExistence(true);
    board[boardColumnsNumber*(x) + y] = current;
    Helix newHelix;
    newHelix.setX(current.getX());
    newHelix.setY(current.getY());
    snailVector.push_back(newHelix);
}
void Board::addPlant(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*(x) + y];
    switch (index) {
    case 1:
    {
        Lettuce *plant = new Lettuce;
        plant->setCoordinates(current.getX(), current.getY());
        current.plant = plant;
        break;
    }
    case 3:
    {
        Grass *plant = new Grass;
        plant->setCoordinates(current.getX(), current.getY());
        current.plant = plant;
        break;
    }
    default:
        break;
    }
    board[boardColumnsNumber*(x) + y] = current;
}
