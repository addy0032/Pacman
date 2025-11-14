#pragma once
#include <SFML/Graphics.hpp>

class Tile
{
    private:
        sf::Sprite tile;
    
    public:
        Tile(const sf::Texture& texture, const sf::IntRect& Rect, char tileType);

        void render(sf::RenderWindow* window, float x, float y);

        void scaleTile(float x, float y);
};