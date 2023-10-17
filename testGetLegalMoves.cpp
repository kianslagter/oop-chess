#include <iostream>
#include <vector>
#include "Piece.h"
#include "Pawn.h"

int main() {
    // Create a vector to store the pieces
    vector<Piece*> pieces;

    // Create a white pawn at position (6, 0)
    Pawn* whitePawn = new Pawn(true);
    whitePawn->getSprite().setPosition(getSquareCenter(6, 0));
    pieces.push_back(whitePawn);

    // Create a black pawn at position (1, 1)
    Pawn* blackPawn = new Pawn(false);
    blackPawn->getSprite().setPosition(getSquareCenter(1, 1));
    pieces.push_back(blackPawn);

    // Test the getLegalMoves function for the white pawn
    vector<Vector2f> legalMoves = whitePawn->getLegalMoves(6, 0, pieces);
    cout << "Legal moves for white pawn:" << endl;
    for (Vector2f move : legalMoves) {
        cout << "(" << move.x << ", " << move.y << ")" << endl;
    }

    // Test the getLegalMoves function for the black pawn
    legalMoves = blackPawn->getLegalMoves(1, 1, pieces);
    cout << "Legal moves for black pawn:" << endl;
    for (Vector2f move : legalMoves) {
        cout << "(" << move.x << ", " << move.y << ")" << endl;
    }

    // Clean up
    for (Piece* piece : pieces) {
        delete piece;
    }

    return 0;
}
