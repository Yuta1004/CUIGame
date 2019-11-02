#include "tetris.h"
#include "window.h"

void TETRIS::init() {
    cnt = 0;
    score = 0;
    line = 0;
    level = 1;
    tetrimino = new Tetrimino(4);
    for(int tmp = 0; tmp < 7; ++ tmp)
        tetrimino->down();
}

void TETRIS::draw(cuiwin::Window *win) {
    // 盤面の枠
    win->setChar('|');
    win->drawRect(30, 0, 1, 40);

    // 盤面描画
    win->setChar('*');
    for(int y = 0; y < 20; ++ y)
        for(int x = 0; x < 10; ++ x)
            if(board[y][x])
                win->drawRect(x*3, y*2, 3, 2);

    // テトリミノ描画
    int bx = tetrimino->getX(), by = tetrimino->getY();
    const char *blockState = tetrimino->getState();
    for(int y = 0; y < 5; ++ y)
        for(int x = 0; x < 5; ++ x)
            if(blockState[x+y*5])
                win->drawRect((bx+x)*3, (by+y)*2, 3, 2);

    // スコアなど
    win->drawText(32, 5, "SCORE : %d", score);
    win->drawText(32, 7, "LINE  : %d", line);
    win->drawText(32, 9, "LEVEL : %d", level);
}

void TETRIS::keyPressed(char key) {
    ++ cnt;
    if(key == 'q') exit(0);
}
