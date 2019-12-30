#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>

#include "DataProviderJson.hpp"
#include "DrawableFactory.hpp"
#include "Drawable.hpp"
#include "Rectangle.hpp"
#include "Constants.hpp"


void createAndFillDrawables(std::vector<Drawable*> & drawables, DataProviderJson* dataProvider) {
  DrawableFactory* factory = DrawableFactory::getInstance();
  Json::Value data = dataProvider -> readAndParseData();

  std::for_each(data.begin(), data.end(), [&drawables, &factory](Json::Value & val) mutable {
    Drawable* drawable = factory -> createDrawable(val);
    drawables.push_back(drawable);
  });
}


void renderFrame(std::vector<Drawable*> & drawables, sf::RenderWindow & window) {        
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
}


void saveDataToFile(std::vector<Drawable*> & drawables, DataProviderJson* dataProvider) {
  Json::Value root;
  std::for_each(drawables.begin(), drawables.end(), [&root](Drawable* drawable) {
    root.append(drawable -> toJsonValue());
  });
  dataProvider -> writeData(root);
}


int main() {
  sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Factory", sf::Style::Titlebar | sf::Style::Close};
  DataProviderJson* dataProvider = new DataProviderJson(DATA_FILE);
  std::vector<Drawable*> drawables;

  createAndFillDrawables(drawables, dataProvider);
    
  while (window.isOpen()) {
    sf::Event event;

    renderFrame(drawables, window);
        
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        saveDataToFile(drawables, dataProvider);
        window.close();
      }
    }
    
    sf::sleep(sf::milliseconds(10));
  }
  return 0;
}