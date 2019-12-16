#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <jsoncpp/json/json.h>
#include "Constants.hpp"

class Drawable {
  protected:
    sf::Vector2f position;
    sf::Color color;
    bool active;
    sf::Shape* body;
  public:
    Drawable(const sf::Vector2f position, sf::Color color, bool active, sf::Shape * body);
    virtual void draw(sf::RenderWindow & window) = 0;
    virtual Json::Value toJsonValue() = 0;
    Json::Value getBaseJson();
    void handleInput();
    void updateActive(sf::Vector2i mousePosition);
};

#endif
