#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Pacman{
    private:
        sf::Texture texture;
        sf::Sprite pacman;

        float movementSpeed;

        void initVariables();
    public:
        Pacman(float x, float y);

        void updateInput();
        void updateWindowBoundsCollision(const sf::RenderWindow* window);
        void update(const sf::RenderWindow* window);
        void render(sf::RenderWindow* window);
};