#include <iostream>
#include <unistd.h>
#include "window.h"

int main() {
    cuiwin::Window win(40, 30);
    std::cout << "Width : " << win.getWidth() << std::endl;
    std::cout << "Height : " << win.getHeight() << std::endl;

    int x = 5, y = 0;
    while(1) {
        win.refresh();
        win.setChar('O');
        win.drawRect(x, y, 4, 2);
        win.update();

        ++ y;
        usleep(1*1000000);
    }
}
