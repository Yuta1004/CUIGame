#include <iostream>
#include "window.h"

int main() {
    cuiwin::Window win(20, 10);
    std::cout << "Width : " << win.getWidth() << std::endl;
    std::cout << "Height : " << win.getHeight() << std::endl;
    win.draw();

}
