#include "Game.h"

void Game::initWindow()
{
    unsigned int SCREEN_WIDTH = 224u * 4u, SCREEN_HEIGHT = 248u * 4u;
    this->videoMode = sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT});
    this->window = new sf::RenderWindow(this->videoMode, "Pacman");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

// Constructors and destructors
Game::Game()
    : pacman(100.f, 100.f), map("Assets/map.txt", this->tilesheet)
{
    this->initWindow();
    static_cast<void>(this->tilesheet.loadFromFile("Assets/map28x29.png"));
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->sfmlEvent = this->window->pollEvent())
        {
            if (this->sfmlEvent->is<sf::Event::Closed>())
            {   
                this->window->close();
                break;
            }
        }
}


void Game::update()
{
    this->pollEvents();

    this->pacman.update(this->window);
}


void Game::render()
{
    this->window->clear(sf::Color::Black);
    this->map.render(this->window);

    // Render stuff
    this->pacman.render(this->window);

    // Render end
    this->window->display();
}
