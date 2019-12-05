#include "DrawableFactory.hpp"


DrawableFactory* DrawableFactory::instance = 0;

DrawableFactory* DrawableFactory::getInstance() {
  if(instance == 0) {
    return new DrawableFactory();
  }
  return instance;
}

Drawable* DrawableFactory::createDrawable(Json::Value & definition) {
  try {

  } catch (...) {
    /* implement exception handling 
    for example type not found on definition */
  }
}