#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include "Drawable.hpp"

class Image: public Drawable {
  private:
    sf::Vector2f size;
    std::string imagePath;
    sf::Texture* texture;
  public:
    Image(const sf::Vector2f position, sf::Color color, bool active, float rotation, const sf::Vector2f size, std::string imagePath);
    static Drawable* fromJsonValue(Json::Value config);
    Json::Value toJsonValue() override;
    virtual void draw(sf::RenderWindow & window) override;
};

#endif
