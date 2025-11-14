#include "TileMap.h"
#include <fstream>
#include <iostream>

TileMap::TileMap(const std::string& filename, sf::Texture& tilesheet)
    : tilesheet(tilesheet)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Failed to load map file\n";
        return;
    }
    
    std::vector<std::string> grid;
    std::string line;

    while(std::getline(file, line))
        grid.push_back(line);
    
    const int ROWS = grid.size();
    const int COLS = grid[0].size();

    this->tiles.resize(ROWS, std::vector<Tile>(COLS, Tile(this->tilesheet, sf::IntRect({0, 0}, {8, 8}), ' ')));

    for (int y = 0; y < ROWS; ++y)
    {
        for (int x = 0; x < COLS; ++x)
        {
            this->tiles[y][x] = Tile(this->tilesheet, sf::IntRect({x*8, y*8}, {8, 8}), grid[y][x]);
            this->tiles[y][x].scaleTile(4.f, 4.f);
        }
    }
}


void TileMap::render(sf::RenderWindow* window) 
{   
    const int ROWS = tiles.size();
    const int COLS = tiles[0].size();
    for (int y = 0; y < ROWS; ++y)
    {
        for (int x = 0; x < COLS; ++x)
        {
            this->tiles[y][x].render(window, x * this->tileSize, y * this->tileSize);
        }
    }
}