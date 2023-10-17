# Chess
Two-player Chess game with GUI in C++ using OOP.

# Installation / Compiling

* Prerequisites
  - SFML

Instilation and compiling process.
```
 $ git clone https://github.com/kianslagter/oop-chess.git
 $ cd oop-chess
 $ make
 $ ./run.out
```

# Missing Features / Limitations
* Castling
* En Passant
* Choosing Promotions
  - Pawn automatically promotes to queen, with no option for user to choose another piece.
* Check detection / Check mate
  - There is no in built detection for check, and thus no automatic check mate detection, instead when king is captured game finishes.

# Alterations from Project Plan
* General Name Changes
  - General name changes of certain functions and attributes where done.
* Menu
  - No menu was added, with ability to quit game being featured in terminal.
* drawBoard
  - Replaced function drawBoard() with seperate class, drawBoard.h to draw the chess board.
* ChessBoard Class
  - functions getSquare() and gameOver() removed, with function gameOver() being replaced with function isKingTaken() used in the main.cpp file.
* Piece Class
  - Attribute status is removed, including for all inherited classes.
* King Class
  - checkCheck attribute in king class is removed, and all functions using it.
  - Function kingStatus() replaced with isKingTaken() function in chessBoard.h.
* nearestSquare Class
  - Added nearestSquare.h class, with functions getClosestSquare(), and getSquareCenter().
* loadTextures Class
  - Added loadTextures.h class, allowing for the correct piece textures to be displayed.

# Authors
* Kian Slagter
* Manjeevan Bhullar
