#include <string>
#include <iostream>
#include "game/game.h"
#include "tetris/tetris.h"

using std::cout;
using std::cin;
using std::endl;

yngame::Game* startupGame(int gameID) {
    switch(gameID) {
    case 1:
        return (yngame::Game*)new TETRIS();
    default:
        return (yngame::Game*)new TETRIS();;
    }
}

int main() {
    std::ios::sync_with_stdio();

    int gameID;
    cout << "----- Select Game ----" << endl;
    cout << "1. TETRIS" << endl;
    cout << "\n>> ";
    cin >> gameID;
    cout << "\n\n" << endl;;

    yngame::Game *game = startupGame(gameID);
    game->setFrameRate(30);
    game->run();
    free(game);
}

