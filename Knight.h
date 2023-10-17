// knight piece class inherited from piece.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
#include "Piece.h"

class Knight : public Piece {
 private:
  int pieceValue = 3;
  // textures for piece
  static Texture blackKnight;
  static Texture whiteKnight;

 public:
  // constructor
  Knight(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteKnight();
      sprite.setTexture(LoadTextures::whiteKnight);  // white
    } else {
      LoadTextures::loadBlackKnight();
      sprite.setTexture(LoadTextures::blackKnight);  // black
    }
  }

  // gets legal moves for piece
  vector<Vector2f> getLegalMoves(int currentRow, int currentCol,
                                 vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // moves for L shape knight
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
      int row = currentRow + dx[i];
      int col = currentCol + dy[i];
      if (row >= 0 && row < 8 && col >= 0 && col < 8) {
        if (!isPieceAtPosition(Vector2f(row, col), pieces)) {
          legalMoves.push_back(Vector2f(row, col));
        }
      }
    }

    return legalMoves;
  }

// gets sprite of piece
  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Knight"; }

  int getPieceValue() override { return pieceValue; }

  ~Knight() override{};
};
