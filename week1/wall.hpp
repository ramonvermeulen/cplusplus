#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class Wall: public Shape {
  private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
  public:
    Wall(const sf::Vector2f & position, const int & width, const int & height, const sf::Color & color);
    void draw(sf::RenderWindow & window) override;
};

#endif
