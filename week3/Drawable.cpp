#include "Drawable.hpp"
#include <iostream>

Drawable::Drawable(const sf::Vector2f position, sf::Color color, bool active, sf::Shape * body):
  position{position},
  color{color},
  active{active},
  body{body}
{
  body -> setFillColor(color);
}
