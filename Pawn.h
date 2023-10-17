#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"
#include "Queen.h"
#include "ChessBoard.h"

class Pawn : public Piece {
 private:
  int pieceValue = 1;
  bool promotionCheck;
  static Texture blackPawn;
  static Texture whitePawn;

 public:
  Pawn(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhitePawn();
      sprite.setTexture(LoadTextures::whitePawn);  // white
    } else {
      LoadTextures::loadBlackPawn();
      sprite.setTexture(LoadTextures::blackPawn);  // black
    }
  }

  vector<Vector2f> getLegalMoves(int currentRow, int currentCol,
                                 vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // Determine the direction based on the color of the pawn
    int direction = (getColor() == true) ? -1 : 1;

    // Forward moves
    int row = currentRow + direction;  // Move in the direction of the pawn
    if (row >= 0 && row < 8 &&
        !isPieceAtPosition(Vector2f(row, currentCol), pieces)) {
      legalMoves.push_back(Vector2f(row, currentCol));

      if (!hasMoved) {  // If it's the pawn's first move
        row = currentRow + 2 * direction;
        if (row >= 0 && row < 8 &&
            !isPieceAtPosition(Vector2f(row, currentCol), pieces)) {
          legalMoves.push_back(Vector2f(row, currentCol));
        }
      }
    }

    // Diagonal captures
    if (isPieceAtPosition(Vector2f(currentRow + direction, currentCol),
                          pieces)) {
      for (int col = currentCol - 1; col <= currentCol + 1; col += 2) {
        row = currentRow + direction;
        if (col >= 0 && col < 8 &&
            isPieceAtPosition(Vector2f(row, col), pieces)) {
          legalMoves.push_back(Vector2f(row, col));
        }
      }
    }
    return legalMoves;
  }

  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Pawn"; }

  int getPieceValue() { return pieceValue; }

  static void promotePawn(vector<Piece*>& pieces,
                          int row, int col, bool color) {
    // Find the pawn in the pieces vector
    for (int i = 0; i < pieces.size(); ++i) {
      if (pieces[i]->getRow() == row && pieces[i]->getCol() == col) {
        // Delete the pawn
        delete pieces[i];

        // Replace the pawn with a new queen
        pieces[i] = new Queen(color);
        Vector2f position = getSquareCenter(row, col);
        pieces[i]->getSprite().setPosition(position);

        break;
      }
    }
  }

  ~Pawn() override{};
};
