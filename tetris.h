#ifndef TETRISH
#define TETRISH

#include "game.h"
#include "window.h"

class Tetrimino {

public:
    Tetrimino(int id);
    int getX();
    int getY();
    void rotate();
    void down();
    const char *getState();

private:
    int id, x, y;
    char block[5][5];

};


class TETRIS : mgame::Game {

public:
    void init();
    void draw(cuiwin::Window *w);
    void keyPressed(char key);

private:
    int cnt, score, line, level;
    char board[20][10];
};


#endif
