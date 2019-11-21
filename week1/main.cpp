#include <SFML/Graphics.hpp>
#include <list>

#include "square.hpp"
#include "wall.hpp"
#include "shape.hpp"
#include "ball.hpp"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
const float WALL_SIZE = 10.0;
const int AMOUNT_OF_SCREEN_OBJECTS = 6;

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Muren en stuiteren", sf::Style::Titlebar | sf::Style::Close};
    
    Shape* screen_objects[AMOUNT_OF_SCREEN_OBJECTS];
    screen_objects[0] = new Square { sf::Vector2f{ SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 4 * 3) }, 20.0 };
    screen_objects[1] = new Ball { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Yellow, 35.0, 180, 2 };
    screen_objects[2] = new Wall { sf::Vector2f{ 0.0, 0.0 }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };  
    screen_objects[3] = new Wall { sf::Vector2f{ SCREEN_WIDTH - WALL_SIZE, 0.0 }, WALL_SIZE, SCREEN_HEIGHT, sf::Color::Green };
    screen_objects[4] = new Wall { sf::Vector2f{ 0.0, SCREEN_HEIGHT - WALL_SIZE }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };
    screen_objects[5] = new Wall { sf::Vector2f{ 0.0, 0.0 }, WALL_SIZE, SCREEN_WIDTH, sf::Color::Green }; 

    // screen_objects[2] = new Ball { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Blue, 35.0, 225, 15 };
    // screen_objects[3] = new Ball { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Red, 20.0, 70, 20 };
    // screen_objects[4] = new Ball { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Cyan, 10.0, 315, 30 };

    // Wall top_wall { sf::Vector2f{ 0.0, 0.0 }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };    
    // Wall right_wall { sf::Vector2f{ SCREEN_WIDTH - WALL_SIZE, 0.0 }, WALL_SIZE, SCREEN_HEIGHT, sf::Color::Green };
    // Wall bottom_wall { sf::Vector2f{ 0.0, SCREEN_HEIGHT - WALL_SIZE }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };
    // Wall left_wall { sf::Vector2f{ 0.0, 0.0 }, WALL_SIZE, SCREEN_WIDTH, sf::Color::Green };    


    while(window.isOpen()) {
        sf::Event event;

        static_cast<Square*>(screen_objects[0]) -> handle_input(window);

        window.clear();
        for (int i = 0; i < AMOUNT_OF_SCREEN_OBJECTS; i++) {
            screen_objects[i] -> draw(window);
        }
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