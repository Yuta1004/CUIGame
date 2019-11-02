#include "game.h"
#include "tetris.h"

int main() {
    mgame::Game *tetris = (mgame::Game*)new TETRIS();
    tetris->setFrameRate(30);
    tetris->run();
}

