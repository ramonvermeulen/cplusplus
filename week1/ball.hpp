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
    int no_collision_frames;
    sf::Vector2f calculate_next_position();
  public:
    Ball(const sf::Vector2f start_position, const sf::Color color, float radius = 30.0, float direction = 145, float velocity = 5);
    Collider collider;
    void invert_move_x(float intersect_x);
    void invert_move_y(float intersect_y);
    void draw(sf::RenderWindow & window) override;
};

#endif
