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

  Sprite& getSprite() override { return sprite; }

  string getName() override { return "King"; }

  ~King() override{};
};
