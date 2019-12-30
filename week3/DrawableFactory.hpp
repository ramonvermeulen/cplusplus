#ifndef _DRAWABLE_FACTORY_HPP
#define _DRAWABLE_FACTORY_HPP

#include "Drawable.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Image.hpp"
#include <iostream>

class DrawableFactory {
  private:
    DrawableFactory() { }; /* private constructor to prevent instancing */
    static DrawableFactory* instance;
  public:
    static DrawableFactory* getInstance();
    Drawable* createDrawable(Json::Value& definition);
};

#endif
