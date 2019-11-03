#include <random>
#include <algorithm>
#include "snake.h"

#define all(x) (x).begin(), (x).end()

Snake::Snake() : Game(60, 34){}

Snake::~Snake() {}

void Snake::init() {
    std::random_device rnd;
    x = rnd() % 15 + 5;
    y = rnd() % 5 + 5;
    appleX = rnd() % 20;
    appleY = rnd() % 15;
    dx = 0;
    dy = 1;
    tail.emplace_front(x, y);
}

void Snake::draw(yngame::Window *win) {
    if(frameCnt % 5 == 0)
        stepSnake();
    ++ frameCnt;

    win->setChar('@');
    win->drawDot(appleX*3, appleY*2);

    for(auto pos = std::begin(tail); pos != std::end(tail); ++ pos) {
        win->setChar('*');
        win->drawRect(pos->first*3, pos->second*2, 3, 2);
    }

    win->setChar('-');
    win->drawRect(0, 30, 60, 1);
    win->drawText(26, 32, "SCORE : %d", tail.size());
}

void Snake::keyPressed(char key) {
    dx = 0;
    dy = 0;

    switch(key) {
    case 'j':
        dx = -1;
        break;

    case 'l':
        dx = 1;
        break;

    case 'i':
        dy = -1;
        break;

    case 'k':
        dy = 1;
        break;

    case 'q':
        quit();
    }
}

void Snake::putApple() {
    std::random_device rnd;
    do {
        appleX = rnd() % 20;
        appleY = rnd() % 15;
    }while(std::find(all(tail), std::make_pair(appleX, appleY)) != tail.end());

    auto backPos = tail.back();
    tail.emplace_back(backPos.first, backPos.second);
}

void Snake::stepSnake() {
    x += dx;
    y += dy;
    if(x < 0 || 20 <= x || y < 0 || 15 <= y)
        quit();
    if(x == appleX && y == appleY)
        putApple();

    tail.pop_back();
    tail.emplace_front(x, y);
    if(std::count(all(tail), std::make_pair(x, y)) != 1)
        quit();
}
