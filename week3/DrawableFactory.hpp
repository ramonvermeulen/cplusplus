#ifndef _DRAWABLE_FACTORY_HPP
#define _DRAWABLE_FACTORY_HPP

#include <jsoncpp/json/json.h>
#include "Drawable.hpp"

class DrawableFactory {
  private:
    static DrawableFactory* instance;
    DrawableFactory(); /* private constructor to prevent instancing */
  public:
    static DrawableFactory* getInstance();
    Drawable* createDrawable(Json::Value& definition);
};

#endif
