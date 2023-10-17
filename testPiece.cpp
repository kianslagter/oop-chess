#include <iostream>
using namespace std;

#include "Knight.h"
#include "Piece.h"


int main() {
    Piece* piece = new Knight(true);
    cout << "Piece is: " << piece->getName() << endl;
    cout << piece->getPieceValue() << endl;
    delete piece;
    return 0;
}
