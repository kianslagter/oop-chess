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
  static Texture blackBishop;
  static Texture whiteBishop;

 public:
  Bishop(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhiteBishop();
      sprite.setTexture(LoadTextures::whiteBishop);  // white
    } else {
      LoadTextures::loadBlackBishop();
      sprite.setTexture(LoadTextures::blackBishop);  // black
    }
  }

  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Bishop"; }

  int getPieceValue() { return pieceValue; }

  ~Bishop() override{};
};
