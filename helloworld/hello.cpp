#include "hello.h"

HelloWorld::HelloWorld() : Game(40, 10) {}

HelloWorld::~HelloWorld() {}

void HelloWorld::init() {}

void HelloWorld::draw(yngame::Window *win) {
    win->drawText(15, 5, "HelloWorld");
    win->drawText(11, 7, "Press -q- to quit.");
}

void HelloWorld::keyPressed(char key) {
    if(key == 'q') quit();
}

