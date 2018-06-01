#include "board.h"

Board::Board(){}
Board::Board(int rows, int columns, int lettuce, int cabbage, int grass, int helix, int slug, int worm)
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
    for(auto &i: board)
    {
        i.plant->cabbageNumber = 0;
        i.plant->lettuceNumber = 0;
        i.plant->grassNumber = 0;
        i.snail->helixNumber = 0;
        i.snail->slugNumber = 0;
        i.snail->wormNumber = 0;
    }
    if(columns*rows < lettuce + cabbage + grass || columns*rows < slug + helix + worm)
    {
        setPlantStartingPosition(0, 0, 0);
        setSnailStartingPosition(0, 0, 0);
    }
    else
    {
        setPlantStartingPosition(lettuce, cabbage, grass);
        setSnailStartingPosition(helix, slug, worm);
    }
}
Board::~Board()
{
    for(auto &i: board)
    {
        i.plant = NULL;
        i.snail = NULL;
    }
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
void Board::getPlantNumber(int &lettuce, int &cabbage, int &grass)
{
    for(auto &i: board)
    {
        if(i.plant)
        {
            Plant *temp = i.plant;
            if(temp->getType() == 1)
            {
                lettuce = temp->lettuceNumber;
            }
            if(temp->getType() == 2)
            {
                cabbage = temp->cabbageNumber;
            }
            if(temp->getType() == 3)
            {
                grass = temp->grassNumber;
            }
        }
    }
}

void Board::getSnailNumber(int& helix, int& slug, int& worm){
    for(auto &i: board)
    {
        if(i.snail)
        {
            Snail *temp = i.snail;
            if(temp->getType() == 1)
            {
               helix = temp->helixNumber;
            }
            if(temp->getType() == 2)
            {
                slug = temp->slugNumber;
            }
            if(temp->getType() == 3)
            {
                worm = temp->wormNumber;
            }
        }
    }
}
void Board::setSnailStartingPosition(int helix, int slug, int worm)
{
    int helixCounter = 0, slugCounter = 0, wormCounter = 0;
    while(helixCounter < helix)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.snail)
        {
            Helix *helix = new Helix;
            helix->setCoordinates(current.getX(), current.getY());
            current.snail = helix;
            helix = NULL;
            delete helix;
            board.at(fieldNumber) = current;
            helixCounter++;
        }
    }
    while(slugCounter < slug)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.snail)
        {
            Slug *slug = new Slug;
            slug->setCoordinates(current.getX(), current.getY());
            current.snail = slug;
            slug = NULL;
            delete slug;
            board.at(fieldNumber) = current;
            slugCounter++;
        }
    }
    while(wormCounter < worm)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        Worm *worm = new Worm;
        worm->setCoordinates(current.getX(), current.getY());
        current.snail = worm;
        worm = NULL;
        delete worm;
        board.at(fieldNumber) = current;
        wormCounter++;

    }
}
void Board::setPlantStartingPosition(int lettuce, int cabbage, int grass)
{
    int lettuceCounter = 0, cabbageCounter = 0, grassCounter = 0;
    while(lettuceCounter < lettuce)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        Lettuce *lettuce = new Lettuce;
        lettuce->setCoordinates(current.getX(), current.getY());
        current.plant = lettuce;
        lettuce = NULL;
        delete lettuce;
        board.at(fieldNumber) = current;
        lettuceCounter++;
    }
    while(cabbageCounter < cabbage)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        Cabbage *cabbage = new Cabbage;
        cabbage->setCoordinates(current.getX(), current.getY());
        current.plant = cabbage;
        cabbage = NULL;
        delete cabbage;
        board.at(fieldNumber) = current;
        cabbageCounter++;
    }
    while(grassCounter < grass)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        Grass *grass = new Grass;
        grass->setCoordinates(current.getX(), current.getY());
        current.plant = grass;
        grass = NULL;
        delete grass;
        board.at(fieldNumber) = current;
        grassCounter++;
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
            if(temp->isReproduced() && !temp->isDead())
            {
                int newX = temp->getX();
                int newY = temp->getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.plant)
                    {
                        switch (temp->getType()) {
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
            if(temp->isReproduced() && !temp->isDead())
            {
                int newX = temp->getX();
                int newY = temp->getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.snail)
                    {
                        switch (temp->getType()) {
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
    if(turn > 0)
    {
        plantsNextTurn();
        snailsNextTurn();
    }
    turn++;
}
void Board::addSnail(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*x + y];
    if(!current.snail)
    {
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
    }
    board[boardColumnsNumber*x + y] = current;
}
void Board::addPlant(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*x + y];
    if(!current.plant)
    {
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
    }
    board[boardColumnsNumber*x + y] = current;
}
