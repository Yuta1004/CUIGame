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
    this->buf = (char*)std::malloc(width*height);
    refresh();
}

Window::~Window() {
    free(buf);
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}

void Window::drawDot(int x, int y) {
    if(0 <= x && x < width && 0 <= y && y < height)
        this->buf[x+y*width] = '*';
}

void Window::refresh() {
    for(int idx = 0; idx < width*height; ++ idx)
        this->buf[idx] = ' ';
}

void Window::update() {
    // 行ごとのバッファ etc
    char *lbuf = (char*)std::malloc(width+1);
    std::string hfline(width+2, '-');

    // 出力
    std::puts(hfline.c_str());
    for(int y = 0; y < height; ++ y) {
        std::strncpy(lbuf, buf+y*width, width);
        std::printf("|%s|\n", lbuf);
    }
    std::puts(hfline.c_str());

    // 後処理
    free(lbuf);
}
