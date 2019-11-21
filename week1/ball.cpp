#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "ball.hpp"

const int SCREEN_HEIGHT = 480.0;
const int SCREEN_WIDTH = 640.0;

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
  if(position.x >= SCREEN_WIDTH - radius) {
    move_x = -move_x;
  }
  if (position.x <= 0 + radius) {
    move_x = -move_x;
  }
  if (position.y >= SCREEN_HEIGHT - radius) {
    move_y = -move_y;
  }
  if (position.y <= 0 + radius) {
    move_y = -move_y;
  }

  float new_x = position.x + move_x;
  float new_y = position.y + move_y;
  
  return sf::Vector2f{ new_x, new_y };
}

void Ball::draw(sf::RenderWindow & window) {
  position = calculate_next_position();
  static_cast<sf::CircleShape*>(body) -> setPosition(position);
  // sf::RectangleShape head;
  // head.setSize(sf::Vector2f{ 1.0, 1.0 });
  // head.setFillColor(sf::Color::Cyan);
  // head.setPosition(sf::Vector2f{ position.x + move_x, position.y + move_y });
  window.draw(*body);
  // window.draw(head);
}
