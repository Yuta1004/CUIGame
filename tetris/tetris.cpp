#include <iostream>
#include <vector>
#include <random>
#include "../game/window.h"
#include "tetris.h"

TETRIS::TETRIS() : Game(50, 40){}

void TETRIS::init() {
    cnt = 0;
    score = 0;
    line = 0;
    level = 1;
    frameCnt = 0;
    tetrimino = new Tetrimino(0);
    tetrimino->setBoard((char const*)board);
    nextTet = new Tetrimino(1);
    holdTet = NULL;
}

void TETRIS::draw(cuiwin::Window *win) {
    // 盤面の枠
    win->setChar('|');
    win->drawRect(30, 0, 1, 40);

    // 盤面描画
    drawBoard(win);

    // テトリミノ描画
    drawTetrimino(win);

    // テトリミノ落下 -> 確定チェック
    if(frameCnt % 10 == 0)
        tetrimino->down();
    if(tetrimino->confirm())
        goNextPhase();

    // スコアなど
    win->drawText(32, 5, "SCORE : %d", score);
    win->drawText(32, 7, "LINE  : %d", line);
    win->drawText(32, 9, "LEVEL : %d", level);
    win->drawText(32, 11, "TIME  : %d", frameCnt);
    win->drawText(32, 20, "HOLD");
    win->drawText(32, 28, "NEXT");
    ++ frameCnt;

    // NEXT, HOLD
    if(holdTet != NULL)
        drawTetrimino(win, holdTet, 11, 10);
    drawTetrimino(win, nextTet, 11, 14);
}

void TETRIS::keyPressed(char key) {
    ++ cnt;
    switch(key) {
    case 's':{
        Tetrimino *tmp = tetrimino;
        tetrimino = holdTet;
        holdTet = tmp;
        holdTet->reset();
        if(tetrimino == NULL)
            goNextPhase();
        break;
    }

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

    case 'i':
        tetrimino->downShot();
        break;

    case 'k':
        tetrimino->down();
        break;

    case 'q':
        exit(0);
        break;
    }
}

void TETRIS::goNextPhase() {
    if(tetrimino != NULL) {
        if(tetrimino->getY() < 0)
            exit(0);
        updateBoard();
    }
    removeLine();

    delete tetrimino;
    std::random_device rnd;
    tetrimino = nextTet;
    tetrimino->setBoard((char const*)board);
    nextTet = new Tetrimino(rnd()%7);
    ++ level;
}

void TETRIS::drawBoard(cuiwin::Window *win) {
    win->setChar('*');
    for(int y = 0; y < 20; ++ y)
        for(int x = 0; x < 10; ++ x)
            if(board[y][x])
                win->drawRect(x*3, y*2, 3, 2);
}

void TETRIS::drawTetrimino(cuiwin::Window *win) {
    int bx = tetrimino->getX();
    int by = tetrimino->getY();
    drawTetrimino(win, tetrimino, bx, by);
}

void TETRIS::drawTetrimino(cuiwin::Window *win, Tetrimino *tet, int bx, int by) {
    const char *blockState = tet->getState();
    for(int y = 0; y < 4; ++ y)
        for(int x = 0; x < 4; ++ x)
            if(blockState[x+y*4])
                win->drawRect((bx+x)*3, (by+y)*2, 3, 2);
}

void TETRIS::updateBoard() {
    int bx = tetrimino->getX(), by = tetrimino->getY();
    const char *blockState = tetrimino->getState();
    for(int y = 0; y < 4; ++ y)
        for(int x = 0; x < 4; ++ x)
            if(blockState[x+y*4])
                board[by+y][bx+x] = 1;
}

void TETRIS::removeLine() {
    int sum = 0;
    for(int y = 19; y >= 0; -- y) {
        // 消せるか確認
        bool canRemove = true;
        for(int x = 0; x < 10; ++ x)
            canRemove &= (bool)board[y][x];

        // 消す
        sum += canRemove;
        for(int x = 0; x < 10; ++ x)
            if(y-sum >= 0)
                board[y][x] = board[y-sum][x];
            else
                board[y][x] = 0;
        if(canRemove)
            ++ y;
    }

    static int baseScore[] = {0, 40, 100, 300, 1200};
    score += level * baseScore[(sum+1)/2];
    line += (sum+1)/2;
}

