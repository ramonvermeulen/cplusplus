#ifndef _DRAWABLE_FACTORY_HPP
#define _DRAWABLE_FACTORY_HPP

#include <jsoncpp/json/json.h>
#include "Drawable.hpp"

class DrawableFactory {
  private:
    DrawableFactory() { }; /* private constructor to prevent instancing */
    static DrawableFactory* instance;
  public:
    static DrawableFactory* getInstance();
    Drawable* createDrawable(Json::Value& definition);
};

#endif
