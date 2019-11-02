#include <iostream>
#include "tetris.h"

void printTetrimino(char pattern[5][5]) {
    for(int y = 0; y < 5; ++ y) {
        for(int x = 0; x < 5; ++ x)
            if(pattern[y][x])
                std::cout << "*";
            else
                std::cout << "-";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    for(int type = 0; type < 7; ++ type) {
        Tetrimino tmp(type);
        std::cout << type <<  std::endl;
        for(int idx = 0; idx < 5; ++ idx) {
            printTetrimino(tmp.block);
            tmp.rotate();
        }
    }
}

