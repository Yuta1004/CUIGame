#include "game/game.h"
#include "tetris/tetris.h"

int main() {
    yngame::Game *tetris = (yngame::Game*)new TETRIS();
    tetris->setFrameRate(30);
    tetris->run();
}

