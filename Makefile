G++ = g++


make:
	make build
	make run


build:
	$(G++) -o main main.cpp window.cpp kbhit.c gamemanager.cpp tetris.cpp


run:
	./main


test-window:
	$(G++) -o window_test window_test.cpp window.cpp
	./window_test


test-game:
	$(G++) -o game_test game_test.cpp window.cpp
	./game_test


test-gameman:
	$(G++) -o gamemanager_test gamemanager_test.cpp window.cpp gamemanager.cpp kbhit.c
	./gamemanager_test


test-tetrimino:
	$(G++) -o tetrimino_test tetrimino_test.cpp tetrimino.cpp
	./tetrimino_test


clean:
	rm -rf main *_test
