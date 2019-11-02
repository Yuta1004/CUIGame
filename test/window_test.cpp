#include <iostream>
#include <unistd.h>
#include "../game/window.h"

int main() {
    yngame::Window win(40, 30);
    std::cout << "Width : " << win.getWidth() << std::endl;
    std::cout << "Height : " << win.getHeight() << std::endl;

    int x = 5, y = 0;
    while(1) {
        win.refresh();
        win.setChar('O');
        win.drawRect(x, y, 4, 2);
        win.drawText(20, 10, "POS: (%d, %d)", x, y);
        win.update();

        ++ y;
        usleep(1*1000000);
    }
}
