// rook piece class inherited from piece.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

class Rook : public Piece {
 private:
  int pieceValue = 5;
  // textures for piece
  static Texture blackRook;
  static Texture whiteRook;

 public:
  // constructor
  Rook(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteRook();
      sprite.setTexture(LoadTextures::whiteRook);  // white
    } else {
      LoadTextures::loadBlackRook();
      sprite.setTexture(LoadTextures::blackRook);  // black
    }
  }

  // gets legal moves for piece
  vector<Vector2f> getLegalMoves(int currentRow, int currentCol, vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // horizontal and vertical moves
    for (int i = 0; i < 8; ++i) {
      if (i != currentCol) {
        if (!isPathBlocked(currentRow, currentCol, currentRow, i, pieces)) {
          legalMoves.push_back(Vector2f(currentRow, i));  // Moves in the same row
        }
      }
      if (i != currentRow) {
        if (!isPathBlocked(currentRow, currentCol, i, currentCol, pieces)) {
          legalMoves.push_back(Vector2f(i, currentCol));  // Moves in the same column
        }
      }
    }
    return legalMoves;
}
  // checks if a pieces path of movement is blocked
   bool isPathBlocked(int currentRow, int currentCol, int targetRow, int targetCol, vector<Piece*>& pieces) override {
    int rowDirection = (targetRow - currentRow > 0) ? 1 : -1;
    int colDirection = (targetCol - currentCol > 0) ? 1 : -1;

    if (currentRow == targetRow) { // horizontal move
        for (int col = currentCol + colDirection; col != targetCol; col += colDirection) {
            Vector2f position = getSquareCenter(currentRow, col);
            if (isPieceAtPosition(position, pieces)) {
                return true;
            }
        }
    } else if (currentCol == targetCol) { // vertical move
        for (int row = currentRow + rowDirection; row != targetRow; row += rowDirection) {
            Vector2f position = getSquareCenter(row, currentCol);
            if (isPieceAtPosition(position, pieces)) {
                return true;
            }
        }
    } 
    return false;
}

  // gets sprite of piece
  Sprite& getSprite() override { return sprite; }

  // gets name of piece
  string getName() override { return "Rook"; }

  // gets value of piece
  int getPieceValue() override { return pieceValue; }

  // destructors
  ~Rook() override{};
};
