#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "ball.hpp"

const int SCREEN_HEIGHT = 480.0;
const int SCREEN_WIDTH = 640.0;

Ball::Ball(
  const sf::Vector2f start_position,
  const sf::Color color,
  float size,
  float direction,
  float velocity
  ) : Shape(start_position, sf::Vector2f{ size, size }, color, new sf::CircleShape),
  direction { direction },
  velocity { velocity },
  move_x { (float) sin(direction * M_PI / 180) * velocity },
  move_y { (float) -std::cos(direction * M_PI / 180) * velocity }
  { }

sf::Vector2f Ball::calculate_next_position() {
  if(position.x >= SCREEN_WIDTH - size.x * 2) {
    move_x = -move_x;
  }
  if (position.x <= 0) {
    move_x = -move_x;
  }
  if (position.y >= SCREEN_HEIGHT - size.x * 2) {
    move_y = -move_y;
  }
  if (position.y <= 0) {
    move_y = -move_y;
  }

  float new_x = position.x + move_x;
  float new_y = position.y + move_y;
  
  return sf::Vector2f{ new_x, new_y };
}

void Ball::draw(sf::RenderWindow & window) {
  static_cast<sf::CircleShape*>(body) -> setRadius(size.x);
  static_cast<sf::CircleShape*>(body) -> setFillColor(color);
  position = calculate_next_position();
  static_cast<sf::CircleShape*>(body) -> setPosition(position);
  window.draw(*body);
}
