#ifndef _SHAPE_HPP
#define _SHAPE_HPP

#include <SFML/Graphics.hpp>

class Shape {
  protected:
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f size;
  public:
    sf::Shape * body;
    Shape(const sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Shape * body);
    virtual void draw(sf::RenderWindow & window) = 0;
    sf::Vector2f getSize();
};

#endif
