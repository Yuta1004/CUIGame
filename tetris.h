#ifndef TETRISH
#define TETRISH

#include "game.h"
#include "window.h"

static char blockBase[7][4][4] = {
    {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}}
};

class Tetrimino {

public:
    Tetrimino(int id);
    int getX();
    int getY();
    const char *getState();
    void setBoard(char const *board);
    void reset();
    void moveL();
    void moveR();
    void rotateL();
    void rotateR();
    void down();
    void downShot();
    bool confirm();

private:
    int id, x, y;
    char const *board;
    char block[4][4];
    bool confirmFlag;

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
    Tetrimino *tetrimino, *holdTet, *nextTet;

    void goNextPhase();
    void drawBoard(cuiwin::Window *win);
    void drawTetrimino(cuiwin::Window *win);
    void drawTetrimino(cuiwin::Window *win, Tetrimino *tet, int bx, int by);
    void updateBoard();
    void removeLine();
};


#endif
