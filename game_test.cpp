#include "game.h"
#include "window.h"

class NullGame : mgame::Game {
public:
    void init(){}
    void draw(cuiwin::Window *w){}
    void keyPressed(char key){}
};

int main() {
    NullGame *ngame = new NullGame();
    mgame::Game *game = (mgame::Game*)ngame;
    delete ngame;
}
