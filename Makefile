G++ = g++


make:
	make build
	make run


build:
	$(G++) -o main main.cpp game/game.cpp game/window.cpp game/kbhit.c tetris/tetris.cpp tetris/tetrimino.cpp helloworld/hello.cpp


run:
	./main


test-window:
	$(G++) -o window_test test/window_test.cpp game/window.cpp
	./window_test


clean:
	rm -rf main *_test
