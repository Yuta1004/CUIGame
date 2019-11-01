#include <cstdio>
#include <ctime>
#include <unistd.h>
#include "gamemanager.h"
#include "game.h"
#include "window.h"
#include "kbhit.h"

#define SEC 1000000
#define MILLI 1000
#define MICRO 1

using namespace mgameman;

GameManager::GameManager(mgame::Game *game, int width, int height) {
    this->game = game;
    this->frameRate = 10;
    this->win = new cuiwin::Window(width, height);
}

GameManager::~GameManager() {
    free(this->win);
}

void GameManager::setFrameRate(int frameRate) {
    this->frameRate = frameRate;
}

char GameManager::checkKeyState() {
    if(kbhit())
        return (char)std::getchar();
    return '\0';
}

void GameManager::run() {
    while(1) {
        char key = checkKeyState();
        if(key)
            game->keyPressed(key);
        game->draw(win);
        usleep(1000.0/frameRate*MILLI);
    }
}
