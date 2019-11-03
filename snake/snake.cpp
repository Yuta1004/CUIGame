#include <random>
#include "snake.h"

Snake::Snake() : Game(60, 30){}

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

    win->setChar('@');
    win->drawDot(appleX*3, appleY*2);

    for(auto pos = std::begin(tail); pos != std::end(tail); ++ pos) {
        win->setChar('*');
        win->drawRect(pos->first*3, pos->second*2, 3, 2);
    }

    ++ frameCnt;
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

void Snake::stepSnake() {
    x += dx;
    y += dy;
    if(x == appleX && y == appleY) {
        std::random_device rnd;
        appleX = rnd() % 20;
        appleY = rnd() % 15;
        auto backPos = tail.back();
        tail.emplace_back(backPos.first, backPos.second);
    }
    tail.pop_back();
    tail.emplace_front(x, y);
}
