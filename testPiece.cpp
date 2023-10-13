#include <iostream>
using namespace std;

#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "ChessBoard.h"

int main() {
    Piece* piece = new Knight();
    cout << "Piece is: " << piece->getName() << endl;
    delete piece;
    return 0;
}