#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>
using namespace sf;
using namespace std;

class Board : public Drawable{

public:

    Board(Color col1, Color col2){
        for(int i=0; i<8;i++){

            bool tmpColor = ((i % 2)==0)?true:false;

            for(int j=0; j<8;j++){

                boardSquares[j + (i * 8)].setPosition(Vector2f( j*64.f , i*64.f ));
                boardSquares[j + (i * 8)].setSize(Vector2f(64.f, 64.f));
                boardSquares[j + (i * 8)].setFillColor(tmpColor ? col1 : col2);
                
                tmpColor = !tmpColor;
            }
        }
    }

private:
    array<RectangleShape, 64> boardSquares;
    
    // draw board
    virtual void draw(RenderTarget& target, RenderStates states) const{
        for(int i=0;i<64;i++){
            target.draw(boardSquares[i], states);
        }
    }

};
