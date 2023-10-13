#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"

class ChessBoard {
 private:
  int whiteEval;
  int blackEval;
  int eval;
  int moveCount;

 public:
  static void initialiseChessBoard(vector<Piece*>& pieces) {
    // create white pieces
    pieces.push_back(new Queen(true));
    pieces.push_back(new King(true));
    pieces.push_back(new Bishop(true));
    pieces.push_back(new Bishop(true));
    pieces.push_back(new Knight(true));
    pieces.push_back(new Knight(true));
    pieces.push_back(new Rook(true));
    pieces.push_back(new Rook(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));
    pieces.push_back(new Pawn(true));

    // create black pieces
    pieces.push_back(new Queen(false));
    pieces.push_back(new King(false));
    pieces.push_back(new Bishop(false));
    pieces.push_back(new Bishop(false));
    pieces.push_back(new Knight(false));
    pieces.push_back(new Knight(false));
    pieces.push_back(new Rook(false));
    pieces.push_back(new Rook(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));
    pieces.push_back(new Pawn(false));

    // count of pieces on the board
    int whitePawnCount = 0;
    int blackPawnCount = 0;
    int whiteBishopCount = 0;
    int blackBishopCount = 0;
    int whiteKnightCount = 0;
    int blackKnightCount = 0;
    int whiteRookCount = 0;
    int blackRookCount = 0;

    // Set initial positions for each piece
    for (Piece* piece : pieces) {
      if (piece->getName() == "Queen") {
        if (piece->getColor() == true) {  // white queen
          Vector2f position = getSquareCenter(7, 3);
          piece->getSprite().setPosition(position);
        } else {  // black queen
          Vector2f position = getSquareCenter(0, 3);
          piece->getSprite().setPosition(position);
        }
      }

      if (piece->getName() == "King") {
        if (piece->getColor() == true) {  // white king
          Vector2f position = getSquareCenter(7, 4);
          piece->getSprite().setPosition(position);
        } else {  // black king
          Vector2f position = getSquareCenter(0, 4);
          piece->getSprite().setPosition(position);
        }
      }

      if (piece->getName() == "Pawn") {
        if (piece->getColor() == true) {  // white pawn
          Vector2f position = getSquareCenter(6, whitePawnCount);
          piece->getSprite().setPosition(position);
          whitePawnCount++;
        } else {  // black pawn
          Vector2f position = getSquareCenter(1, blackPawnCount);
          piece->getSprite().setPosition(position);
          blackPawnCount++;
        }
      }

      if (piece->getName() == "Bishop") {
        if (piece->getColor() == true) {  // white bishop
          Vector2f position = getSquareCenter(7, (whiteBishopCount + 2));
          piece->getSprite().setPosition(position);
          whiteBishopCount = whiteBishopCount + 3;
        } else {  // black bishop
          Vector2f position = getSquareCenter(0, (blackBishopCount + 2));
          piece->getSprite().setPosition(position);
          blackBishopCount = blackBishopCount + 3;
        }
      }

      if (piece->getName() == "Knight") {
        if (piece->getColor() == true) {  // white knight
          Vector2f position = getSquareCenter(7, (whiteKnightCount + 1));
          piece->getSprite().setPosition(position);
          whiteKnightCount = whiteKnightCount + 5;
        } else {  // black knight
          Vector2f position = getSquareCenter(0, (blackKnightCount + 1));
          piece->getSprite().setPosition(position);
          blackKnightCount = blackKnightCount + 5;
        }
      }

      if (piece->getName() == "Rook") {
        if (piece->getColor() == true) {  // white rook
          Vector2f position = getSquareCenter(7, whiteRookCount);
          piece->getSprite().setPosition(position);
          whiteRookCount = whiteRookCount + 7;
        } else {  // black rook
          Vector2f position = getSquareCenter(0, blackRookCount);
          piece->getSprite().setPosition(position);
          blackRookCount = blackRookCount + 7;
        }
      }

      LoadTextures::setSpriteParameters(piece->getSprite());
    }
  }

  // destructor
  ~ChessBoard(){};

  void setWhiteEval() {
    whiteEval = 0;  // place holder
  }

  void setBlackEval() {
    blackEval = 0;  // place holder
  }

  void setEval() { eval = whiteEval - blackEval; }

  int getEval() { return eval; }

  void displayEval() { cout << "Current Eval:" << getEval() << endl; }

  void displayMove() {
    if (moveCount % 2 == 0) {
      cout << "Move: " << (moveCount + 1) << endl
           << "White"
           << "to play." << endl;

    } else {
      cout << "Move: " << (moveCount + 1) << endl
           << "Black"
           << "to play." << endl;
    }
  }
};
