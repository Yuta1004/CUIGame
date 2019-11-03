#include <cmath>
#include <random>
#include "tower.h"

Tower::Tower() : Game(50, 40) {}

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
        win->drawRect(x*3, idx*2, len*3, 2);
    }

    // バー
    win->drawRect((barX-barLen)*3, (19-height)*2, barLen*3, 2);
    ++ barX;
    barX %= 25+barLen;
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
    blockInfo[h].first = barX;
    blockInfo[h].second = barLen;
    ++ height;
    makeNewBar();
}
