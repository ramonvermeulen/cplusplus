#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>

#include "DataProviderJson.hpp"
#include "DrawableFactory.hpp"

#include "Drawable.hpp"
#include "Rectangle.hpp"

const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1080;

int main()
{
  sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Factory", sf::Style::Titlebar | sf::Style::Close};
  std::vector<Drawable*> drawables;
  DataProviderJson* dataProvider = new DataProviderJson("data.json");
  DrawableFactory* factory = DrawableFactory::getInstance();
  Json::Value data = dataProvider -> readAndParseData();

  std::for_each(data.begin(), data.end(), [&drawables, &factory](Json::Value & val) mutable {
    Drawable* drawable = factory -> createDrawable(val);
    drawables.push_back(drawable);
  });
    
  while (window.isOpen()) {
    sf::Event event;
        
    window.clear();
        
    std::for_each(drawables.begin(), drawables.end(), [&window](Drawable* drawable) {
      drawable -> handleInput();
      drawable -> draw(window);
    });

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      std::for_each(drawables.begin(), drawables.end(), [&window](Drawable* drawable) { 
        drawable -> updateActive(sf::Mouse::getPosition(window));
      });
    }

    window.display();
        
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        std::cout << "Close and save objects handling" << std::endl;
        window.close();
      }
    }
    
    sf::sleep(sf::milliseconds(10));
  }
  return 0;
}