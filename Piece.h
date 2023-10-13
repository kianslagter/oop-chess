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

   Sprite sprite;
 
    Piece(bool pieceColor): pieceColor(pieceColor) {
        this->pieceColor = pieceColor;
        if (pieceColor == true){
            // white
        }
        else{
           // black
        }
   
    }

void setPiecePosition(int row, int col) {
    Vector2f position = getSquareCenter(row, col);
    sprite.setPosition(position);
}



    virtual Sprite& getSprite() {return sprite;}

    bool getColor() {return pieceColor; }

    void draw(RenderWindow& window) const {
        window.draw(sprite);
    }




  virtual string getName() = 0;

  int getPieceValue() { return pieceValue; }

  virtual ~Piece(){};
};
