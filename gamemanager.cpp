#include <cstdio>
#include "gamemanager.h"
#include "game.h"
#include "window.h"
#include "kbhit.h"

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
