// primary piece class which all other pieces inherit from. contains most
// functions for piece related actions
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
  bool hasMoved; // for if the pawn has moved yet to allow two space move

  // constructor
  Piece(bool pieceColor) : pieceColor(pieceColor), hasMoved(false) {
    this->pieceColor = pieceColor;
    if (pieceColor == true) {
      // white
    } else {
      // black
    }
  }

  // default legal moves
  virtual vector<Vector2f> getLegalMoves(int currentRow, int currentCol,
                                         vector<Piece*>& pieces) {
    return vector<Vector2f>();
  }

  // checks if there is a piece at certain square on board
  bool isPieceAtPosition(Vector2f position, vector<Piece*>& pieces) {
    for (Piece* piece : pieces) {
      if (piece->getSprite().getPosition() == position) {
        return true;
      }
    }
    return false;
  }

  // checks if a pieces path of movement is blocked
  virtual bool isPathBlocked(int currentRow, int currentCol, int targetRow,
                             int targetCol, vector<Piece*>& pieces) {
    return false;
  }
 
  // gets a piece from a certain position
  Piece* getPieceAtPosition(Vector2f position, vector<Piece*>& pieces) {
    for (Piece* piece : pieces) {
      if (getClosestSquare(piece->getSprite().getPosition()) == position) {
        return piece;
      }
    }
    return nullptr;
  }

  // gets row of piece
  int getRow() {
    Vector2f position = this->getSprite().getPosition();
    int row = position.y / 64;
    return row;
  }

  // gets column of piece
  int getCol() {
    Vector2f position = this->getSprite().getPosition();
    int col = position.x / 64;

    return col;
  }

  // gets color of piece
  bool getColor() { return pieceColor; }

  // gets name of piece
  virtual string getName() = 0;

  // gets value of piece
  virtual int getPieceValue() { return pieceValue; }
};
