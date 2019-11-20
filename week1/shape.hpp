#ifndef _SHAPE_HPP
#define _SHAPE_HPP

#include <SFML/Graphics.hpp>

class Shape {
  private:
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f size;
  public:
    Shape();
    virtual void draw(sf::RenderWindow & window);
};

#endif
