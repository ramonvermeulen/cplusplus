#include "Rectangle.hpp"

Rectangle::Rectangle(const sf::Vector2f position, sf::Color color, bool active, float rotation, const sf::Vector2f size):
  Drawable(position, color, active, rotation, new sf::RectangleShape()),
  size{size}
{
  static_cast<sf::RectangleShape*>(body) -> setOrigin(sf::Vector2f{size.x / 2, size.y / 2});
}

void Rectangle::draw(sf::RenderWindow & window) {
  static_cast<sf::RectangleShape*>(body) -> setPosition(position);
  static_cast<sf::RectangleShape*>(body) -> setSize(size);
  static_cast<sf::RectangleShape*>(body) -> setRotation(rotation);

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
    config["rotation"].asFloat(),
    sf::Vector2f(
      config["size"]["x"].asFloat(),
      config["size"]["y"].asFloat()
    )
  );
}

Json::Value Rectangle::toJsonValue() {
  Json::Value rectangle = Drawable::getBaseJson();
  rectangle["type"] = RECTANGLE_TYPE;
  rectangle["size"]["x"] = size.x;
  rectangle["size"]["y"] = size.y;
  return rectangle;
}
