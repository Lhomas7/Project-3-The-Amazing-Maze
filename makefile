#this is the makefile to compile, run, and clean the maze project
#the output is in SDL and the out file will be placed in the views folder.

compile:
	g++ Controller/main.cpp -I /opt/homebrew/include/SDL2 -L /opt/homebrew/lib -lSDL2
	mv a.out view/a.out

run:
	./view/a.out

clean:
	rm view/a.out

