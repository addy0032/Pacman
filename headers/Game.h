#pragma once

#include "Pacman.h"
#include "TileMap.h"
class Game{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        std::optional<sf::Event> sfmlEvent;

        Pacman pacman;
        TileMap map;
        sf::Texture tilesheet;

        void initWindow();

    public:
        Game();
        ~Game();

        const bool running() const;
        void pollEvents();

        void update();
        void render();
};