#include "Board.h"

#include <iostream>

void Board::displayBoard() {
  char letterAxis[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'H'};
  for (int i = 0; i < 8; i++) {
    std::cout << letterAxis[i];
    for (int j = 0; j < 8; j++) {
    }
  }

  for (int i = 0; i < 8; i++) {
    std::cout << (i+1);
  }
}