#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>
using namespace sf;
using namespace std;

class Board : public Drawable{

public:

    Board(Color col1 = Color::White, Color col2 = Color::Black){
        load(col1,col2);
    }
    
    // board colours
    void load(Color col1 = Color::White, Color col2 = Color::Black){
        for(int i=0; i<8;i++){

            bool tmpColor = ((i % 2)==0)?true:false;

            for(int j=0; j<8;j++){

                m_boardSquares[j + (i * 8)].setPosition(Vector2f( j*64.f , i*64.f ));
                m_boardSquares[j + (i * 8)].setSize(Vector2f(64.f, 64.f));
                m_boardSquares[j + (i * 8)].setFillColor(tmpColor ? col1 : col2);
                
                tmpColor = !tmpColor;
            }
        }
    }

private:

    array<RectangleShape, 64> m_boardSquares;
    
    // draw board
    virtual void draw(RenderTarget& target, RenderStates states) const{
        for(int i=0;i<64;i++){
            target.draw(m_boardSquares[i], states);
        }
    }

};