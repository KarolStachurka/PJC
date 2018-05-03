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
            switch (rand()%3 + 1) {
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
                Slug *slug = new Slug;
                slug->setCoordinates(current.getX(), current.getY());
                current.snail = slug;
                slug = NULL;
                delete slug;
                break;
            }
            case 3:
            {
                Worm *worm = new Worm;
                worm->setCoordinates(current.getX(), current.getY());
                current.snail = worm;
                worm = NULL;
                delete worm;
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
                Lettuce *lettuce = new Lettuce;
                lettuce->setCoordinates(current.getX(), current.getY());
                current.plant = lettuce;
                lettuce = NULL;
                delete lettuce;
                break;
            }
            case 1:
            {
                Cabbage *cabbage = new Cabbage;
                cabbage->setCoordinates(current.getX(), current.getY());
                current.plant = cabbage;
                cabbage = NULL;
                delete cabbage;
                break;
            }
            case 2:
            {
                Grass *grass = new Grass;
                grass->setCoordinates(current.getX(), current.getY());
                current.plant = grass;
                grass = NULL;
                delete grass;
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
                temp->beEaten(current.snail->getHunger());
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
                            Lettuce *lettuce = new Lettuce;
                            lettuce->setCoordinates(next.getX(), next.getY());
                            next.plant = lettuce;
                            lettuce = NULL;
                            delete lettuce;
                            break;
                        }
                        case 2:
                        {
                            Cabbage *cabbage = new Cabbage;
                            cabbage->setCoordinates(next.getX(), next.getY());
                            next.plant = cabbage;
                            cabbage = NULL;
                            delete cabbage;
                            break;
                        }
                        case 3:
                        {
                            Grass *grass = new Grass;
                            grass->setCoordinates(next.getX(), next.getY());
                            next.plant = grass;
                            grass = NULL;
                            delete grass;
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    temp->reproduce();
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
                        case 2:
                        {
                            Slug *slug = new Slug;
                            slug->setCoordinates(next.getX(), next.getY());
                            next.snail = slug;
                            slug = NULL;
                            delete slug;
                            break;
                        }

                        case 3:
                        {
                            Worm *worm = new Worm;
                            worm->setCoordinates(next.getX(), next.getY());
                            next.snail = worm;
                            worm = NULL;
                            delete worm;
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    temp->reproduce();
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
void Board::addSnail(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*(x) + y];
    switch (index) {
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
        Slug *slug = new Slug;
        slug->setCoordinates(current.getX(), current.getY());
        current.snail = slug;
        slug = NULL;
        delete slug;
        break;
    }
    case 3:
    {
        Worm *worm = new Worm;
        worm->setCoordinates(current.getX(), current.getY());
        current.snail = worm;
        worm = NULL;
        delete worm;
        break;
    }
    default:
        break;
    }
    board[boardColumnsNumber*(x) + y] = current;
}
void Board::addPlant(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*(x) + y];
    switch (index) {
    case 1:
    {
        Lettuce *lettuce = new Lettuce;
        lettuce->setCoordinates(current.getX(), current.getY());
        current.plant = lettuce;
        lettuce = NULL;
        delete lettuce;
        break;
    }
    case 2:
    {
        Cabbage *cabbage = new Cabbage;
        cabbage->setCoordinates(current.getX(), current.getY());
        current.plant = cabbage;
        cabbage = NULL;
        delete cabbage;
        break;
    }
    case 3:
    {
        Grass *grass = new Grass;
        grass->setCoordinates(current.getX(), current.getY());
        current.plant = grass;
        grass = NULL;
        delete grass;
        break;
    }
    default:
        break;
    }
    board[boardColumnsNumber*(x) + y] = current;
}
