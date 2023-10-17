#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

class King : public Piece {
 private:
  static Texture blackKing;
  static Texture whiteKing;

 public:
  King(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteKing();
      sprite.setTexture(LoadTextures::whiteKing);  // white
    } else {
      LoadTextures::loadBlackKing();
      sprite.setTexture(LoadTextures::blackKing);  // black
    }
  }

vector<Vector2f> getLegalMoves(int currentRow, int currentCol, vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // Moves in all eight directions
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i != 0 || j != 0) { // Exclude the current square
                int row = currentRow + i;
                int col = currentCol + j;
                if (row >= 0 && row < 8 && col >= 0 && col < 8) {
                    if (!isPieceAtPosition(Vector2f(row, col), pieces)) {
                        legalMoves.push_back(Vector2f(row, col));
                    }
                }
            }
        }
    }

    return legalMoves;
}



  Sprite& getSprite() override { return sprite; }

  string getName() override { return "King"; }

  ~King() override{};
};
