#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <array>
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
};
