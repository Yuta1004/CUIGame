#ifndef SNAKEH
#define SNAKEH

#include <deque>
#include "../game/game.h"
#include "../game/window.h"

class Snake : yngame::Game {

public:
    Snake();
    ~Snake();
    void init();
    void draw(yngame::Window *win);
    void keyPressed(char key);

private:
    int x, y, dx, dy, appleX, appleY, frameCnt;
    std::deque<std::pair<int, int>> tail;

    void putApple();
    void stepSnake();

};

#endif
