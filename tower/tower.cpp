#include "tower.h"

Tower::Tower() : Game(50, 40) {}

Tower::~Tower() {}

void Tower::init() {}

void Tower::draw(yngame::Window *win) {}

void Tower::keyPressed(char key) {
    switch(key) {
    case 'q':
        quit();
    }
}

