#include <unistd.h>
#include "window.h"

#define SEC 1000000
#define MIL 1000
#define MIC 1

int main() {
    // Window初期化
    cuiwin::Window win(50, 40);
    win.setChar('*');

    // メインループ
    while(1) {
        win.refresh();

        // 盤面の区切り
        win.setChar('|');
        win.drawRect(30, 0, 1, 40);

        // 画面更新
        win.update();
        usleep(1*SEC);
    }
}
