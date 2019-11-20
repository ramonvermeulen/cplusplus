#include <SFML/Graphics.hpp>
#include "square.hpp"

Square::Square(const sf::Vector2f & position, float size, sf::Color color):
  position{ position },
  size{ size, size },
  color{ color }
{}

sf::Vector2f Square::Vector2i_to_Vector2f(const sf::Vector2i & target) {
    return sf::Vector2f(
        static_cast<float>(target.x),
        static_cast<float>(target.y)
    );
}

void Square::handle_input(const sf::Window & window) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(sf::Vector2f{ -2.5, 0 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(sf::Vector2f{ +2.5, 0 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(sf::Vector2f{ 0, -2.5 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(sf::Vector2f{ 0, +2.5 });                
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        jump(sf::Mouse::getPosition(window));
    }
}

void Square::draw(sf::RenderWindow & window) {
  sf::RectangleShape square;
  square.setSize(size);
  square.setPosition(position);
  window.draw(square);
}

void Square::jump(const sf::Vector2f & target) {
  position = target;
}

void Square::jump(const sf::Vector2i & target) {
  jump(Vector2i_to_Vector2f(target));
}

void Square::move(const sf::Vector2f & delta) {
  position += delta;
}
