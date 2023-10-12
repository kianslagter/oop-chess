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

 public:
  static Texture whiteKnight;
  static Texture blackKnight;

  Texture loadTexture

  string getName() override { return "Knight"; }

  void movePiece() override {
    // game logic for legal moves
  }
};
