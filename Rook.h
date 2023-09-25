#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Rook : public Piece
{
private:
public:
    string getName() override { return "Rook"; }
    Rook(/* args */){};
    ~Rook() override {};
};