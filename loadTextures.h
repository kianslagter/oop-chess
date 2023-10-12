#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class LoadTextures{
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

    static void loadTextures() {
        if (!blackKing.loadFromFile("/Users/kianslagter/oop-chess/Textures/b_king.png"))
            cout << "Could not load texture\n";
        if (!blackQueen.loadFromFile("/Users/kianslagter/oop-chess/Textures/b_queen.png"))
            cout << "Could not load texture\n";
        if (!blackRook.loadFromFile("/Users/kianslagter/oop-chess/Textures/b_rook.png"))
            cout << "Could not load texture\n";
        if (!blackKnight.loadFromFile("/Users/kianslagter/oop-chess/Textures/b_knight.png"))
            cout << "Could not load texture\n";
        if (!blackBishop.loadFromFile("/Users/kianslagter/oop-chess/Textures/b_bishop.png"))
            cout << "Could not load texture\n";
        if (!blackPawn.loadFromFile("/Users/kianslagter/oop-chess/Textures/b_pawn.png"))
            cout << "Could not load texture\n";

        if (!whiteKing.loadFromFile("/Users/kianslagter/oop-chess/Textures/w_king.png"))
            cout << "Could not load texture\n";
        if (!whiteQueen.loadFromFile("/Users/kianslagter/oop-chess/Textures/w_queen.png"))
            cout << "Could not load texture\n";
        if (!whiteRook.loadFromFile("/Users/kianslagter/oop-chess/Textures/w_rook.png"))
            cout << "Could not load texture\n";
        if (!whiteKnight.loadFromFile("/Users/kianslagter/oop-chess/Textures/w_knight.png"))
            cout << "Could not load texture\n";
        if (!whiteBishop.loadFromFile("/Users/kianslagter/oop-chess/Textures/w_bishop.png"))
            cout << "Could not load texture\n";
        if (!whitePawn.loadFromFile("/Users/kianslagter/oop-chess/Textures/w_pawn.png"))
            cout << "Could not load texture\n";
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

