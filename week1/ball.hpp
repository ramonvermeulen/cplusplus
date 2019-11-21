#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"
#include "collider.hpp"

class Ball: public Shape {
  private:
    float direction;
    float velocity;
    float move_x;
    float move_y;
    float radius;
    sf::Vector2f calculate_next_position();
  public:
    Collider collider;
    Ball(const sf::Vector2f start_position, const sf::Color color, float radius = 30.0, float direction = 145, float velocity = 5);
    void draw(sf::RenderWindow & window) override;
};

#endif
