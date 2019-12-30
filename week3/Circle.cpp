#include "Circle.hpp"

Circle::Circle(const sf::Vector2f position, sf::Color color, bool active, float rotation, float radius):
  Drawable(position, color, active, rotation, new sf::CircleShape),
  radius{radius}
{
  static_cast<sf::CircleShape*>(body) -> setRadius(radius);
  static_cast<sf::RectangleShape*>(body) -> setOrigin(sf::Vector2f{radius, radius});
}

Drawable* Circle::fromJsonValue(Json::Value config) {
  return new Circle(
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
    config["radius"].asFloat()
  );
}

Json::Value Circle::toJsonValue() {
  Json::Value circle = Drawable::getBaseJson();
  circle["type"] = CIRCLE_TYPE;
  circle["radius"] = radius;
  return circle;
}

void Circle::draw(sf::RenderWindow & window) {
  static_cast<sf::RectangleShape*>(body) -> setPosition(position);
  static_cast<sf::RectangleShape*>(body) -> setRotation(rotation);
  window.draw(*body);
}
