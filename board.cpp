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
        if(!current.snail)
        {
            switch (rand()%3) {
            case 0:
            {
                Helix *helix = new Helix;
                helix->setCoordinates(current.getX(), current.getY());
                current.snail = helix;
                helix = NULL;
                delete helix;
                break;
            }
            case 1:
            {
                Helix *helix = new Helix;
                helix->setCoordinates(current.getX(), current.getY());
                current.snail = helix;
                helix = NULL;
                delete helix;
                break;
            }
            case 2:
            {
                Helix *helix = new Helix;
                helix->setCoordinates(current.getX(), current.getY());
                current.snail = helix;
                helix = NULL;
                delete helix;
                break;
            }
            default:
                break;
            }
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
        if(current.plant)
        {
            Plant *temp = current.plant;
            if(current.snail)
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
                    if(!next.plant)
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
    //                    Field next = board.at(boardColumnsNumber*newX + newY);
    //                    if(!next.plant)
    //                    {
    //                        switch (temp->getPlantType()) {
    //                        case 1:
    //                        {
    //                            Lettuce *plant = new Lettuce;
    //                            plant->setCoordinates(next.getX(), next.getY());
    //                            next.plant = plant;
    //                            plant = NULL;
    //                            delete plant;
    //                            break;
    //                        }
    //                        case 3:
    //                        {
    //                            Grass *plant = new Grass;
    //                            plant->setCoordinates(next.getX(), next.getY());
    //                            next.plant = plant;
    //                            plant = NULL;
    //                            delete plant;
    //                            break;
    //                        }
    //                        default:
    //                            break;
    //                        }
}
void Board::snailsNextTurn()
{
    for(auto &i: board)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        if(current.snail)
        {
            Snail *temp = current.snail;
            temp->grow();
            temp->die();
            if(temp->isDead())
            {
                delete current.snail;
                current.snail = NULL;
            }
            if(current.plant)
                temp->eat();
            else if(temp->isReproduced() && !temp->isDead())
            {
                int newX = temp->getX();
                int newY = temp->getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.snail)
                    {
                        switch (temp->getSnailType()) {
                        case 1:
                        {
                            Helix *helix = new Helix;
                            helix->setCoordinates(next.getX(), next.getY());
                            next.snail = helix;
                            helix = NULL;
                            delete helix;
                            break;
                        }
                        case 3:
                        {
                            Helix *helix = new Helix;
                            helix->setCoordinates(next.getX(), next.getY());
                            next.snail = helix;
                            helix = NULL;
                            delete helix;
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    board.at(boardColumnsNumber*newX + newY) = next;
                }
            }
            else if(!temp->isDead())
            {
                int newX = temp->getX();
                int newY = temp->getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.snail)
                    {
                        next.snail = temp;
                        temp->setCoordinates(next.getX(),next.getY());
                        current.snail = NULL;
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
