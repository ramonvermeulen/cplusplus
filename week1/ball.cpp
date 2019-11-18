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

float ball::calculate_acceleration_factor(int base_corner_degrees) {
  int relative_direction = direction - base_corner_degrees;
  if ((float) (relative_direction % 45) / 45 == 0.0 && direction != 0 && direction != 90 && direction != 180 && direction != 270 && direction != 360) {
    return 2;
  } else if (relative_direction < 45) {
    return 1 + (float) (relative_direction % 45) / 45;
  } else if (relative_direction > 45) {
    return 1 + (float) (1 - (float) (relative_direction % 45) / 45);
  }
  return 1;
}

sf::Vector2f ball::calculate_next_position() {
  float factor; // between 0 and 1
  float calculated_speed;
  if (direction <= 90) {
    factor = (float) direction / 90;
    calculated_speed = speed * calculate_acceleration_factor(0);
    float new_x = position.x + (float) (factor * calculated_speed);
    return sf::Vector2f{ new_x, position.y - (calculated_speed - (new_x - position.x)) };
  } else if (direction > 90 && direction <= 180) {
    factor = (float) (direction - 90) / 90;
    calculated_speed = speed * calculate_acceleration_factor(90);
    float new_y = position.y + (float) (factor * calculated_speed);
    return sf::Vector2f{ position.x + (calculated_speed - (new_y - position.y)), new_y };
  } else if (direction > 180 && direction <= 270) {
    factor = (float) (direction - 180) / 90;
    calculated_speed = speed * calculate_acceleration_factor(180);
    float new_x = position.x - (float) (factor * calculated_speed);
    return sf::Vector2f{ new_x, position.y + (calculated_speed - (position.x - new_x)) };
  } else if (direction > 270 && direction <= 360) {
    factor = (float) (direction - 270) / 90;
    calculated_speed = speed * calculate_acceleration_factor(270);
    float new_y = position.y - (float) (factor * calculated_speed);
    return sf::Vector2f{ position.x - (calculated_speed - (position.y - new_y)), new_y };
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
