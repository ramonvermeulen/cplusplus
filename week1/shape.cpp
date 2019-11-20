#include "shape.hpp"

Shape::Shape(const sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Shape * body):
  position{position},
  size{size},
  color{color},
  body{body}
{ } 