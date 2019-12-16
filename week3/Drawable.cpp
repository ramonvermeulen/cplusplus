#include "Drawable.hpp"

float SPEED = 2.5;

Drawable::Drawable(const sf::Vector2f position, sf::Color color, bool active, sf::Shape * body):
  position{position},
  color{color},
  active{active},
  body{body}
{
  body -> setFillColor(color);
}

void Drawable::handleInput() {
  if (active) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      position.x -= SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      position.x += SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      position.y -= SPEED;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      position.y += SPEED;               
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

