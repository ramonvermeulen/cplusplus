#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(const sf::Vector2f & position, const int & width, const int & height, const sf::Color & color):
  position{ position },
  size{ (float) width, (float) height },
  color { color }
{}

void wall::draw(sf::RenderWindow & window) {
  sf::RectangleShape wall;
  wall.setFillColor(color);
  wall.setSize(size);
  wall.setPosition(position);
  window.draw(wall);
}
