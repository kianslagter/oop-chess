#include "drawBoard.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // create SFML window
    RenderWindow window(VideoMode(512, 512), "Chess Board");

    // create board
    Board board();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(board);
        window.display();
    }

    return 0;
}
