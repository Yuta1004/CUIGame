#ifndef WINDOWM
#define WINDOWM

namespace cuiwin {

    class Window {

    public:
        Window(int width, int height);
        ~Window();
        int getWidth();
        int getHeight();
        void refresh();
        void draw();

    private:
        int width, height;
        char *buf;

    };

}


#endif
