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
  static Texture blackRook;
  static Texture whiteRook;

 public:
  Rook(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteRook();
      sprite.setTexture(LoadTextures::whiteRook);  // white
    } else {
      LoadTextures::loadBlackRook();
      sprite.setTexture(LoadTextures::blackRook);  // black
    }
  }

  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Rook"; }

  int getPieceValue() { return pieceValue; }

  ~Rook() override{};
};
