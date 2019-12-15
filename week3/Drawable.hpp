#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class Drawable {
  protected:
    sf::Color color;
    bool active;
    sf::Drawable* body;
    void handleInput();
  public:
    sf::Vector2f position;
    Drawable(const sf::Vector2f position, sf::Color color, bool active, sf::Shape * body);
    virtual void draw(sf::RenderWindow & window) = 0;
};

#endif
