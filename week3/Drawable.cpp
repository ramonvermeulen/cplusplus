#include "Drawable.hpp"

Drawable::Drawable(const sf::Vector2f position, const sf::Color color, bool active, sf::Drawable * body):
  position{position},
  color{color},
  active{active},
  body{body}
{ }
