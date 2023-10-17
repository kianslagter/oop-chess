#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class LoadTextures {
 public:
  static Texture blackKing;
  static Texture blackQueen;
  static Texture blackRook;
  static Texture blackKnight;
  static Texture blackBishop;
  static Texture blackPawn;

  static Texture whiteKing;
  static Texture whiteQueen;
  static Texture whiteRook;
  static Texture whiteKnight;
  static Texture whiteBishop;
  static Texture whitePawn;

  static void loadBlackKing() {
    if (!blackKing.loadFromFile(
            "oop-chess/Textures/b_king.png"))
      cout << "Could not load texture\n";
  }

  static void loadBlackQueen() {
    if (!blackQueen.loadFromFile(
            "oop-chess/Textures/b_queen.png"))
      cout << "Could not load texture\n";
  }

  static void loadBlackRook() {
    if (!blackRook.loadFromFile(
            "oop-chess/Textures/b_rook.png"))
      cout << "Could not load texture\n";
  }

  static void loadBlackKnight() {
    if (!blackKnight.loadFromFile(
            "oop-chess/Textures/b_knight.png"))
      cout << "Could not load texture\n";
  }

  static void loadBlackBishop() {
    if (!blackBishop.loadFromFile(
            "oop-chess/Textures/b_bishop.png"))
      cout << "Could not load texture\n";
  }

  static void loadBlackPawn() {
    if (!blackPawn.loadFromFile(
            "oop-chess/Textures/b_pawn.png"))
      cout << "Could not load texture\n";
  }

    static void loadWhiteKing() {
    if (!whiteKing.loadFromFile(
            "oop-chess/Textures/w_king.png"))
      cout << "Could not load texture\n";
  }

  static void loadWhiteQueen() {
    if (!whiteQueen.loadFromFile(
            "oop-chess/Textures/w_queen.png"))
      cout << "Could not load texture\n";
  }

  static void loadWhiteRook() {
    if (!whiteRook.loadFromFile(
            "oop-chess/Textures/w_rook.png"))
      cout << "Could not load texture\n";
  }

  static void loadWhiteKnight() {
    if (!whiteKnight.loadFromFile(
            "oop-chess/Textures/w_knight.png"))
      cout << "Could not load texture\n";
  }

  static void loadWhiteBishop() {
    if (!whiteBishop.loadFromFile(
            "oop-chess/Textures/w_bishop.png"))
      cout << "Could not load texture\n";
  }

  static void loadWhitePawn() {
    if (!whitePawn.loadFromFile(
            "oop-chess/Textures/w_pawn.png"))
      cout << "Could not load texture\n";
  }

  static void setSpriteParameters(Sprite& sprite) {
    sprite.setOrigin(Vector2f(sprite.getTexture()->getSize().x / 2,
                              sprite.getTexture()->getSize().y / 2));
    sprite.setScale(Vector2f(0.375f, 0.375f));
  }
};

Texture LoadTextures::blackKing;
Texture LoadTextures::blackQueen;
Texture LoadTextures::blackRook;
Texture LoadTextures::blackKnight;
Texture LoadTextures::blackBishop;
Texture LoadTextures::blackPawn;

Texture LoadTextures::whiteKing;
Texture LoadTextures::whiteQueen;
Texture LoadTextures::whiteRook;
Texture LoadTextures::whiteKnight;
Texture LoadTextures::whiteBishop;
Texture LoadTextures::whitePawn;
