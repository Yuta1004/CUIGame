#include <iostream>
#include <random>
#include "tetris.h"
#include "window.h"

void TETRIS::init() {
    cnt = 0;
    score = 0;
    line = 0;
    level = 1;
    frameCnt = 0;
    tetrimino = new Tetrimino(0, (char const*)board);
}

void TETRIS::draw(cuiwin::Window *win) {
    // 盤面の枠
    win->setChar('|');
    win->drawRect(30, 0, 1, 40);

    // 盤面描画
    drawBoard(win);

    // テトリミノ描画
    int bx = tetrimino->getX(), by = tetrimino->getY();
    const char *blockState = tetrimino->getState();
    for(int y = 0; y < 4; ++ y)
        for(int x = 0; x < 4; ++ x)
            if(blockState[x+y*4])
                win->drawRect((bx+x)*3, (by+y)*2, 3, 2);

    // テトリミノ落下 -> 確定チェック
    if(frameCnt % 10 == 0)
        tetrimino->down();
    if(tetrimino->confirm()) {
        updateBoard();
        delete tetrimino;
        std::random_device rnd;
        tetrimino = new Tetrimino(rnd()%7, (char const*)board);
    }

    // スコアなど
    win->drawText(32, 5, "SCORE : %d", score);
    win->drawText(32, 7, "LINE  : %d", line);
    win->drawText(32, 9, "LEVEL : %d", level);
    win->drawText(32, 11, "TIME  : %d", frameCnt);
    ++ frameCnt;
}

void TETRIS::keyPressed(char key) {
    ++ cnt;
    switch(key) {
    case 'a':
        tetrimino->rotateL();
        break;

    case'd':
        tetrimino->rotateR();
        break;

    case 'j':
        tetrimino->moveL();
        break;

    case 'l':
        tetrimino->moveR();
        break;

    case 'q':
        exit(0);
        break;
    }
}

void TETRIS::drawBoard(cuiwin::Window *win) {
    win->setChar('*');
    for(int y = 0; y < 20; ++ y)
        for(int x = 0; x < 10; ++ x)
            if(board[y][x])
                win->drawRect(x*3, y*2, 3, 2);
}

void TETRIS::updateBoard() {
    int bx = tetrimino->getX(), by = tetrimino->getY();
    const char *blockState = tetrimino->getState();
    for(int y = 0; y < 4; ++ y)
        for(int x = 0; x < 4; ++ x)
            if(blockState[x+y*4])
                board[by+y][bx+x] = 1;
}
