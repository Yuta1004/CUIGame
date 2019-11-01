#ifndef WINDOWM
#define WINDOWM

namespace cuiwin {

    class Window {

    public:
        Window(int width, int height);
        int getWidth();
        int getHeight();
        void draw();

    private:
        int width, height;

    };

}


#endif
