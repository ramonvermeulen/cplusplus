#include <SFML/Graphics.hpp>
#include "collider.hpp"
#include "shape.hpp"
#include <iostream>

Collider::Collider(Shape * body):
  body{body}
{ }

std::pair<bool, sf::Vector2f> Collider::is_colliding(Shape * other) {
  sf::Vector2f current_position = body -> body -> getPosition();
  sf::Vector2f current_half_size = body -> getSize() / (float) 2;
  sf::Vector2f other_position = other -> body -> getPosition();
  sf::Vector2f other_half_size = other -> getSize() / (float) 2;
  
  float delta_x = other_position.x - current_position.x;
  float delta_y = other_position.y - current_position.y;

  float intersect_x = abs(delta_x) - (current_half_size.x + other_half_size.x);
  float intersect_y = abs(delta_y) - (current_half_size.y + other_half_size.y);

  bool is_colliding;
  
  if (intersect_x < (float) 0 && intersect_y < (float) 0) {
    is_colliding = true;
  } else {
    is_colliding = false;
  }

  return std::pair<bool, sf::Vector2f>(is_colliding, sf::Vector2f{intersect_x, intersect_y});
}