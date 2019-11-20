#include <SFML/Graphics.hpp>
#include "wall.hpp"

Wall::Wall(const sf::Vector2f position, const float width, const float height, const sf::Color & color)
  : Shape( position, sf::Vector2f{ width, height }, color, new sf::RectangleShape )
{ }

void Wall::draw(sf::RenderWindow & window) {
  static_cast<sf::RectangleShape*>(body) -> setFillColor(color);
  static_cast<sf::RectangleShape*>(body) -> setSize(size);
  static_cast<sf::RectangleShape*>(body) -> setPosition(position);
  window.draw(*body);
}
