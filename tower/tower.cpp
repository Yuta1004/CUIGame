#include <cmath>
#include <random>
#include "tower.h"

Tower::Tower() : Game(50, 44) {}

Tower::~Tower() {}

void Tower::init() {
    height = 0;
    makeNewBar();
    for(int idx = 0; idx < 20; ++ idx){
        blockInfo[idx].first = 0;
        blockInfo[idx].second = 0;
    }
}

void Tower::draw(yngame::Window *win) {
    // タワー
    win->setChar('#');
    for(int idx = 0; idx < 20; ++ idx) {
        int x = blockInfo[idx].first;
        int len = blockInfo[idx].second;
        win->drawRect((x-25)*3, idx*2, len*3, 2);
    }

    // バー
    win->drawRect((barX-25)*3, (19-height)*2, barLen*3, 2);
    ++ barX;
    barX %= 50;

    // スコア
    win->setChar('-');
    win->drawRect(0, 40, 50, 1);
    win->drawText(20, 42, "SCORE : %d", height);
}

void Tower::keyPressed(char key) {
    switch(key) {
    case ' ':
        reflectBlock();
        break;

    case 'q':
        quit();
    }
}

void Tower::makeNewBar() {
    std::random_device rnd;
    barX = 0;
    barLen = rnd() % 25 + height/2;
}

void Tower::reflectBlock() {
    int h = 19-height;
    int oldBarX = -1, oldBarLen = 99;
    if(h < 19){
        oldBarX = blockInfo[h+1].first;
        oldBarLen = blockInfo[h+1].second;
    }

    blockInfo[h].first = std::max(oldBarX, barX);
    blockInfo[h].second = std::min(barX+barLen, oldBarX+oldBarLen) - blockInfo[h].first;
    if(blockInfo[h].second <= 0)
        quit();
    ++ height;
    makeNewBar();
}
