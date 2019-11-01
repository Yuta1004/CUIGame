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
    char *s = (char*)malloc(15);
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
            sprintf(s, "SCORE: %d", score);
            win.drawText(33, 5, s);
            sprintf(s, "LINE : %d", line);
            win.drawText(33, 7, s);
            sprintf(s, "LEVEL: %d", level);
            win.drawText(33, 9, s);

            // 画面更新
            win.update();
        }

        usleep(40*MIL);
    }

    free(s);
}

bool keyEvent() {
    if(!kbhit()) return false;

    switch(std::getchar()) {
    case 'q':
        exit(0);
    }
    return true;
}
