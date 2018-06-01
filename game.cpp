#include "game.h"

Game::Game()
{

}
Game::Game(int size, int lettuce, int cabbage, int grass, int helix, int slug, int worm)
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
}

