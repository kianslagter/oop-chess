// test function for nearest squre calculation
#include <iostream>
#include "nearestSquare.h"
using namespace std;

int main() {
    int row = 1;
    int col = 1;

    Vector2f center = getSquareCenter(row, col);

    std::cout << "The center of the square at row " << row << " and column " << col 
              << " is at (" << center.x << ", " << center.y << ").\n";

    return 0;
}
