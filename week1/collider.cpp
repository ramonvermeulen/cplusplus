#include <SFML/Graphics.hpp>
#include "collider.hpp"
#include "shape.hpp"
#include <iostream>

Collider::Collider(Shape * body):
  body{body}
{ }

std::pair<bool, float> Collider::is_colliding(Shape * other) {
  sf::Vector2f current_position = body -> body -> getPosition();
  sf::Vector2f current_half_size = body -> getSize() / (float) 2;
  sf::Vector2f other_position = other -> body -> getPosition();
  sf::Vector2f other_half_size = other -> getSize() / (float) 2;
  

  float delta_x = other_position.x - current_position.x;
  float delta_y = other_position.y - current_position.y;

  float intersect_x = abs(delta_x) - (current_half_size.x + other_half_size.x);
  float intersect_y = abs(delta_y) - (current_half_size.y + other_half_size.y);
  
  if (intersect_x < (float) 0 && intersect_y < (float) 0) {
    std::cout << "jup" << std::endl;
  } else {
    std::cout << "nope" << std::endl;
  }
  // std::cout << current_position.x << current_position.y << std::endl;
  // std::cout << current_half_size.x << current_half_size.y << std::endl;
  // std::cout << other_position.x << other_position.y << std::endl;
  // std::cout << other_half_size.x << other_half_size.y << std::endl;

  return std::pair<bool, float>(true, 1.1);
}