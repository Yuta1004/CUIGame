G++ = g++


make:
	make build
	make run


build:
	$(G++) -o main main.cpp game.cpp window.cpp kbhit.c tetris/tetris.cpp tetris/tetrimino.cpp


run:
	./main


test-window:
	$(G++) -o window_test window_test.cpp window.cpp
	./window_test


test-game:
	$(G++) -o game_test game_test.cpp window.cpp
	./game_test

clean:
	rm -rf main *_test
