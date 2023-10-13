#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "loadTextures.h"
using namespace std;
using namespace sf;
#include "Piece.h"

class Queen : public Piece {
 private:
  int pieceValue = 9;
  static Texture blackQueen;
  static Texture whiteQueen;

 public:

 Queen(bool pieceColor) : Piece(pieceColor){
        if (pieceColor == true){
          LoadTextures::loadWhiteQueen();
          sprite.setTexture(LoadTextures::whiteQueen);// white
        }
        else{
            LoadTextures::loadBlackQueen();
            sprite.setTexture(LoadTextures::blackQueen);// black
        }
   
    }
    
  Sprite& getSprite() override { return sprite; }

  string getName() override { return "Queen"; }

  int getPieceValue() { return pieceValue; }

  ~Queen() override{};
};
