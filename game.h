#ifndef GAME
#define GAME

#include "window.h"

namespace mgame {

    struct Game {
        virtual void init() = 0;
        virtual void draw(cuiwin::Window *w) = 0;
        virtual void keyPressed() = 0;
        virtual ~Game() {}
    };
}

#endif
