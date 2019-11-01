#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include "window.h"

using namespace cuiwin;

Window::Window(int width, int height) {
    this->width = width;
    this->height = height;
}

int Window::getWidth() {
    return this->width;
}

int Window::getHeight() {
    return this->height;
}

void Window::draw() {
    // 高さ, 幅など
    int width = this->width;
    int height = this->height;
    char *buf = (char*)std::malloc(width+1);
    std::string hfline(width+2, '-');

    // 出力
    std::puts(hfline.c_str());
    for(int y = 0; y < height; ++ y) {
        std::strncpy(buf, "", width);
        std::printf("|%s|\n", buf);
    }
    std::puts(hfline.c_str());

    // 後処理
    free(buf);
}
