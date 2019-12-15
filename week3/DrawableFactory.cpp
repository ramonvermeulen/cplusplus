#include "DrawableFactory.hpp"
#include "Rectangle.hpp"
#include "Drawable.hpp"
#include <iostream>

DrawableFactory* DrawableFactory::instance = 0;

DrawableFactory* DrawableFactory::getInstance() {
  if(instance == 0) {
    instance = new DrawableFactory();
  }
  return instance;
};

Drawable* DrawableFactory::createDrawable(Json::Value & definition) {
  try {
    std::string type = definition["type"].asString();
    if (type == "Rectangle") return Rectangle::fromJsonValue(definition);
    else exit(-1);
  } catch (std::exception & e) {
    throw e;
    /* implement exception handling 
    for example type not found on definition */
  }
};
