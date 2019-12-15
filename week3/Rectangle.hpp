#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "Drawable.hpp"
#include "jsoncpp/json/json.h"

class Rectangle: public Drawable {
  private:
    sf::Vector2f size;
  public:
    Rectangle(const sf::Vector2f position, sf::Color color, bool active, const sf::Vector2f size);
    static Drawable* fromJsonValue(Json::Value config);
    virtual void draw(sf::RenderWindow & window) override;
};

#endif
