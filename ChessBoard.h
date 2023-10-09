#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"

class ChessBoard {
 private:
  Piece* board[8][8];
  int whiteEval;
  int blackEval;
  int eval;
  int moveCount;

 public:
  ChessBoard() {
    // put pieces on board
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (i == 0 || i == 7) {
          if (j == 0 || j == 7) {
            board[i][j] = new Rook();
          } else if (j == 1 || j == 6) {
            board[i][j] = new Knight();
          } else if (j == 2 || j == 5) {
            board[i][j] = new Bishop();
          } else if (j == 3) {
            board[i][j] = new Queen();
          } else {
            board[i][j] = new King();
          }
        } else if (i == 1 || i == 6) {
          board[i][j] = new Pawn();

        } else {
          board[i][j] = nullptr;  // empty squares on board
        }
      }
    }
  }

  // destructor
  ~ChessBoard() {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        delete board[i][j];
      }
    }
  }

  // display board function
  void printBoard() {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cout << board[i][j] << ' ';
      }
      cout << endl;
    }
  }

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
