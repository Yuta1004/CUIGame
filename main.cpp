#include "gamemanager.h"
#include "game.h"
#include "tetris.h"

int main() {
    TETRIS *tetris = new TETRIS();
    mgameman::GameManager man((mgame::Game*)tetris, 50, 40);
    man.setFrameRate(10);
    man.run();
}

