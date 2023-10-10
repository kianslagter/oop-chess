#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Queen : public Piece {
 private:
  int pieceValue = 9;

 public:
  string getName() override { return "Queen"; }

  int getPieceValue() { return pieceValue; }

  Queen(/* args */){};
  ~Queen() override{};
};