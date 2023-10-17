#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "ChessBoard.h"
#include "Piece.h"
#include "Queen.h"
#include "drawBoard.h"
#include "loadTextures.h"
#include "nearestSquare.h"
using namespace sf;
using namespace std;

int main() {
  ChessBoard ChessBoard;

  // create window
  RenderWindow window(VideoMode(512, 512), "OOP Chess");

  // add pieces to vector
  vector<Piece*> pieces;
  ChessBoard.initialiseChessBoard(pieces);

  // dragging pieces variables
  bool isDragging = false;
  Piece* draggedPiece = nullptr;
  Vector2f initialPos = {0, 0};

  // create chess board
  Board board(Color(238, 238, 210), Color(118, 150, 86));

  // Add a variable to keep track of turns
  bool isWhiteTurn = true;  // White goes first

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
                // Check if the piece being moved matches the current turn
                if ((piece->getColor() == true && isWhiteTurn) ||
                    (piece->getColor() == false && !isWhiteTurn)) {
                  isDragging = true;
                  draggedPiece = piece;
                  // save initial position
                  initialPos =
                      getClosestSquare(draggedPiece->getSprite().getPosition());
                } else {
                  // If it's not the turn of the piece's color, reset dragging
                  // variables
                  isDragging = false;
                  draggedPiece = nullptr;
                }
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
              ChessBoard.movePiece(pieces, draggedPiece, newPos, initialPos);
              // If the move was successful, switch the turn
              if (ChessBoard.moveSuccessful == true) {
                isWhiteTurn = !isWhiteTurn;
                ChessBoard.moveSuccessful = false;
              }
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

    if (ChessBoard.isKingTaken(
            true, pieces)) {  // Check if the white king has been taken
      cout << "Game over! Black wins!" << endl;
      break;
    } else if (ChessBoard.isKingTaken(
                   false, pieces)) {  // Check if the black king has been taken
      cout << "Game over! White wins!" << endl;
      break;
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
