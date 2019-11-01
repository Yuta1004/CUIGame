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
    int cnt;

};

#endif
