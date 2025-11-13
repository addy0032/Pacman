#include "Pacman.h"

void Pacman::initVariables()
{
    this->movementSpeed = 2.5f;
}

Pacman::Pacman(float x = 100.f, float y = 100.f)
    : pacman(this->texture)
{   
    initVariables();

    static_cast<void>(this->texture.loadFromFile("Assets/general_sprites.png"));
    pacman.setTextureRect(sf::IntRect({489, 1}, {13, 13}));

    this->pacman.setPosition(sf::Vector2f(x, y));
}

void Pacman::updateInput()
{
    // Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->pacman.move({-this->movementSpeed, 0.f});
    }
    // Right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->pacman.move({this->movementSpeed, 0.f});
    }
    // Up
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->pacman.move({0.f, -this->movementSpeed});
    }
    // Down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->pacman.move({0.f, this->movementSpeed});
    }
}

void Pacman::updateWindowBoundsCollision(const sf::RenderWindow *window)
{
    // Left
    if (this->pacman.getPosition().x <= 0.f){
        this->pacman.setPosition({0.f, this->pacman.getPosition().y});
    }
    if (this->pacman.getPosition().x + 13.f >= window->getView().getSize().x){
        this->pacman.setPosition({window->getView().getSize().x - 13.f, this->pacman.getPosition().y});
    }
    if (this->pacman.getPosition().y <= 0.f){
        this->pacman.setPosition({this->pacman.getPosition().x, 0.f});
    }
    if (this->pacman.getPosition().y + 13.f >= window->getView().getSize().y){
        this->pacman.setPosition({this->pacman.getPosition().x, window->getView().getSize().y - 13.f});
    }
}

void Pacman::update(const sf::RenderWindow* window)
{
    // Keyboard input
    this->updateInput();

    // Update collision with window bounds
    this->updateWindowBoundsCollision(window);
}

void Pacman::render(sf::RenderWindow *window)
{
    window->draw(pacman);
}