#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>

class ball {
  private:
    sf::Vector2f position;
    float size;
  
  public: // Wat doet diet & teken? Ik zou logischerwijs const sf::Vector2f position denken
    ball(const sf::Vector2f & position, float size = 30.0);
    void draw(sf::RenderWindow & window) const;
    void move(const sf::Vector2f & delta);
    void jump(const sf::Vector2f & target);
};

#endif
