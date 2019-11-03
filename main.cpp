#include <string>
#include <iostream>
#include "game/game.h"
#include "tetris/tetris.h"
#include "snake/snake.h"
#include "tower/tower.h"
#include "helloworld/hello.h"

using std::cout;
using std::cin;
using std::endl;

yngame::Game* startupGame(int gameID) {
    switch(gameID) {
    case 1:
        return (yngame::Game*)new TETRIS();
    case 2:
        return (yngame::Game*)new Snake();
    case 3:
        return (yngame::Game*)new Tower();
    default:
        return (yngame::Game*)new HelloWorld();;
    }
}

int main() {
    std::ios::sync_with_stdio();

    int gameID;
    cout << "----- Select Game ----" << endl;
    cout << "1. TETRIS" << endl;
    cout << "2. Snake" << endl;
    cout << "3, Tower" << endl;
    cout << "\n>> ";
    cin >> gameID;
    cout << "\n\n" << endl;;

    yngame::Game *game = startupGame(gameID);
    game->setFrameRate(30);
    game->run();
    delete game;
}

