#ifndef TOWERH
#define TOWERH

#include "../game/game.h"
#include "../game/window.h"

class Tower : yngame::Game {

public:
    Tower();
    ~Tower();
    void init();
    void draw(yngame::Window *win);
    void keyPressed(char key);

};

#endif
