#ifndef _SQUARE_HPP
#define _SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class Square: public Shape {
  private: // Waarom moet ik position, size, color hier opnieuw declaren?
    sf::Vector2f Vector2i_to_Vector2f(const sf::Vector2i & target);
    void move(const sf::Vector2f & delta);
    void jump(const sf::Vector2f & target);
    void jump(const sf::Vector2i & target);
  public: // Wat doet dit & teken? En waarom const in de param en niet bij declaratie?
    Square(const sf::Vector2f & position, float size = 30.0, sf::Color color = sf::Color::White);
    void draw(sf::RenderWindow & window) override;
    void handle_input(const sf::Window & window);
};

#endif
