#ifndef _LINE_HPP
#define _LINE_HPP

#include "Drawable.hpp"

class Line: public Drawable {
  private:
    float length;
    float thickness;
  public:
    Line(const sf::Vector2f position, sf::Color color, bool active, float rotation, float length, float thickness);
    static Drawable* fromJsonValue(Json::Value config);
    Json::Value toJsonValue() override;
    virtual void draw(sf::RenderWindow & window) override;
};

#endif
