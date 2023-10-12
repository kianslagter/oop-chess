#include <SFML/Graphics.hpp>

#include "drawBoard.h"
#include "loadTextures.h"
using namespace sf;

void setSpriteParameters(Sprite& sprite) {
  sprite.setOrigin(Vector2f(sprite.getTexture()->getSize().x / 2,
                            sprite.getTexture()->getSize().y / 2));
  sprite.setScale(Vector2f(0.375f, 0.375f));
}

Vector2f getClosestSquare(Vector2f pos) {
  int x = static_cast<int>(pos.x / 64.f);
  int y = static_cast<int>(pos.y / 64.f);

  return Vector2f((x * 64.f) + 32.f, (y * 64.f) + 32.f);
}

int main() {
  // load textures
  LoadTextures::loadTextures();

  // create window
  RenderWindow window(VideoMode(512, 512), "Texture Display");

  // create sprites for pieces
  Sprite blackKing(LoadTextures::blackKing);
  Sprite blackQueen(LoadTextures::blackQueen);

  // set parameters for sprites
  setSpriteParameters(blackKing);
  setSpriteParameters(blackQueen);

  // dragging pieces variables
  bool isDragging = false;
  Sprite* draggedSprite = nullptr;

  // create chess board
  Board board(Color(118, 150, 86), Color(238, 238, 210));

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {
        case Event::Closed:
          window.close();
          break;
        case Event::MouseButtonPressed:
          if (event.mouseButton.button == Mouse::Left) {
            if (blackKing.getGlobalBounds().contains(window.mapPixelToCoords(
                    Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
              isDragging = true;
              draggedSprite = &blackKing;
            } else if (blackQueen.getGlobalBounds().contains(
                           window.mapPixelToCoords(Vector2i(
                               event.mouseButton.x, event.mouseButton.y)))) {
              isDragging = true;
              draggedSprite = &blackQueen;
            }
          }
          break;
        case Event::MouseButtonReleased:
          if (event.mouseButton.button == Mouse::Left) {
            isDragging = false;
            if (draggedSprite != nullptr) {
              Vector2f newPos = getClosestSquare(draggedSprite->getPosition());
              draggedSprite->setPosition(newPos);
            }
          }
          break;
        case Event::MouseMoved:
          if (isDragging && draggedSprite != nullptr) {
            draggedSprite->setPosition(window.mapPixelToCoords(
                Vector2i(event.mouseMove.x, event.mouseMove.y)));
          }
          break;
        default:
          break;
      }
    }

    window.clear();

    // draw board
    window.draw(board);

    // draw sprites
    window.draw(blackKing);
    window.draw(blackQueen);

    window.display();
  }

  return 0;
}
