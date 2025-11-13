#include "Game.h"

void Game::initWindow()
{
    unsigned int SCREEN_WIDTH = 384u, SCREEN_HEIGHT = 216u;
    this->videoMode = sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT});
    this->window = new sf::RenderWindow(this->videoMode, "Pacman");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

// Constructors and destructors
Game::Game()
    : pacman(100.f, 100.f)
{
    this->initWindow();
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

    // Render stuff
    this->pacman.render(this->window);

    // Render end
    this->window->display();
}
