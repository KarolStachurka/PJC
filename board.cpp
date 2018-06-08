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
        i.setPlant(NULL);
        i.setSnail(NULL);
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

int Board::getBoardRowsNumber()
{
    return boardRowsNumber;
}
int Board::getBoardColumnsNumber()
{
    return boardColumnsNumber;
}
void Board::getPlantNumber(int &lettuce, int &cabbage, int &grass)
{
    lettuce = 0, cabbage = 0, grass = 0;
    for(auto &i: board)
    {
        if(i.getPlant())
        {
            Plant *temp = i.getPlant();
            if(temp->getType() == 1)
            {
                lettuce++;
            }
            if(temp->getType() == 2)
            {
                cabbage++;
            }
            if(temp->getType() == 3)
            {
                grass++;
            }
        }
    }
}
string Board::getFieldInfo(int x, int y)
{
    string output = "";
    Field current = board.at(boardColumnsNumber*x + y);
    if(current.getPlant())
        output += current.getPlant()->getPlantInfo();
    if(current.getSnail())
        output += current.getSnail()->getSnailInfo();
    return output;

}
vector<int> Board::getEncodedBoard()
{
    vector<int> encodedBoard;
    for(auto &i: board)
    {
        int info = 0;
        if(i.getPlant())
        {
            Plant *temp = i.getPlant();
            if(temp->getType() == 1)
            {
                info += 1;
            }
            if(temp->getType() == 2)
            {
                info += 2;
            }
            if(temp->getType() == 3)
            {
                info += 3;
            }
        }
        if(i.getSnail())
        {
            Snail *temp = i.getSnail();
            if(temp->getType() == 1)
            {
               info += 10;
            }
            if(temp->getType() == 2)
            {
                info += 20;
            }
            if(temp->getType() == 3)
            {
                info += 30;
            }
        }
        encodedBoard.push_back(info);
    }
    return encodedBoard;
}

