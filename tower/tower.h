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

private:
    int height, barX, barLen;
    std::pair<int, int> blockInfo[20];

    void makeNewBar();

};

#endif
