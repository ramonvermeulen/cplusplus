#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include "Drawable.hpp"

class Circle: public Drawable {
  private:
    float radius;
  public:
    Circle(const sf::Vector2f position, sf::Color color, bool active, float rotation, float radius);
    static Drawable* fromJsonValue(Json::Value config);
    Json::Value toJsonValue() override;
    virtual void draw(sf::RenderWindow & window) override;
};

#endif
