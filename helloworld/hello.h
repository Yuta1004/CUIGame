#ifndef HELLOH
#define HELLOH

#include "../game/game.h"
#include "../game/window.h"

class HelloWorld : yngame::Game {

public:
    HelloWorld();
    void init();
    void draw(yngame::Window *win);
    void keyPressed(char key);

};


#endif
