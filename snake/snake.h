#ifndef SNAKEH
#define SNAKEH

#include "../game/game.h"
#include "../game/window.h"

class Snake : yngame::Game {

public:
    Snake();
    ~Snake();
    void init();
    void draw(yngame::Window *win);
    void keyPressed(char key);

};

#endif
