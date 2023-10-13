all: compile link

compile:
	g++ -std=c++11 -c main.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include -DSFML_STATIC

link:
	g++ -std=c++11 main.o -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main *.o
