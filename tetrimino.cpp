#include <iostream>
#include "tetris.h"

Tetrimino::Tetrimino(int id) {
    static char blockBase[7][4][4] = {
        {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}}
    };

    for(int y = 0; y < 4; ++ y)
        for(int x = 0; x < 4; ++ x)
            block[y][x] = blockBase[id][y][x];
    this->id = id;
    this->x = 2;
    this->y = -5;
}

int Tetrimino::getX() {
    return x;
}

int Tetrimino::getY() {
    return y;
}

void Tetrimino::rotate() {
    if(id == 6) return; // 四角テトリミノは回転なし

    char *newBlock = (char*)calloc(16, sizeof(char));
    for(int y = 0; y < 4 ; ++ y)
        for(int x = 0; x < 4; ++ x)
            newBlock[y+(3-x)*4] = block[y][x];
    for(int idx = 0; idx < 16; ++ idx)
        block[idx/4][idx%4] = newBlock[idx];
    free(newBlock);
}

void Tetrimino::down() {
    ++ this->y;
}

const char *Tetrimino::getState() {
    return (const char*)block;
}
