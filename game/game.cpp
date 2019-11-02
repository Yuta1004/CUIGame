#include <unistd.h>
#include "game.h"
#include "kbhit.h"

#define SEC 1000000
#define MILLI 1000
#define MICRO 1

using namespace mgame;

Game::Game(int width, int height) {
    this->win = new cuiwin::Window(width, height);
}

void Game::setFrameRate(int frameRate) {
    this->frameRate = frameRate;
}

int Game::getFrameRate() {
    return frameRate;
}

char Game::checkKeyState() {
    if(kbhit())
        return (char)std::getchar();
    return '\0';
}

void Game::run() {
    init();

    while(1) {
        char key = checkKeyState();
        if(key)
            keyPressed(key);
        win->refresh();
        draw(win);
        win->update();
        usleep(1000.0/frameRate*MILLI);
    }
}
