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
