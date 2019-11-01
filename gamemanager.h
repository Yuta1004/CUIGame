#ifndef GAMEMANAGER
#define GAMEMANAGER

#include "game.h"
#include "window.h"

namespace mgameman {

    class GameManager {

    public:
        GameManager(mgame::Game *game, int width, int height);
        ~GameManager();
        void setFrameRate(int frameRate);
        void run();

    private:
        mgame::Game *game;
        cuiwin::Window *win;
        int frameRate;

        char checkKeyState();

    };
}

#endif
