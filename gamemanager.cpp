#include "gamemanager.h"
#include "game.h"

using namespace mgameman;

GameManager::GameManager(mgame::Game *game) {
    this->game = game;
    this->frameRate = 10;
}

void GameManager::setFrameRate(int frameRate) {
    this->frameRate = frameRate;
}
