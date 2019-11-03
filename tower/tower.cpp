#include "tower.h"

Tower::Tower() : Game(50, 40) {}

Tower::~Tower() {}

void Tower::init() {
    for(int idx = 0; idx < 25; ++ idx){
        blockInfo[idx].first = 0;
        blockInfo[idx].second = 0;
    }
}

void Tower::draw(yngame::Window *win) {
    // タワー
    win->setChar('#');
    for(int idx = 0; idx < 25; ++ idx) {
        int x = blockInfo[idx].first;
        int len = blockInfo[idx].second;
        win->drawRect(x*3, idx*2, len*3, 2);
    }
}

void Tower::keyPressed(char key) {
    switch(key) {
    case 'q':
        quit();
    }
}

