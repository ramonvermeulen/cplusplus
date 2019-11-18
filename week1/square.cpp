#include <SFML/Graphics.hpp>
#include "square.hpp"

square::square(const sf::Vector2f & position, float size):
  position{ position },
  size{ size, size }
{}

sf::Vector2f square::Vector2i_to_Vector2f(const sf::Vector2i & target) {
    return sf::Vector2f(
        static_cast<float>(target.x),
        static_cast<float>(target.y)
    );
}

void square::handle_input(const sf::Window & window) {
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

void square::draw(sf::RenderWindow & window) {
  sf::RectangleShape square;
  square.setSize(size);
  square.setPosition(position);
  window.draw(square);
}

void square::jump(const sf::Vector2f & target) {
  position = target;
}

void square::jump(const sf::Vector2i & target) {
  jump(Vector2i_to_Vector2f(target));
}

void square::move(const sf::Vector2f & delta) {
  position += delta;
}
