#include <unistd.h>
#include "window.h"

#define SEC 1000000
#define MIL 1000
#define MIC 1

int main() {
    cuiwin::Window win(50, 40);

    while(1) {
        win.refresh();
        win.update();
        usleep(1*SEC);
    }
}
