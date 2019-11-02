#include "game/game.h"
#include "tetris/tetris.h"

int main() {
    mgame::Game *tetris = (mgame::Game*)new TETRIS();
    tetris->setFrameRate(30);
    tetris->run();
}

