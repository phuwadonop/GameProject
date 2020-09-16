#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My frist Game", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f,10.f);
    this->enemy.setSize(sf::Vector2f(100.f,100.f));
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(1.f);
}

// constructor/destructor
Game::Game()
{
    this->initVariables();
	this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}
//Accessor
const bool Game::running() const
{
	return this->window->isOpen();
}
void Game::pollEvent()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            this->window->close();
            break;
        }
    }
}
//Function
void Game::update()
{
	this->pollEvent();
}

void Game::render()
{
    this->window->clear();
    //draw object
    this->window->draw(this->enemy);
    this->window->display();
}
