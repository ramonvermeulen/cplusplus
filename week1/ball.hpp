#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class ball: public shape {
  private:
    sf::Vector2f position;
    sf::Color color;
    float size;
    int direction;
    int speed;
  public:
    ball(const sf::Vector2f & start_position, const sf::Color & color, float size = 30.0, int direction = 145, int speed = 5);
    void draw(sf::RenderWindow & window) override;
    sf::Vector2f calculate_next_position();
    float calculate_acceleration_factor(int base_corner_degrees);
};

#endif
