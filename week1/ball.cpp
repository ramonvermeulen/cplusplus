#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "ball.hpp"

Ball::Ball(const sf::Vector2f start_position, const sf::Color color, float radius, float direction, float velocity)
  : Shape(start_position, sf::Vector2f{ radius * 2, radius * 2 }, color, new sf::CircleShape),
  radius {radius},
  direction {direction},
  velocity {velocity},
  move_x {(float) sin(direction * M_PI / 180) * velocity},
  move_y {(float) -std::cos(direction * M_PI / 180) * velocity},
  collider{Collider(this)}
{   
  static_cast<sf::CircleShape*>(body) -> setRadius(radius);
}

sf::Vector2f Ball::calculate_next_position() {
  float new_x = position.x + move_x;
  float new_y = position.y + move_y;

  return sf::Vector2f{ new_x, new_y };
}

void Ball::invert_move_x(float intersect_x) {;
  move_x = -move_x;
  if (move_x < 0) {
    position.x += intersect_x;
  } else {
    position.x += abs(intersect_x);
  }
  body -> setFillColor(sf::Color(255, rand() % 200, rand() % 200));
}

void Ball::invert_move_y(float intersect_y) {
  move_y = -move_y;
  if (move_y < 0) {
    position.y += intersect_y;
  } else {
    position.y += abs(intersect_y);
  }
  body -> setFillColor(sf::Color(rand() % 200, rand() % 200, 255));
}

void Ball::draw(sf::RenderWindow & window) {
  position = calculate_next_position();
  static_cast<sf::CircleShape*>(body) -> setPosition(position);
  window.draw(*body);
}