void Board::getSnailNumber(int& helix, int& slug, int& worm){
    helix = 0, slug = 0, worm = 0;
    for(auto &i: board)
    {
        if(i.getSnail())
        {
            Snail *temp = i.getSnail();
            if(temp->getType() == 1)
            {
               helix++;
            }
            if(temp->getType() == 2)
            {
                slug++;
            }
            if(temp->getType() == 3)
            {
                worm++;
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
        if(!current.getSnail())
        {
            Helix *helix = new Helix;
            current.setSnail(helix);
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
        if(!current.getSnail())
        {
            Slug *slug = new Slug;
            current.setSnail(slug);
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
        if(!current.getSnail())
        {
            Worm *worm = new Worm;
            current.setSnail(worm);
            worm = NULL;
            delete worm;
            board.at(fieldNumber) = current;
            wormCounter++;
        }

    }
}
void Board::setPlantStartingPosition(int lettuce, int cabbage, int grass)
{
    int lettuceCounter = 0, cabbageCounter = 0, grassCounter = 0;
    while(lettuceCounter < lettuce)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.getPlant())
        {
            Lettuce *lettuce = new Lettuce;
            current.setPlant(lettuce);
            lettuce = NULL;
            delete lettuce;
            board.at(fieldNumber) = current;
            lettuceCounter++;
        }
    }
    while(cabbageCounter < cabbage)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.getPlant())
        {
            Cabbage *cabbage = new Cabbage;
            current.setPlant(cabbage);
            cabbage = NULL;
            delete cabbage;
            board.at(fieldNumber) = current;
            cabbageCounter++;
        }
    }
    while(grassCounter < grass)
    {
        int fieldNumber = rand()%board.size();
        Field current = board.at(fieldNumber);
        if(!current.getPlant())
        {
            Grass *grass = new Grass;
            current.setPlant(grass);
            grass = NULL;
            delete grass;
            board.at(fieldNumber) = current;
            grassCounter++;
        }
    }
}
void Board::plantsNextTurn()
{
    for(auto &i: board)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        if(current.getPlant())
        {
            Plant *temp = current.getPlant();
            if(current.getSnail())
                temp->beEaten(current.getSnail()->getHunger());
            temp->grow();
            temp->die();
            if(temp->isReproduced() && !temp->isDead())
            {
                int newX = i.getX();
                int newY = i.getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    switch (temp->getType()) {
                    case 1:
                    {
                        if(!next.getPlant() || next.getPlant()->getType() == 3)
                        {
                            Lettuce *lettuce = new Lettuce;
                            next.setPlant(lettuce);
                            lettuce = NULL;
                            delete lettuce;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(!next.getPlant() || next.getPlant()->getType() == 3)
                        {
                            Cabbage *cabbage = new Cabbage;
                            next.setPlant(cabbage);
                            cabbage = NULL;
                            delete cabbage;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(!next.getPlant())
                        {
                            Grass *grass = new Grass;
                            next.setPlant(grass);
                            grass = NULL;
                            delete grass;
                        }
                        break;
                    }
                    default:
                        break;
                    }
                    temp->reproduce();
                    board.at(boardColumnsNumber*newX + newY) = next;
                }
            }
            if(temp->isDead())
            {
                current.setPlant(NULL);
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
        if(current.getSnail())
            i.getSnail()->setTired(false);
    }
    for(auto &i: board)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        if(current.getSnail() && !current.getSnail()->isTired())
        {
            Snail *temp = current.getSnail();
            temp->grow();
            temp->die();
            if(temp->isDead())
            {
                current.setSnail(NULL);
            }
            if(current.getPlant() && !temp->isDead())
            {
                temp->eat(current.getPlant()->getType());
            }
            if(temp->isReproduced() && !temp->isDead())
            {
                int newX = i.getX();
                int newY = i.getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.getSnail())
                    {
                        switch (temp->getType()) {
                        case 1:
                        {
                            Helix *helix = new Helix;
                            next.setSnail(helix);
                            helix = NULL;
                            delete helix;
                            break;
                        }
                        case 2:
                        {
                            Slug *slug = new Slug;
                            next.setSnail(slug);
                            slug = NULL;
                            delete slug;
                            break;
                        }

                        case 3:
                        {
                            Worm *worm = new Worm;
                            next.setSnail(worm);
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
                int newX = i.getX();
                int newY = i.getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.getSnail())
                    {
                        next.setSnail(temp);
                        current.setSnail(NULL);
                    }
                    else if(temp->getType() == 3 && next.getSnail()->getType() == 1)
                    {
                        temp->eat(0);
                        next.setSnail(temp);
                        current.setSnail(NULL);
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

void Board::addSnail(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*x + y];
    if(!current.getSnail())
    {
        switch (index) {
        case 1:
        {
            Helix *helix = new Helix;
            current.setSnail(helix);
            helix = NULL;
            delete helix;
            break;
        }
        case 2:
        {
            Slug *slug = new Slug;
            current.setSnail(slug);
            slug = NULL;
            delete slug;
            break;
        }
        case 3:
        {
            Worm *worm = new Worm;
            current.setSnail(worm);
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
    if(!current.getPlant())
    {
        switch (index) {
        case 1:
        {
            Lettuce *lettuce = new Lettuce;
            current.setPlant(lettuce);
            lettuce = NULL;
            delete lettuce;
            break;
        }
        case 2:
        {
            Cabbage *cabbage = new Cabbage;
            current.setPlant(cabbage);
            cabbage = NULL;
            delete cabbage;
            break;
        }
        case 3:
        {
            Grass *grass = new Grass;
            current.setPlant(grass);
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
void Board::removePlants()
{
    for(auto &i: board)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        if(current.getPlant())
        {
            current.setPlant(NULL);
        }
        board.at(boardColumnsNumber*current.getX() + current.getY()) = current;
    }
}
