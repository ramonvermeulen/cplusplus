#ifndef _COLLIDER_HPP
#define _COLLIDER_HPP

#include <SFML/Graphics.hpp>
#include "shape.hpp"

class Collider {
  private:
    Shape* body;
  public:
    Collider(Shape * body);
    std::pair<bool, float> is_colliding(Shape * other);
};

// Herzie dit nog even, misschien heeft SFML zelf hier wel iets voor
// Je wilt tenslotte niet al je walls bijhouden bij je Ball

#endif
