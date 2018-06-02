#include "game.h"

Game::Game()
{
    this->board = Board(1, 1, 0, 0, 0, 0, 0, 0);
}
void Game::nextTurn()
{
    if(turnNumber >0)
    {
        board.plantsNextTurn();
        board.snailsNextTurn();
    }
    turnNumber++;
}
void Game::newGame(int size, int lettuce, int cabbage, int grass, int helix, int slug, int worm)
{
    switch(size){
    case 1:
    {
        this->board = Board(30, 30, lettuce, cabbage, grass, helix, slug, worm);
        break;
    }
    case 2:
    {
        this->board = Board(50, 50, lettuce, cabbage, grass, helix, slug, worm);
        break;
    }
    case 3 :
    {
        this->board = Board(80, 80, lettuce, cabbage, grass, helix, slug, worm);
        break;
    }
    default:
        break;
    }
    turnNumber = 0;
}
void Game::addOrganism(int x, int y, int index, string type)
{
    if(type == "plant")
        board.addPlant(x, y, index);
    if(type == "snail")
        board.addSnail(x, y, index);
}
string Game::getFieldInfo(int x, int y)
{
    return board.getFieldInfo(x, y);
}
vector <int> Game::getEncodedBoard()
{
    return board.getEncodedBoard();
}
void Game::getBoardSize(int &rows, int &cols)
{
    rows = board.getBoardRowsNumber();
    cols = board.getBoardColumnsNumber();
}
void Game::getOrganismsNumber(int &lettuce, int &cabbage, int &grass, int &helix, int &slug, int &worm)
{
    board.getPlantNumber(lettuce, cabbage, grass);
    board.getSnailNumber(helix, slug, worm);
}

int Game::getTurnNumber()
{
    return this->turnNumber;
}
