#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "Drawable.hpp"
#include "jsoncpp/json/json.h"

class Line: public Drawable {
  private:
    float length;
    float thickness;
    float rotation;
  public:
    Line(const sf::Vector2f position, sf::Color color, bool active, float length, float thickness, float rotation);
    static Drawable* fromJsonValue(Json::Value config);
    Json::Value toJsonValue() override;
    virtual void draw(sf::RenderWindow & window) override;
};

#endif
