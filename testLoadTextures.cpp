#include <SFML/Graphics.hpp>
#include "loadTextures.h"
using namespace sf;



int main()
{
    // load textures
    LoadTextures::loadTextures();

    // create window
    RenderWindow window(VideoMode(800, 600), "Texture Display");

    // create sprites
    Sprite blackKing(LoadTextures::blackKing);
    Sprite blackQueen(LoadTextures::blackQueen);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        // draw sprites
        window.draw(blackKing);
        window.draw(blackQueen);

        window.display();
    }

    return 0;
}
