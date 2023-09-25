#pragma once
#include <iostream>
#include <string>
using namespace std;

class Piece
{
private:
    /* data */
public:
    virtual string getName() = 0;
    virtual ~Piece() {};

};

