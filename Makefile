G++ = g++


make:
	make build
	make run


build:
	$(G++) -o main main.cpp window.cpp kbhit.c


run:
	./main


test:
	$(G++) -o window_test window_test.cpp window.cpp
	./window_test
