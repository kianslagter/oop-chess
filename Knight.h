#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Knight : public Piece {
 private:
  int pieceValue = 3;

 public:
  string getName() override { return "Knight"; }

  int getPieceValue() { return pieceValue; }

  Knight(/* args */){};
  ~Knight() override{};
};