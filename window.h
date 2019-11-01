#ifndef WINDOWM
#define WINDOWM

#include <string>

namespace cuiwin {

    class Window {

    public:
        Window(int width, int height);
        ~Window();
        int getWidth();
        int getHeight();
        void drawDot(int x, int y);
        void drawRect(int x0, int y0, int w, int h);
        void drawText(int x, int y, const char *s);
        void refresh();
        void update();

    private:
        void init();
        int width, height;
        char *buf;

    };

}


#endif
