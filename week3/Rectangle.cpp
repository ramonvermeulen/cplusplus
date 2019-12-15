#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const sf::Vector2f position, sf::Color color, bool active, const sf::Vector2f size):
  Drawable(position, color, active, new sf::RectangleShape()),
  size{size}
{
  static_cast<sf::RectangleShape*>(body) -> setOrigin(sf::Vector2f{size.x / 2, size.y / 2});
}

void Rectangle::draw(sf::RenderWindow & window) {
  static_cast<sf::RectangleShape*>(body) -> setPosition(position);
  static_cast<sf::RectangleShape*>(body) -> setSize(size);
  window.draw(*body);
}

Drawable* Rectangle::fromJsonValue(Json::Value config) {
  return new Rectangle(
    sf::Vector2f(
      config["position"]["x"].asFloat(),
      config["position"]["y"].asFloat()
    ),
    sf::Color(
      config["color"]["r"].asInt(),
      config["color"]["g"].asInt(),
      config["color"]["b"].asInt()
    ),
    config["active"].asBool(),
    sf::Vector2f(
      config["size"]["x"].asFloat(),
      config["size"]["y"].asFloat()
    )
  );
}
