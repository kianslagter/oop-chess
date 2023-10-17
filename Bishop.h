// bishop piece class inherited from piece.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

class Bishop : public Piece {
 private:
  int pieceValue = 3;
  // textures for piece
  static Texture blackBishop;
  static Texture whiteBishop;

 public:
 // constructor
  Bishop(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteBishop();
      sprite.setTexture(LoadTextures::whiteBishop);  // white
    } else {
      LoadTextures::loadBlackBishop();
      sprite.setTexture(LoadTextures::blackBishop);  // black
    }
  }

  // gets legal moves for piece
  vector<Vector2f> getLegalMoves(int currentRow, int currentCol,
                                 vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // diagonal moves
    for (int i = -7; i <= 7; ++i) {
      if (i != 0) {
        int row = currentRow + i;
        int col = currentCol + i;
        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
          if (!isPathBlocked(currentRow, currentCol, row, col, pieces)) {
            legalMoves.push_back(
                Vector2f(row, col));  // main diagonal moves
          }
        }
        col = currentCol - i;
        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
          if (!isPathBlocked(currentRow, currentCol, row, col, pieces)) {
            legalMoves.push_back(
                Vector2f(row, col));  // second diagonal moves
          }
        }
      }
    }

    return legalMoves;
  }

  // checks if a pieces path of movement is blocked
  bool isPathBlocked(int currentRow, int currentCol, int targetRow,
                     int targetCol, vector<Piece*>& pieces) override {
    int rowDirection = (targetRow - currentRow > 0) ? 1 : -1;
    int colDirection = (targetCol - currentCol > 0) ? 1 : -1;
    for (int row = currentRow + rowDirection, col = currentCol + colDirection;
         row != targetRow; row += rowDirection, col += colDirection) {
      Vector2f position = getSquareCenter(row, col);
      if (isPieceAtPosition(position, pieces)) {
        return true;
      }
    }

    return false;
  }


  // gets sprite of piece
  Sprite& getSprite() override { return sprite; }

  // gets name of piece
  string getName() override { return "Bishop"; }

  // gets value of piece
  int getPieceValue() override { return pieceValue; }

  // destructor
  ~Bishop() override{};
};
