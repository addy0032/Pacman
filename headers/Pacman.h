#pragma once
#include <SFML/Graphics.hpp>

class Pacman{
    private:
        sf::Texture texture;
        sf::Sprite pacman;

        float movementSpeed;

        void initVariables();
    public:
        Pacman(float x, float y);

        void handleInput(float screenWidth);
        void updateInput();
        void update();
        void render(sf::RenderWindow* window);
};