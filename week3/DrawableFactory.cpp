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
    if (type == RECTANGLE_TYPE) return Rectangle::fromJsonValue(definition);
    if (type == LINE_TYPE) return Line::fromJsonValue(definition);
    if (type == CIRCLE_TYPE) return Circle::fromJsonValue(definition);
    if (type == IMAGE_TYPE) return Image::fromJsonValue(definition);
    else {
      std::cout << "DrawableFactory could not create object of type: " << type << std::endl;
      std::cout << "Closing program" << std::endl;
      exit(-1);
    }
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
    throw;
  }
};
