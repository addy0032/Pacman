#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pacman.h"

int main()
{
    unsigned int SCREEN_WIDTH = 384u, SCREEN_HEIGHT = 216u;
    auto window = sf::RenderWindow(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Pacman");
    window.setFramerateLimit(60);

    Pacman pacman(100.f, 100.f);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }
        }

        window.clear(sf::Color::Black);
        
        pacman.render(&window);

        window.display();
    }
}