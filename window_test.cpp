#include <iostream>
#include "window.h"

int main() {
    cuiwin::Window win(50, 30);
    std::cout << win.getWidth() << " " << win.getHeight() << std::endl;
}
