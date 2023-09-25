#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Pawn : public Piece
{
private:
public:
    string getName() override { return "Pawn"; }
    Pawn(/* args */){};
    ~Pawn() override {};
};