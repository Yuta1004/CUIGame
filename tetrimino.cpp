#include "tetris.h"

Tetrimino::Tetrimino(int id) {
    static char blockBase[7][5][5] = {
        {{0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
    };

    for(int y = 0; y < 5; ++ y)
        for(int x = 0; x < 5; ++ x)
            block[y][x] = blockBase[id][y][x];
    this->x = 7;
    this->y = 0;
}
