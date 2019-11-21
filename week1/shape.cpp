#include "shape.hpp"

Shape::Shape(const sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Shape * body):
  position{position},
  size{size},
  color{color},
  body{body}
{ 
  body -> setFillColor(color);
  body -> setOrigin(sf::Vector2f{size.x / 2, size.y / 2});
}

sf::Vector2f Shape::getSize() {
  return size;
}