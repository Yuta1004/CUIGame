#include <iostream>
#include "window.h"

int main() {
    cuiwin::Window win(40, 30);
    std::cout << "Width : " << win.getWidth() << std::endl;
    std::cout << "Height : " << win.getHeight() << std::endl;
    win.refresh();
    win.draw();

}
