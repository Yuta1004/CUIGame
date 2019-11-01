#ifndef WINDOWM
#define WINDOWM

namespace mywindow {

    class Window {

    public:
        Window(int width, int height);
        int getWidth();
        int getHeight();

    private:
        int width, height;

    };

}


#endif
