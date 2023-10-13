#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

class Pawn : public Piece {
 private:
  int pieceValue = 1;
  bool promotionCheck;
  static Texture blackPawn;
  static Texture whitePawn;

 public:
  Pawn(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhitePawn();
      sprite.setTexture(LoadTextures::whitePawn);  // white
    } else {
      LoadTextures::loadBlackPawn();
      sprite.setTexture(LoadTextures::blackPawn);  // black
    }
  }

  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Pawn"; }

  int getPieceValue() { return pieceValue; }

 // bool promotionCheck() {
 //   if (Colour == "white") return 1;
 // }
 // else {
 //   return 0;
  //}

  ~Pawn() override{};
};
