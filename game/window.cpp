#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <string>
#include "window.h"

using namespace yngame;

Window::Window(int width, int height) {
    this->width = width;
    this->height = height;
    this->buf = (char*)std::malloc(width*height);
    this->drawC = '*';
    init();
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

void Window::init() {
    std::cout << std::string(height, '\n');
}

void Window::setChar(char c) {
    this->drawC = c;
}

void Window::drawDot(int x, int y) {
    if(0 <= x && x < width && 0 <= y && y < height)
        this->buf[x+y*width] = drawC;
}

void Window::drawRect(int x0, int y0, int w, int h) {
    for(int y = y0; y < y0+h; ++ y)
        for(int x = x0; x< x0+w; ++ x)
            drawDot(x, y);
}

void Window::drawText(int x, int y, const char *fmt, ...) {
    // 文字列構築
    std::va_list va;
    va_start(va, fmt);
    char *s = (char*)malloc(30);
    std::vsprintf(s, fmt, va);
    va_end(va);

    int size = std::min(width-x, (int)std::strlen(s));
    for(int idx = 0; idx < size; ++ idx)
        buf[x+y*width+idx] = s[idx];
}

void Window::refresh() {
    for(int idx = 0; idx < width*height; ++ idx)
        this->buf[idx] = ' ';
}

void Window::update() {
    // 行ごとのバッファ etc
    char *lbuf = (char*)std::malloc(width+1);
    std::string hfline(width+2, '-');

    // カーソル位置合わせ
    std::printf("\e[%dF\e[0J", height+2);

    // 出力
    std::puts(hfline.c_str());
    for(int y = 0; y < height; ++ y) {
        std::strncpy(lbuf, buf+y*width, width);
        lbuf[width] = '\0';
        std::printf("|%s|\n", lbuf);
    }
    std::puts(hfline.c_str());

    // 後処理
    free(lbuf);
}
