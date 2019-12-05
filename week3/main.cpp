#include <SFML/Graphics.hpp>
#include <iostream>

const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1080;

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Factory", sf::Style::Titlebar | sf::Style::Close};

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