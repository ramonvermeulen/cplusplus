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
    // DataProviderJson* dataProvider = new DataProviderJson("data.json");
    // DrawableFactory* factory = DrawableFactory::getInstance();
    // Json::Value data = dataProvider -> readAndParseData();
    // std::for_each(data.begin(), data.end(), [drawables, factory](Json::Value & val) mutable { 
    //     Drawable* drawable = factory -> createDrawable(val);
    //     drawables.push_back(drawable);
    // });
    std::cout << "woop woop" << std::endl;
    Rectangle* rec = new Rectangle(sf::Vector2f{0, 0}, sf::Color::Green, true, sf::Vector2f{ 5.0, 5.0 });
    // drawables.push_back(new Rectangle(sf::Vector2f{0, 0}, sf::Color::Green, true, sf::Vector2f{ 5.0, 5.0 }));
    
    std::cout<< "ben er langs swa";
    while (window.isOpen()) {
        sf::Event event;

        window.clear();

        rec -> draw(window);
        /* draw handling */
        // std::cout >> drawables[0];
        // drawables[0] -> draw(window);
        // for()
        // std::for_each(drawables.begin(), drawables.end(), [window](Drawable* drawable) { drawable -> draw(window); });

        window.display();
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}