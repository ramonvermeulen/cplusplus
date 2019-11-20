#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class Ball: public Shape {
  private:
    float direction;
    float velocity;
    float move_x;
    float move_y;
    sf::Vector2f calculate_next_position();
  public:
    Ball(const sf::Vector2f start_position, const sf::Color color, float size = 30.0, float direction = 145, float velocity = 5);
    void draw(sf::RenderWindow & window) override;
};

#endif
