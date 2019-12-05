#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class Drawable {
  private:
    sf::Vector2f position;
    sf::Color color;
    bool active;
    void handleInput();
  public:
    Drawable(sf::Vector2f & position, sf::Color & color, bool active);
    virtual void draw() = 0;
};

#endif
