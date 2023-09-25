#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Bishop : public Piece
{
private:
    /* data */
public:
    string getName() override { return "Bishop"; }
    Bishop(/* args */){};
    ~Bishop() override {};
};