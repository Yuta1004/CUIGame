#include <iostream>
#include "tetris.h"

Tetrimino::Tetrimino(int id, char const *board) {
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
    this->y = -2;
    this->board = board;
    this->confirmFlag = false;
}

int Tetrimino::getX() {
    return x;
}

int Tetrimino::getY() {
    return y;
}

void Tetrimino::moveL() {
    -- x;
    if(checkHit())
        ++ x;
}

void Tetrimino::moveR() {
    ++ x;
    if(checkHit())
        -- x;
}

void Tetrimino::down() {
    ++ y;
    if(checkHit()) {
        -- y;
        confirmFlag = true;
    }
}

void Tetrimino::downShot() {
    while(1) {
        ++ y;
        if(checkHit()) {
           -- y;
           confirmFlag = true;
           break;
        }
    }
}

void Tetrimino::rotateL() {
    char *newBlock = (char*)calloc(16, sizeof(char));
    for(int y = 0; y < 4 ; ++ y)
        for(int x = 0; x < 4; ++ x)
            newBlock[y+(3-x)*4] = block[y][x];

    for(int idx = 0; idx < 16; ++ idx) {
        char tmp = block[idx/4][idx%4];
        block[idx/4][idx%4] = newBlock[idx];
        newBlock[idx] = tmp;
    }

    if(checkHit())
        for(int idx = 0; idx < 16; ++ idx)
            block[idx/4][idx%4] = newBlock[idx];
    free(newBlock);
}

void Tetrimino::rotateR() {
    char *newBlock = (char*)calloc(16, sizeof(char));
    for(int y = 0; y < 4 ; ++ y)
        for(int x = 0; x < 4; ++ x)
            newBlock[(3-y)+x*4] = block[y][x];

    for(int idx = 0; idx < 16; ++ idx) {
        char tmp = block[idx/4][idx%4];
        block[idx/4][idx%4] = newBlock[idx];
        newBlock[idx] = tmp;
    }

    if(checkHit())
        for(int idx = 0; idx < 16; ++ idx)
            block[idx/4][idx%4] = newBlock[idx];
    free(newBlock);
}

const char *Tetrimino::getState() {
    return (const char*)block;
}

bool Tetrimino::confirm() {
    return confirmFlag;
}

bool Tetrimino::checkHit() {
    bool result = true;
    int bx = this->x, by = this->y;
    for(int y = 0; y < 4; ++ y) {
        for(int x = 0; x < 4; ++ x) {
            if(block[y][x]) {
                result &= (0 <= bx+x && bx+x < 10);
                result &= (0 <= by+y && by+y < 20);
                result &= !board[bx+x+(by+y)*10];
            }
        }
    }
    return !result;
}
