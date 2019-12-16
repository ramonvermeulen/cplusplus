#include "Line.hpp"

Line::Line(const sf::Vector2f position, sf::Color color, bool active, float rotation, float length, float thickness):
  Drawable(position, color, active, rotation, new sf::RectangleShape),
  length{length},
  thickness{thickness}
{
  static_cast<sf::RectangleShape*>(body) -> setOrigin(sf::Vector2f{thickness / 2, length / 2});
  static_cast<sf::RectangleShape*>(body) -> setSize(sf::Vector2f{thickness, length});
  static_cast<sf::RectangleShape*>(body) -> setRotation(rotation);
}

Drawable* Line::fromJsonValue(Json::Value config) {
  return new Line(
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
    config["length"].asFloat(),
    config["thickness"].asFloat()
  );
}

Json::Value Line::toJsonValue() {
  Json::Value line = Drawable::getBaseJson();
  line["type"] = "Line";
  line["length"] = length;
  line["thickness"] = thickness;
  return line;
}

void Line::draw(sf::RenderWindow & window) {
  static_cast<sf::RectangleShape*>(body) -> setPosition(position);
  static_cast<sf::RectangleShape*>(body) -> setRotation(rotation);
  window.draw(*body);
}
