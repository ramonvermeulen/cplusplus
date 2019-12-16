#include "DrawableFactory.hpp"

DrawableFactory* DrawableFactory::instance = 0;

DrawableFactory* DrawableFactory::getInstance() {
  if (instance == 0) {
    instance = new DrawableFactory();
  }
  return instance;
};

Drawable* DrawableFactory::createDrawable(Json::Value & definition) {
  try {
    std::string type = definition["type"].asString();
    if (type == "Rectangle") return Rectangle::fromJsonValue(definition);
    if (type == "Line") return Line::fromJsonValue(definition);
    if (type == "Circle") return Circle::fromJsonValue(definition);
    else exit(-1);
  } catch (std::exception & e) {
    throw e;
    /* implement exception handling 
    for example type not found on definition */
  }
};
