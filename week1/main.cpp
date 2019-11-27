#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "square.hpp"
#include "wall.hpp"
#include "shape.hpp"
#include "ball.hpp"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
const float WALL_SIZE = 10.0;
const int AMOUNT_OF_SCREEN_OBJECTS = 6;


void collision_handling(Shape* screen_objects[AMOUNT_OF_SCREEN_OBJECTS]) {
  for (int i = 0; i < AMOUNT_OF_SCREEN_OBJECTS; i++) {
        if (dynamic_cast<Ball*>(screen_objects[i])) {
            Ball* ball = dynamic_cast<Ball*>(screen_objects[i]);

            for (int e = 0; e < AMOUNT_OF_SCREEN_OBJECTS; e++) {
                if (e == i) continue;
                std::pair<bool, sf::Vector2f> colliding = ball -> collider.is_colliding(screen_objects[e]);

                if (colliding.first) {
                    if(colliding.second.x > colliding.second.y) {
                        ball -> invert_move_x(colliding.second.x);
                    } else {
                        ball -> invert_move_y(colliding.second.y);
                    }
                }
            }
        }   
    }
}

void draw_handling(Shape* screen_objects[AMOUNT_OF_SCREEN_OBJECTS], sf::RenderWindow & window) {
    for (int i = 0; i < AMOUNT_OF_SCREEN_OBJECTS; i++) {
        screen_objects[i] -> draw(window);
    }
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Muren en stuiteren", sf::Style::Titlebar | sf::Style::Close};
    
    Shape* screen_objects[AMOUNT_OF_SCREEN_OBJECTS];
    screen_objects[0] = new Square { sf::Vector2f{ SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 4 * 3) }, 20.0 };
    screen_objects[1] = new Wall { sf::Vector2f{ SCREEN_WIDTH / 2, WALL_SIZE / 2 }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };  // top wall
    screen_objects[2] = new Wall { sf::Vector2f{ SCREEN_WIDTH - WALL_SIZE / 2, SCREEN_HEIGHT / 2 }, WALL_SIZE, SCREEN_HEIGHT, sf::Color::Green }; // right wall
    screen_objects[3] = new Wall { sf::Vector2f{ SCREEN_WIDTH / 2, SCREEN_HEIGHT - WALL_SIZE / 2 }, SCREEN_WIDTH, WALL_SIZE, sf::Color::Green };
    screen_objects[4] = new Wall { sf::Vector2f{ WALL_SIZE / 2, SCREEN_HEIGHT / 2 }, WALL_SIZE, SCREEN_WIDTH, sf::Color::Green }; 
    // screen_objects[5] = new Ball { sf::Vector2f{ 100, SCREEN_HEIGHT / 2 }, sf::Color::Yellow, 15.0, 90, 2 };
    screen_objects[5] = new Ball { sf::Vector2f{ 200, SCREEN_HEIGHT / 2 }, sf::Color::Blue, 35.0, 225, 5 };
    // screen_objects[7] = new Ball { sf::Vector2f{ 300, SCREEN_HEIGHT / 2 }, sf::Color::Red, 20.0, 70, 5 };
    // screen_objects[8] = new Ball { sf::Vector2f{ 400, SCREEN_HEIGHT / 2 }, sf::Color::Cyan, 10.0, 315, 8 };   


    while (window.isOpen()) {
        sf::Event event;
        static_cast<Square*>(screen_objects[0]) -> handle_input(window);

        window.clear();

        collision_handling(screen_objects);
        draw_handling(screen_objects, window);

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