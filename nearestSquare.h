#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

Vector2f getClosestSquare(Vector2f pos) {
  int x = static_cast<int>(pos.x / 64.f);
  int y = static_cast<int>(pos.y / 64.f);

  return Vector2f((x * 64.f) + 32.f, (y * 64.f) + 32.f);
}

Vector2f getSquareCenter(int row, int col) {
    float x = col * 64.0f + 64.0f / 2;
    float y = row * 64.0f + 64.0f / 2;
    return Vector2f(x, y);
}
