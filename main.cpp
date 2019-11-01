#include <iostream>
#include <unistd.h>
#include "window.h"
#include "kbhit.h"

#define SEC 1000000
#define MIL 1000
#define MIC 1

bool keyEvent();

int main() {
    // 初期化
    long frameCnt = 0;
    int score = 0, line = 0, level = 1;
    char *s = (char*)malloc(15);
    cuiwin::Window win(55, 40);
    win.setChar('*');

    // メインループ
    while(1) {
        keyEvent();

        if(frameCnt % 40 == 0) {
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

        // 次フレームまで待機
        usleep(25*MIL);
        ++ frameCnt;
    }

    // 後処理
    free(s);
}

bool keyEvent() {
    bool result = true;
    if(kbhit()) {
        switch(std::getchar()) {
        case 'q':
            exit(0);

        default:
            result = false;
            break;
        }
    }
    return result;
}
