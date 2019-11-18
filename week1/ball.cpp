#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"

ball::ball(const sf::Vector2f & start_position, const sf::Color & color, float size, int direction, int speed):
  position{ start_position },
  color{ color },
  size{ size },
  direction { direction },
  speed { speed }
{}

sf::Vector2f ball::calculate_next_position() {
  float factor;
  if (direction <= 90) {
    factor = (float) direction / 90;
    float new_x = position.x + (float) (factor * speed);
    return sf::Vector2f{ new_x, position.y - (speed - (new_x - position.x)) };
  } else if (direction > 90 && direction <= 180) {
    factor = (float) (direction - 90) / 90;
    float new_y = position.y + (float) (factor * speed);
    return sf::Vector2f{ position.x + (speed - (new_y - position.y)), new_y };
  } else if (direction > 180 && direction <= 270) {
    factor = (float) (direction - 180) / 90;
    float new_x = position.x - (float) (factor * speed);
    return sf::Vector2f{ new_x, position.y + (speed - (position.x - new_x)) };
  } else if (direction > 270 && direction <= 360) {
    factor = (float) (direction - 270) / 90;
    float new_y = position.y - (float) (factor * speed);
    return sf::Vector2f{ position.x - (speed - (position.y - new_y)), new_y };
  }
  throw "direction cannnot be more than 360 degress";
}

void ball::draw(sf::RenderWindow & window) {
  sf::CircleShape circle;
  circle.setRadius(size);
  circle.setFillColor(color);
  position = calculate_next_position();
  circle.setPosition(position);
  window.draw(circle);
}
