#include "tetris.h"
#include "window.h"

void TETRIS::init() {
    cnt = 0;
    score = 0;
    line = 0;
    level = 1;
    frameCnt = 0;
    tetrimino = new Tetrimino(0);
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
    for(int y = 0; y < 4; ++ y)
        for(int x = 0; x < 4; ++ x)
            if(blockState[x+y*4])
                win->drawRect((bx+x)*3, (by+y)*2, 3, 2);

    if(frameCnt % 10 == 0)
        tetrimino->down();

    // スコアなど
    win->drawText(32, 5, "SCORE : %d", score);
    win->drawText(32, 7, "LINE  : %d", line);
    win->drawText(32, 9, "LEVEL : %d", level);
    win->drawText(32, 11, "TIME  : %d", frameCnt);
    ++ frameCnt;
}

void TETRIS::keyPressed(char key) {
    ++ cnt;
    if(key == 'a') tetrimino->rotateL();
    if(key == 'd') tetrimino->rotateR();
    if(key == 'q') exit(0);
}
