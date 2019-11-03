#ifndef GAME
#define GAME

#include "window.h"

namespace yngame {

    class Game {

    public:
        Game(int width, int height);
        ~Game();
        void setFrameRate(int frameRate);
        int getFrameRate();
        void run();
        void quit();

        virtual void init() = 0;
        virtual void draw(Window *w) = 0;
        virtual void keyPressed(char key) = 0;


    private:
        int frameRate;
        Window *win;
        bool doExec;

        char checkKeyState();
    };
}

#endif
