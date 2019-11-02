#ifndef TETRISH
#define TETRISH

#include "game.h"
#include "window.h"

class Tetrimino {

public:
    Tetrimino(int id, char const *board);
    int getX();
    int getY();
    void moveL();
    void moveR();
    void rotateL();
    void rotateR();
    void down();
    const char *getState();

private:
    int id, x, y;
    char const *board;
    char block[4][4];

    bool checkHit();

};


class TETRIS : mgame::Game {

public:
    void init();
    void draw(cuiwin::Window *w);
    void keyPressed(char key);

private:
    int cnt, score, line, level, frameCnt;
    char board[20][10];
    Tetrimino *tetrimino;
};


#endif
