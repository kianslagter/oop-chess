all: compile link

compile:
	g++ -c testDrawBoard.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include -DSFML_STATIC

link:
	g++ testDrawBoard.o -o testDrawBoard -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f testDrawBoard *.o