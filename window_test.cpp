#include <iostream>
#include "window.h"

int main() {
    cuiwin::Window win(40, 30);
    std::cout << "Width : " << win.getWidth() << std::endl;
    std::cout << "Height : " << win.getHeight() << std::endl;

    win.refresh();
    win.drawDot(13, 3);
    win.drawDot(12, 4);
    win.drawDot(13, 5);
    win.drawDot(14, 4);
    win.drawRect(5, 10, 10, 4);
    win.update();
}
