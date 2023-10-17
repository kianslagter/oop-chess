// main file for the entire chess project
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
  // create a chessboard instance
  ChessBoard ChessBoard;

  // create sfml window
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

  // variable for which players turn it is
  bool isWhiteTurn = true;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case Event::Closed:
          window.close();
          break;
        case Event::MouseButtonPressed:// what happens when mouse is clicked
          if (event.mouseButton.button == Mouse::Left) {
            for (Piece* piece : pieces) {
              Sprite& sprite = piece->getSprite();
              if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(
                      Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
                // check if right player is moving piece
                if ((piece->getColor() == true && isWhiteTurn) ||
                    (piece->getColor() == false && !isWhiteTurn)) {
                  isDragging = true;
                  draggedPiece = piece;
                  // save initial position
                  initialPos =
                      getClosestSquare(draggedPiece->getSprite().getPosition());
                } else {
                  isDragging = false;
                  draggedPiece = nullptr;
                }
                break;
              }
            }
          }
          break;

        case Event::MouseButtonReleased: // what happens when mouse is released
          if (event.mouseButton.button == Mouse::Left) {
            isDragging = false;
            if (draggedPiece != nullptr) {
              Vector2f newPos =
                  getClosestSquare(draggedPiece->getSprite().getPosition());
              ChessBoard.movePiece(pieces, draggedPiece, newPos, initialPos);
              // if move complete then other players turn
              if (ChessBoard.moveSuccessful == true) {
                isWhiteTurn = !isWhiteTurn;
                ChessBoard.moveSuccessful = false;
              }
            }
          }
          break;
        case Event::MouseMoved: // for mouse movements
          if (isDragging && draggedPiece != nullptr) {
            draggedPiece->getSprite().setPosition(window.mapPixelToCoords(
                Vector2i(event.mouseMove.x, event.mouseMove.y)));
          }
          break;
        default:
          break;
      }
    }

    // check if either king has been taken
    if (ChessBoard.isKingTaken(
            true, pieces)) {  
      cout << "Game over! Black wins!" << endl;
      break;
    } else if (ChessBoard.isKingTaken(
                   false, pieces)) { 
      cout << "Game over! White wins!" << endl;
      break;
    }

    window.clear();

    // draw the board
    window.draw(board);

    // draw each piece
    for (Piece* piece : pieces) {
      window.draw(piece->getSprite());
    }

    window.display();
  }

  return 0;
}
