#include <iostream>
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
    this->id = id;
    this->x = 7;
    this->y = 0;
}

void Tetrimino::rotate() {
    if(id == 6) return; // 四角テトリミノは回転なし

    char *newBlock = (char*)calloc(25, sizeof(char));
    for(int y = 0; y < 5; ++ y)
        for(int x = 0; x < 5; ++ x)
            newBlock[y+(4-x)*5] = block[y][x];
    for(int idx = 0; idx < 25; ++ idx)
        block[idx/5][idx%5] = newBlock[idx];
    free(newBlock);
}

void Tetrimino::down() {
    ++ this->y;
}
