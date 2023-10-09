#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Bishop : public Piece {
 private:
  int pieceValue = 3;

 public:
  string getName() override { return "Bishop"; }

  int getPieceValue() { return pieceValue; }
  
  Bishop(/* args */){};
  ~Bishop() override{};
};