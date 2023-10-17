# Chess
Two-player Chess game using GUI in C++ using OOP.

# Installation / Compiling


# Missing Features
* Castling
* En Passant
* Choosing Promotions
  - Pawn automatically promotes to queen, with no option for user to choose another piece.
* Check detection / Check mate
  - There is no in built detection for check, and thus no automatic check mate detection, instead when king is captured game finishes.


# Alterations from Project Plan
* drawBoard
  - Replaced function drawBoard() with seperate class, drawBoard.h to draw the chess board.
* ChessBoard Class
  - functions getSquare() and gameOver() removed, with function gameOver() being replaced with function isKingTaken() used in the main.cpp file.
* Piece Class
  - Attribute status is removed, including for all inherited classes.
* King Class
  - checkCheck attribute in king class is removed, and all functions using it.
  - Function kingStatus() replaced with isKingTaken() function in chessBoard.h.

# Authors
* Kian Slagter
* Manjeevan Bhullar
