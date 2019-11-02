#include "tetris.h"
#include "window.h"

void TETRIS::init() {
    cnt = 0;
}

void TETRIS::draw(cuiwin::Window *win) {
    win->drawText(5, 5, "Hello TETRIS!");
    win->drawText(5, 6, "KeyCnt : %d", cnt);
}

void TETRIS::keyPressed(char key) {
    ++ cnt;
    if(key == 'q') exit(0);
}
