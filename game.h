#ifndef GAME
#define GAME

#include "window.h"

namespace mgame {

    class Game {

    public:
        Game(int width, int height);
        ~Game();
        void setFrameRate(int frameRate);
        int getFrameRate();
        void run();

        virtual void init() = 0;
        virtual void draw(cuiwin::Window *w) = 0;
        virtual void keyPressed(char key) = 0;


    private:
        int frameRate;
        cuiwin::Window *win;

        char checkKeyState();
    };
}

#endif
