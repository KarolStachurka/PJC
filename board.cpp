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
void Board::getPlantNumber(int &lettuce, int &cabbage, int &grass)
{
    lettuce = 0, cabbage = 0, grass = 0;
    for(auto &i: board)
    {
        if(i.plant)
        {
            Plant *temp = i.plant;
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
    if(current.plant)
        output += current.plant->getPlantInfo();
    if(current.snail)
        output += current.snail->getSnailInfo();
    return output;

}
vector<int> Board::getEncodedBoard()
{
    vector<int> encodedBoard;
    for(auto &i: board)
    {
        int info = 0;
        if(i.plant)
        {
            Plant *temp = i.plant;
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
        if(i.snail)
        {
            Snail *temp = i.snail;
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
        if(i.snail)
        {
            Snail *temp = i.snail;
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
        if(!current.snail)
        {
            Helix *helix = new Helix;
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
        if(!current.snail)
        {
            Worm *worm = new Worm;
            current.snail = worm;
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
        if(!current.plant)
        {
            Lettuce *lettuce = new Lettuce;
            current.plant = lettuce;
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
        if(!current.plant)
        {
            Cabbage *cabbage = new Cabbage;
            current.plant = cabbage;
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
        if(!current.plant)
        {
            Grass *grass = new Grass;
            current.plant = grass;
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
        if(current.plant)
        {
            Plant *temp = current.plant;
            if(current.snail)
                temp->beEaten(current.snail->getHunger());
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
                        if(!next.plant || next.plant->getType() == 3)
                        {
                            delete next.plant;
                            Lettuce *lettuce = new Lettuce;
                            next.plant = lettuce;
                            lettuce = NULL;
                            delete lettuce;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(!next.plant || next.plant->getType() == 3)
                        {
                            delete next.plant;
                            Cabbage *cabbage = new Cabbage;
                            next.plant = cabbage;
                            cabbage = NULL;
                            delete cabbage;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(!next.plant)
                        {
                            Grass *grass = new Grass;
                            next.plant = grass;
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
                delete current.plant;
                current.plant = NULL;
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
            i.snail->setTired(false);
    }
    for(auto &i: board)
    {
        Field current = board.at(boardColumnsNumber*(i.getX()) + i.getY());
        if(current.snail && !current.snail->isTired())
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
                temp->eat(current.plant->getType());
            if(temp->isReproduced() && !temp->isDead())
            {
                int newX = i.getX();
                int newY = i.getY();
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
                            next.snail = helix;
                            helix = NULL;
                            delete helix;
                            break;
                        }
                        case 2:
                        {
                            Slug *slug = new Slug;
                            next.snail = slug;
                            slug = NULL;
                            delete slug;
                            break;
                        }

                        case 3:
                        {
                            Worm *worm = new Worm;
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
                int newX = i.getX();
                int newY = i.getY();
                bool isReady = temp->getNewPosition(newX, newY, boardRowsNumber, boardColumnsNumber);
                if(isReady)
                {
                    Field next = board.at(boardColumnsNumber*newX + newY);
                    if(!next.snail)
                    {
                        next.snail = temp;
                        current.snail = NULL;
                    }
                    else if(temp->getType() == 3 && next.snail->getType() == 1)
                    {
                        delete next.snail;
                        next.snail = temp;
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

void Board::addSnail(int x, int y, int index)
{
    Field current = board[boardColumnsNumber*x + y];
    if(!current.snail)
    {
        switch (index) {
        case 1:
        {
            Helix *helix = new Helix;
            current.snail = helix;
            helix = NULL;
            delete helix;
            break;
        }
        case 2:
        {
            Slug *slug = new Slug;
            current.snail = slug;
            slug = NULL;
            delete slug;
            break;
        }
        case 3:
        {
            Worm *worm = new Worm;
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
            current.plant = lettuce;
            lettuce = NULL;
            delete lettuce;
            break;
        }
        case 2:
        {
            Cabbage *cabbage = new Cabbage;
            current.plant = cabbage;
            cabbage = NULL;
            delete cabbage;
            break;
        }
        case 3:
        {
            Grass *grass = new Grass;
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
