#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class TileMap
{
    private:
        std::vector<std::vector<Tile>> tiles;
        const sf::Texture& tilesheet;
        
        const int tileSize = 32;
    public:
        TileMap(const std::string& filename, sf::Texture& tilesheet);

        void render(sf::RenderWindow* window);
};