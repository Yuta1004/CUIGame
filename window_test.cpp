#include <iostream>
#include "window.h"

int main() {
    mywindow::Window win(50, 30);
    std::cout << win.getWidth() << " " << win.getHeight() << std::endl;
}
