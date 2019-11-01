G++ = g++


make:
	make build
	make run


build:
	$(G++) -o main main.cpp window.cpp kbhit.c


run:
	./main


test:
	@echo "Compile..."
	$(G++) -o window_test window_test.cpp window.cpp
	$(G++) -o game_test game_test.cpp window.cpp
	@echo "Exec..."
	./window_test
	./game_test
