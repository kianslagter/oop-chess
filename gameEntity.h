// base class for all objects and pieces
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameEntity {
 public:
  Sprite sprite;

  virtual Sprite& getSprite() { return sprite; }

  virtual void draw(RenderWindow& window) const { window.draw(sprite); }

  virtual ~GameEntity() {};
};
