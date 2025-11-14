#include "Tile.h"


Tile::Tile(const sf::Texture &texture, const sf::IntRect &Rect, char tileType)
    : tile(texture)
{
    this->tile.setTextureRect(Rect);

    // Will later use the tileType to set the tile properties like passable, score points, powerup, etc
}

void Tile::render(sf::RenderWindow* window, float x, float y)
{
    this->tile.setPosition({x, y});
    window->draw(tile);
}

void Tile::scaleTile(float x, float y)
{
    this->tile.setScale({x, y});
}
