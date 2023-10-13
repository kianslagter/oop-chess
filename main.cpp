#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "drawBoard.h"
#include "loadTextures.h"
#include "nearestSquare.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "Queen.h"
using namespace sf;
using namespace std;

int main() {
  // create window
  RenderWindow window(VideoMode(512, 512), "OOP Chess");

  // add pieces to vector
  vector<Piece*> pieces;
  ChessBoard::initialiseChessBoard(pieces);

  // dragging pieces variables
  bool isDragging = false;
  Piece* draggedPiece = nullptr;

  // create chess board
  Board board(Color(238, 238, 210), Color(118, 150, 86));

while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case Event::Closed:
          window.close();
          break;
        case Event::MouseButtonPressed:
          if (event.mouseButton.button == Mouse::Left) {
            for (Piece* piece : pieces) {
              Sprite& sprite = piece->getSprite();
              if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(
                      Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
                isDragging = true;
                draggedPiece = piece;
                break;
              }
            }
          }
          break;
        case Event::MouseButtonReleased:
          if (event.mouseButton.button == Mouse::Left) {
            isDragging = false;
            if (draggedPiece != nullptr) {
              Vector2f newPos =
                  getClosestSquare(draggedPiece->getSprite().getPosition());
              draggedPiece->Piece::getSprite().setPosition(newPos);
            }
          }
          break;
        case Event::MouseMoved:
          if (isDragging && draggedPiece != nullptr) {
            draggedPiece->getSprite().setPosition(window.mapPixelToCoords(
                Vector2i(event.mouseMove.x, event.mouseMove.y)));
          }
          break;
        default:
          break;
      }
    }


    window.clear();

    // Draw the board
    window.draw(board);

    // Draw each piece
    for (Piece* piece : pieces) {
      window.draw(piece->getSprite());
    }

    window.display();
  }

  return 0;
}
