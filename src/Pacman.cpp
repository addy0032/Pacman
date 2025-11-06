#include "Pacman.h"

void Pacman::initVariables()
{
    this->movementSpeed = 2.5f;
}

Pacman::Pacman(float x, float y)
    : pacman(this->texture)
{   
    initVariables();

    static_cast<void>(this->texture.loadFromFile("Assets/general_sprites.png"));
    pacman.setTextureRect(sf::IntRect({489, 1}, {13, 13}));

    this->pacman.setPosition(sf::Vector2f(x, y));
}

void Pacman::updateInput()
{
    // Keyboard Input
    //Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->pacman.move({-this->movementSpeed, 0.f});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->pacman.move({this->movementSpeed, 0.f});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->pacman.move({0.f, -this->movementSpeed});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->pacman.move({0.f, this->movementSpeed});
    }
}

void Pacman::update()
{

    this->updateInput();
}

void Pacman::render(sf::RenderWindow *window)
{
    this->update();
    window->draw(pacman);
}