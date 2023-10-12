all: compile link

compile:
	g++ -c main.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include -DSFML_STATIC

link:
	g++ main.o -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main *.o
