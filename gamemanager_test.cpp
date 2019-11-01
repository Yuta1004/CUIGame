#include "gamemanager.h"

class NullGame : mgame::Game {
public:
    void init(){
        y = 5;
        cnt = 0;
    }

    void draw(cuiwin::Window *w){
        ++ cnt;
        w->refresh();
        w->drawText(10, y, "hello world");
        w->drawText(0, 2, "Cnt : %d", cnt);
        w->drawText(0, 3, "Sec : %d", cnt/5);
        w->update();
    }

    void keyPressed(char key){
        ++ y;
        if(key == 'q') exit(0);
    }

private:
    int y, cnt;
};

int main() {
    NullGame *ngame = new NullGame();
    mgameman::GameManager man((mgame::Game*)ngame, 30, 20);
    man.setFrameRate(5);
    man.run();
}
