#include <random>
#include "snake.h"

Snake::Snake() : Game(60, 30){}

Snake::~Snake() {}

void Snake::init() {
    std::random_device rnd;
    x = rnd() % 15 + 5;
    y = rnd() % 5 + 5;
    dx = 0;
    dy = 1;
}

void Snake::draw(yngame::Window *win) {
    if(frameCnt % 15 == 0) {
        x += dx;
        y += dy;
    }

    win->setChar('*');
    win->drawRect(x*3, y*2, 3, 2);

    ++ frameCnt;
}

void Snake::keyPressed(char key) {
    switch(key) {
    case 'q':
        quit();
    }
}

