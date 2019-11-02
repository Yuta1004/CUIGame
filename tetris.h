#ifndef TETRISH
#define TETRISH

#include "game.h"
#include "window.h"


class TETRIS : mgame::Game {

public:
    void init();
    void draw(cuiwin::Window *w);
    void keyPressed(char key);

private:
    int cnt, score, line, level;
    char board[20][10];
};

class Tetrimino {

public:
    Tetrimino(int id);
    void rotate();
    void down();
    const char *getState();

private:
    int id, x, y;
    char block[5][5];

};


#endif
