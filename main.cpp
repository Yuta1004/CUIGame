#include <iostream>
#include <ctime>
#include <unistd.h>
#include "window.h"
#include "kbhit.h"

#define SEC 1000000
#define MIL 1000
#define MIC 1

bool keyEvent();

int main() {
    // 初期化
    long befTime = 0;
    int score = 0, line = 0, level = 1;
    cuiwin::Window win(55, 40);

    // メインループ
    while(1) {
        bool keyResult= keyEvent();
        long nowTime = std::time(nullptr);

        if(keyResult || nowTime-befTime > 0) {
            // 状態更新
            befTime = std::time(nullptr);
            win.refresh();

            // 盤面の区切り
            win.setChar('|');
            win.drawRect(30, 0, 1, 40);

            // 各種情報
            win.drawText(33, 5, "SCORE : %d", score);
            win.drawText(33, 7, "LINE : %d", line);
            win.drawText(33, 9, "LEVEL : %d", level);

            // 画面更新
            win.update();
        }

        usleep(40*MIL);
    }
}

bool keyEvent() {
    if(!kbhit()) return false;

    switch(std::getchar()) {
    case 'q':
        exit(0);
    }
    return true;
}
