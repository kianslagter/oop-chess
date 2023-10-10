#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Pawn : public Piece {
 private:
  int pieceValue = 1;
  string type = "Pawn";
  bool promotionCheck;
  string Colour;

 public:
  string getName() override { return type; }

  int getPieceValue() { return pieceValue; }

  bool promotionCheck() {
    if (Colour == "white") return 1;
  }
  else {
    return 0;
  }

  Pawn(/* args */){};
  ~Pawn() override{};
};