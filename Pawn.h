#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

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

vector<Vector2f> getLegalMoves(int currentRow, int currentCol, vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // Determine the direction based on the color of the pawn
    int direction = (getColor() == true) ? -1 : 1;

    // Forward moves
    int row = currentRow + direction;  // Move in the direction of the pawn
    if (row >= 0 && row < 8 && !isPieceAtPosition(Vector2f(row, currentCol), pieces)) {
        legalMoves.push_back(Vector2f(row, currentCol));

        if (!hasMoved) {  // If it's the pawn's first move
            row = currentRow + 2 * direction;
            if (row >= 0 && row < 8 && !isPieceAtPosition(Vector2f(row, currentCol), pieces)) {
                legalMoves.push_back(Vector2f(row, currentCol));
            }
        }
    }

    // Diagonal captures
    if (isPieceAtPosition(Vector2f(currentRow + direction, currentCol), pieces)) {
        for (int col = currentCol - 1; col <= currentCol + 1; col += 2) {
            row = currentRow + direction;
            if (col >= 0 && col < 8 && isPieceAtPosition(Vector2f(row, col), pieces)) {
                legalMoves.push_back(Vector2f(row, col));
            }
        }
    }

    return legalMoves;
}




  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Pawn"; }

  int getPieceValue() { return pieceValue; }

  // bool promotionCheck() {
  //   if (Colour == "white") return 1;
  // }
  // else {
  //   return 0;
  //}

  ~Pawn() override{};
};
