#include "Drawable.hpp"

Drawable::Drawable(const sf::Vector2f position, sf::Color color, bool active, float rotation, sf::Shape * body):
  position{position},
  color{color},
  active{active},
  rotation{rotation},
  body{body}
{
  body -> setFillColor(color);
}

void Drawable::handleInput() {
  if (active) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && position.x > 0) {
      position.x -= DRAWABLE_SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && position.x < SCREEN_WIDTH) {
      position.x += DRAWABLE_SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && position.y > 0) {
      position.y -= DRAWABLE_SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && position.y < SCREEN_HEIGHT) {
      position.y += DRAWABLE_SPEED;               
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
      rotation -= DRAWABLE_SPEED;   
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
      rotation += DRAWABLE_SPEED;  
    }
  }
}

void Drawable::updateActive(sf::Vector2i mousePosition) {
  if(body -> getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
    active = true;
    body -> setOutlineThickness(5);
  } else {
    active = false;
    body -> setFillColor(color);
    body -> setOutlineThickness(0);
  }
}

Json::Value Drawable::getBaseJson() {
  Json::Value drawable;
  drawable["position"]["x"] = position.x;
  drawable["position"]["y"] = position.y;
  drawable["color"]["r"] = color.r;
  drawable["color"]["g"] = color.g;
  drawable["color"]["b"] = color.b;
  drawable["active"] = active;
  drawable["rotation"] = rotation;
  return drawable;
}

