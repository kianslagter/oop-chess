#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "gameEntity.h"
#include "loadTextures.h"
#include "nearestSquare.h"
using namespace std;
using namespace sf;

class Piece : public GameEntity {
 private:
  int pieceValue;
  bool pieceColor;  // false is black, true is white

 public:
  bool hasMoved;

  Piece(bool pieceColor) : pieceColor(pieceColor), hasMoved(false) {
    this->pieceColor = pieceColor;
    if (pieceColor == true) {
      // white
    } else {
      // black
    }
  }

  virtual vector<Vector2f> getLegalMoves(int currentRow, int currentCol, vector<Piece*>& pieces) {
    return vector<Vector2f>();
  }


bool isPieceAtPosition(Vector2f position, vector<Piece*>& pieces) {
    for (Piece* piece : pieces) {
        if (piece->getSprite().getPosition() == position) {
            return true;
        }
    }
    return false;
}
  virtual bool isPathBlocked(int currentRow, int currentCol, int targetRow, int targetCol, vector<Piece*>& pieces) {
    return false;
  }

  Piece* getPieceAtPosition(Vector2f position, vector<Piece*>& pieces) {
    for (Piece* piece : pieces) {
        if (getClosestSquare(piece->getSprite().getPosition()) == position) {
            return piece;
        }
    }
    return nullptr;
}


  void setPiecePosition(int row, int col) {
    Vector2f position = getSquareCenter(row, col);
    sprite.setPosition(position);
  }

  int getRow() {
    Vector2f position = this->getSprite().getPosition();
    int row = position.y / 64;
    return row;
}

int getCol() {
    Vector2f position = this->getSprite().getPosition();
    int col = position.x / 64;

    return col;
}

  bool getColor() { return pieceColor; }

  virtual string getName() = 0;

  virtual int getPieceValue() { return pieceValue; }

};
