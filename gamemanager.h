#ifndef GAMEMANAGER
#define GAMEMANAGER

#include "game.h"

namespace mgameman {

    class GameManager {

    public:
        GameManager(mgame::Game *game);
        void run();
    };
}

#endif
