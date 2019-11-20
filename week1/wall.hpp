#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class Wall: public Shape {
  public:
    Wall(const sf::Vector2f position, const float width, const float height, const sf::Color & color);
    void draw(sf::RenderWindow & window) override;
};

#endif
