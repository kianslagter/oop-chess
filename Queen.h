// queen piece class inherited from piece.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

class Queen : public Piece {
 private:
  int pieceValue = 9;
  // textures for piece
  static Texture blackQueen;
  static Texture whiteQueen;

 public:
  // constructor
  Queen(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteQueen();
      sprite.setTexture(LoadTextures::whiteQueen);  // white
    } else {
      LoadTextures::loadBlackQueen();
      sprite.setTexture(LoadTextures::blackQueen);  // black
    }
  }

  // gets legal moves for piece
  vector<Vector2f> getLegalMoves(int currentRow, int currentCol,
                                 vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // horizontal and vertical moves
    for (int i = 0; i < 8; ++i) {
      if (i != currentCol) {
        if (!isPathBlocked(currentRow, currentCol, currentRow, i, pieces)) {
          legalMoves.push_back(
              Vector2f(currentRow, i));  // Moves in the same row
        }
      }
      if (i != currentRow) {
        if (!isPathBlocked(currentRow, currentCol, i, currentCol, pieces)) {
          legalMoves.push_back(
              Vector2f(i, currentCol));  // Moves in the same column
        }
      }
    }

    // diagonal moves
    for (int i = -7; i <= 7; ++i) {
      if (i != 0) {
        int row = currentRow + i;
        int col = currentCol + i;
        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
          if (!isPathBlocked(currentRow, currentCol, row, col, pieces)) {
            legalMoves.push_back(Vector2f(row, col));  // main diagonal moves
          }
        }

        col = currentCol - i;
        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
          if (!isPathBlocked(currentRow, currentCol, row, col, pieces)) {
            legalMoves.push_back(Vector2f(row, col));  // second diagonal moves
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

    if (currentRow == targetRow) {  // horizontal move
      for (int col = currentCol + colDirection; col != targetCol;
           col += colDirection) {
        Vector2f position = getSquareCenter(currentRow, col);
        if (isPieceAtPosition(position, pieces)) {
          return true;
        }
      }
    } else if (currentCol == targetCol) {  // vertical move
      for (int row = currentRow + rowDirection; row != targetRow;
           row += rowDirection) {
        Vector2f position = getSquareCenter(row, currentCol);
        if (isPieceAtPosition(position, pieces)) {
          return true;
        }
      }
    } else {  // diagonal move
      for (int row = currentRow + rowDirection, col = currentCol + colDirection;
           row != targetRow; row += rowDirection, col += colDirection) {
        Vector2f position = getSquareCenter(row, col);
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
  string getName() override { return "Queen"; }

  // gets value of piece
  int getPieceValue() override { return pieceValue; }


  // destructor
  ~Queen() override{};
};
