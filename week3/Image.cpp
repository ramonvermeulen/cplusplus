#include "Image.hpp"

Image::Image(const sf::Vector2f position, sf::Color color, bool active, float rotation, const sf::Vector2f size, std::string imagePath):
  Drawable(position, color, active, rotation, new sf::RectangleShape()),
  size{size},
  imagePath{imagePath},
  texture{new sf::Texture()}
{
  if(!texture -> loadFromFile(imagePath)) {
    std::cout << "Could not load image file" << std::endl;
  }
  static_cast<sf::RectangleShape*>(body) -> setTexture(texture);
  static_cast<sf::RectangleShape*>(body) -> setOrigin(sf::Vector2f{size.x / 2, size.y / 2});
}

void Image::draw(sf::RenderWindow & window) {
  static_cast<sf::RectangleShape*>(body) -> setPosition(position);
  static_cast<sf::RectangleShape*>(body) -> setSize(size);
  static_cast<sf::RectangleShape*>(body) -> setRotation(rotation);

  window.draw(*body);
}

Drawable* Image::fromJsonValue(Json::Value config) {
  return new Image(
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
    ),
    config["imagePath"].asString()
  );
}

Json::Value Image::toJsonValue() {
  Json::Value image = Drawable::getBaseJson();
  image["type"] = IMAGE_TYPE;
  image["size"]["x"] = size.x;
  image["size"]["y"] = size.y;
  image["imagePath"] = imagePath;
  return image;
}
