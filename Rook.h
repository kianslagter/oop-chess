#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Rook : public Piece {
 private:
  int pieceValue = 5;

 public:
  string getName() override { return "Rook"; }

  int getPieceValue() { return pieceValue; }

  Rook(/* args */){};
  ~Rook() override{};
};