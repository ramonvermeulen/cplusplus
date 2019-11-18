#include <SFML/Graphics.hpp>
#include <list>

#include "square.hpp"
#include "wall.hpp"
#include "shape.hpp"
#include "ball.hpp"

const int SCREEN_HEIGHT = 480.0;
const int SCREEN_WIDTH = 640.0;
const int WALL_SIZE = 10.0;

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Muren en stuiteren", sf::Style::Titlebar | sf::Style::Close};
    square square{ sf::Vector2f{ SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 4 * 3) }, 20.0 };
    wall top_wall { sf::Vector2f{ 0.0, 0.0 }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };
    wall right_wall { sf::Vector2f{ SCREEN_WIDTH - WALL_SIZE, 0.0 }, WALL_SIZE, SCREEN_HEIGHT, sf::Color::Green };
    wall bottom_wall { sf::Vector2f{ 0.0, SCREEN_HEIGHT - WALL_SIZE }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };
    wall left_wall { sf::Vector2f{ 0.0, 0.0 }, WALL_SIZE, SCREEN_WIDTH, sf::Color::Green };
    ball ball { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Yellow, 10.0, 325, 5 };

    while(window.isOpen()) {
        sf::Event event;
        square.handle_input(window);

        window.clear();
        square.draw(window);
        ball.draw(window);
        top_wall.draw(window);
        right_wall.draw(window);
        bottom_wall.draw(window);
        left_wall.draw(window);
        window.display();
        
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::sleep(sf::milliseconds(20));
    }
    return 0;
}