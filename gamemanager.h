#ifndef GAMEMANAGER
#define GAMEMANAGER

#include "game.h"

namespace mgameman {

    class GameManager {

    public:
        GameManager(mgame::Game *game);
        void setFrameRate(int frameRate);
        void run();

    private:
        mgame::Game *game;
        int frameRate;
    };
}

#endif
