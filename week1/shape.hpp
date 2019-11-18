#ifndef _SHAPE_HPP
#define _SHAPE_HPP

#include <SFML/Graphics.hpp>

class shape {
  private:
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f size;
  public:
    shape();
    virtual void draw(sf::RenderWindow & window);
};

#endif
