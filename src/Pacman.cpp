#include "Pacman.h"

void Pacman::initVariables()
{
    this->movementSpeed = 5.f;
}

Pacman::Pacman(float x = 100.f, float y = 100.f)
    : pacman(this->texture)
{   
    initVariables();
    
    static_cast<void>(this->texture.loadFromFile("Assets/general_sprites.png"));
    this->pacman.setTextureRect(sf::IntRect({488, 0}, {15, 15}));
    this->pacman.setScale({15.f/15.f * 4.f, 15.f/15.f * 4.f});

    this->pacman.setPosition({x, y});
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
    // Right
    if (this->pacman.getPosition().x + 15.f*4.f >= window->getView().getSize().x){
        this->pacman.setPosition({window->getView().getSize().x - 15.f*4.f, this->pacman.getPosition().y});
    }
    // Up
    if (this->pacman.getPosition().y <= 0.f){
        this->pacman.setPosition({this->pacman.getPosition().x, 0.f});
    }
    // Down
    if (this->pacman.getPosition().y + 15.f*4.f >= window->getView().getSize().y){
        this->pacman.setPosition({this->pacman.getPosition().x, window->getView().getSize().y - 15.f*4.f});
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