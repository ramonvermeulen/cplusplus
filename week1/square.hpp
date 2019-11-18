#ifndef _SQUARE_HPP
#define _SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class square: public shape {
  private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f Vector2i_to_Vector2f(const sf::Vector2i & target);
  
  public:
    square(const sf::Vector2f & position, float size = 30.0);
    void draw(sf::RenderWindow & window) override;
    void move(const sf::Vector2f & delta);
    void jump(const sf::Vector2f & target);
    void jump(const sf::Vector2i & target);
    void handle_input(const sf::Window & window);
};

#endif
