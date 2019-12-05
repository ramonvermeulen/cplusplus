#include <SFML/Graphics.hpp>
#include <iostream>
#include <jsoncpp/json/json.h>

#include <fstream>
#include <algorithm>


const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1080;

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Factory", sf::Style::Titlebar | sf::Style::Close}; 
    // std::vector<Drawable*> drawables; 

    // std::ifstream stream("data.json");
    // Json::Reader reader;
    // Json::Value parsed_data;

    // reader.parse(stream, parsed_data);

    // std::for_each(parsed_data.begin(), parsed_data.end(), [](Json::Value & val) { std::cout << val << std::endl; });


    while (window.isOpen()) {
        sf::Event event;

        window.clear();

        /* draw handling */

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