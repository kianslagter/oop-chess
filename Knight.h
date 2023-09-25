#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Knight : public Piece
{
private:
public:
    string getName() override { return "Knight"; }
    Knight(/* args */){};
    ~Knight() override {};
};