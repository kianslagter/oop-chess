// pawn piece class inherited from piece.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "ChessBoard.h"
#include "Piece.h"
#include "Queen.h"

class Pawn : public Piece {
 private:
  int pieceValue = 1;
  bool promotionCheck;
  // textures for piece
  static Texture blackPawn;
  static Texture whitePawn;

 public:
  // constructor
  Pawn(bool pieceColor) : Piece(pieceColor) {
    if (pieceColor == true) {
      LoadTextures::loadWhitePawn();
      sprite.setTexture(LoadTextures::whitePawn);  // white
    } else {
      LoadTextures::loadBlackPawn();
      sprite.setTexture(LoadTextures::blackPawn);  // black
    }
  }

  // gets legal moves for piece
  vector<Vector2f> getLegalMoves(int currentRow, int currentCol,
                                 vector<Piece*>& pieces) override {
    vector<Vector2f> legalMoves;

    // up or down based on colour
    int direction = (getColor() == true) ? -1 : 1;

    // capture diagnal
    int capture_dx[] = {1 * direction, 1 * direction};
    int capture_dy[] = {-1, 1};

    // forward moves
    int forwardRow = currentRow + direction;
    if (forwardRow >= 0 && forwardRow < 8 &&
        !isPieceAtPosition(Vector2f(forwardRow, currentCol), pieces)) {
      legalMoves.push_back(Vector2f(forwardRow, currentCol));

      if (!hasMoved) {  // for first move
        forwardRow = currentRow + 2 * direction;
        if (forwardRow >= 0 && forwardRow < 8 &&
            !isPieceAtPosition(Vector2f(forwardRow, currentCol), pieces)) {
          legalMoves.push_back(Vector2f(forwardRow, currentCol));
        }
      }
    }

    // check for capture
    for (int i = 0; i < 2; ++i) {
      int captureRow = currentRow + capture_dx[i];
      int captureCol = currentCol + capture_dy[i];
      if (captureRow >= 0 && captureRow < 8 && captureCol >= 0 &&
          captureCol < 8) {
        if (isPieceAtPosition(Vector2f(captureRow, captureCol), pieces)) {
          legalMoves.push_back(Vector2f(captureRow, captureCol));
        }
      }
    }

    return legalMoves;
  }

  // gets sprite of piece
  Sprite& getSprite() override { return sprite; }

  // gets name of piece
  string getName() override { return "Pawn"; }

  // gets value of piece
  int getPieceValue() override { return pieceValue; }


 // static void promotePawn(vector<Piece*>& pieces, int row, int col,
 //                         bool color) {
 //   int pieceIndex = getPieceIndexAtPosition(pieces, Vector2f(row, col));
    // find pawn in vector
 //   for (int i = 0; i < pieces.size(); ++i) {
      // delete the pawn
  //    delete pieces[i];
    //  pieces.erase(pieces.begin() + pieceIndex);
      // replace with queen
      //pieces[i] = new Queen(color);
  //    Vector2f position = getSquareCenter(row, col);
  //    pieces[i]->getSprite().setPosition(position);
   //   LoadTextures::setSpriteParameters(pieces[i]->getSprite());
     // break;
   // }
  //}

  ~Pawn() override{};
};
