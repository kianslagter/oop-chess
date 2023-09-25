#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Piece.h"

class Queen : public Piece
{
private:
public:
    string getName() override { return "Queen"; }
    Queen(/* args */){};
    ~Queen() override {};
};