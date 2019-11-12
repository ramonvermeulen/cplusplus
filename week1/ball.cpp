#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(const sf::Vector2f & position, float size):
  position{ position },
  size{ size }
{}

void ball::draw(sf::RenderWindow & window) const {
  sf::CircleShape circle;
  circle.setRadius(size);
  circle.setPosition(position);
  window.draw(circle);
}

void ball::jump(const sf::Vector2f & target) {
  position = target;
}

void ball::move(const sf::Vector2f & delta) {
  position += delta;
}