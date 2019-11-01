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
    this->refresh();
}

Window::~Window() {
    free(buf);
}

int Window::getWidth() {
    return this->width;
}

int Window::getHeight() {
    return this->height;
}

void Window::drawDot(int x, int y) {
    if(0 <= x && x < this->width && 0 <= y && y < this->height)
        this->buf[x+y*this->width] = '*';
}

void Window::refresh() {
    int width = this->width;
    int height = this->height;
    for(int idx = 0; idx < width*height; ++ idx)
        this->buf[idx] = ' ';
}

void Window::update() {
    // 高さ, 幅など
    int width = this->width;
    int height = this->height;
    char *lbuf = (char*)std::malloc(width+1);
    std::string hfline(width+2, '-');

    // 出力
    std::puts(hfline.c_str());
    for(int y = 0; y < height; ++ y) {
        std::strncpy(lbuf, this->buf+y*width, width);
        std::printf("|%s|\n", lbuf);
    }
    std::puts(hfline.c_str());

    // 後処理
    free(lbuf);
}
