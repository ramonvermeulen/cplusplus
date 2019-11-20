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
    Square square{ sf::Vector2f{ SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 4 * 3) }, 20.0 };
    // Wall top_wall { sf::Vector2f{ 0.0, 0.0 }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };    
    // Wall right_wall { sf::Vector2f{ SCREEN_WIDTH - WALL_SIZE, 0.0 }, WALL_SIZE, SCREEN_HEIGHT, sf::Color::Green };
    // Wall bottom_wall { sf::Vector2f{ 0.0, SCREEN_HEIGHT - WALL_SIZE }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };
    // Wall left_wall { sf::Vector2f{ 0.0, 0.0 }, WALL_SIZE, SCREEN_WIDTH, sf::Color::Green };
    Ball ball_one { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Yellow, 15.0, 180, 10 };
    Ball ball_two { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Blue, 35.0, 225, 15 };
    Ball ball_three { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Red, 20.0, 70, 20 };
    Ball ball_four { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, sf::Color::Cyan, 10.0, 315, 30 };
    


    while(window.isOpen()) {
        sf::Event event;
        square.handle_input(window);

        window.clear();
        square.draw(window);
        ball_one.draw(window);
        ball_two.draw(window);
        ball_three.draw(window);
        ball_four.draw(window);
        // top_wall.draw(window);
        // right_wall.draw(window);
        // bottom_wall.draw(window);
        // left_wall.draw(window);
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