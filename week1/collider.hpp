#ifndef _COLLIDER_HPP
#define _COLLIDER_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class Collider {
  private:
    Shape* body;
  public:
    Collider(Shape* body);
    std::pair<bool, sf::Vector2f> is_colliding(Shape * other);
};

#endif
