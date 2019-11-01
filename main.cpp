#include <unistd.h>
#include "window.h"

#define SEC 1000000
#define MIL 1000
#define MIC 1

int main() {
    int score = 0, line = 0, level = 1;
    char *s = (char*)malloc(15);

    // Window初期化
    cuiwin::Window win(55, 40);
    win.setChar('*');

    // メインループ
    while(1) {
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
        usleep(1*SEC);
    }

    // 後処理
    free(s);
}
