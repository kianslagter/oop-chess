// test the getlegalmoves function
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Pawn.h"

int main() {
    // create vector
    vector<Piece*> pieces;

    // create pawns
    Pawn* whitePawn = new Pawn(true);
    whitePawn->getSprite().setPosition(getSquareCenter(6, 0));
    pieces.push_back(whitePawn);

    Pawn* blackPawn = new Pawn(false);
    blackPawn->getSprite().setPosition(getSquareCenter(1, 1));
    pieces.push_back(blackPawn);

    // test
    vector<Vector2f> legalMoves = whitePawn->getLegalMoves(6, 0, pieces);
    cout << "Legal moves for white pawn:" << endl;
    for (Vector2f move : legalMoves) {
        cout << "(" << move.x << ", " << move.y << ")" << endl;
    }

    legalMoves = blackPawn->getLegalMoves(1, 1, pieces);
    cout << "Legal moves for black pawn:" << endl;
    for (Vector2f move : legalMoves) {
        cout << "(" << move.x << ", " << move.y << ")" << endl;
    }

    // delete
    for (Piece* piece : pieces) {
        delete piece;
    }

    return 0;
}
