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
        void update();

    private:
        int width, height;
        char *buf;

    };

}


#endif
