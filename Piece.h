#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "loadTextures.h"
using namespace std;
using namespace sf;

class Piece {
 private:
  int pieceValue;
  bool pieceColor;  // false is black, true is white
  bool hasMoved;    // to check two space move for pawn

 public:
 

  virtual string getName() = 0;

  virtual int getPieceValue() { return pieceValue; }

  virtual ~Piece(){};

  virtual movePiece(){};

  virtual Texture loadTexture(string str) {
    Texture tmp;
    if (!tmp.loadFromFile(str)) cout << "Error loading file\n";
    return tmp;
  }
};
