G++ = g++

GAME_SRCS = $(wildcard game/*.c game/*.cpp)


make:
	make build
	make run


.PHONY: build
build: $(GAME_SRCS)
	make -C tetris
	make -C snake
	make -C helloworld
	$(G++) -o main main.cpp $(GAME_SRCS) $(wildcard build/*.o)


run:
	./main


test-window:
	$(G++) -o window_test test/window_test.cpp game/window.cpp
	./window_test


clean:
	rm -rf main *_test

