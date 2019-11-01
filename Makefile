G++ = g++


make:
	make build
	make run


build:
	$(G++) -o main main.cpp


run:
	./main
