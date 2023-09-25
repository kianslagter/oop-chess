#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class King : public Piece
{
private:
public:
    string getName() override { return "King"; }
    King(/* args */){};
    ~King() override {};
};