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
  static Texture blackKnight;
  static Texture whiteKnight;

 public:
  Knight(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteKnight();
      sprite.setTexture(LoadTextures::whiteKnight);  // white
    } else {
      LoadTextures::loadBlackKnight();
      sprite.setTexture(LoadTextures::blackKnight);  // black
    }
  }

  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Knight"; }

  int getPieceValue() { return pieceValue; }

  ~Knight() override{};
};
