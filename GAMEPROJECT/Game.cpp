#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;

    //Game logic 
    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;

}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My frist Game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
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

//Function
void Game::spawnEnemy()
{
    /*
        return

        spawns enemies and set  thier color and position
        -set a random position.
        -set a random color.
        -Add enemy to the vector.
    */

    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );
    this->enemy.setFillColor(sf::Color::Yellow);
    //Spawn enemy
    this->enemies.push_back(this->enemy);
    //remove ememies
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
void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}
void Game::updateEnemies()
{
    /*
        @return void

        updates the enemy spawn timer and spawns enemies
        when the total amount of enemies is smaller than max.
        Move enemies downwards.
        Removes the enemies at the edge of  the screen. //todo
    */

    // updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //spawn enemies and reset timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }    
        else
            this->enemySpawnTimer += 1.f;
    }
    //Move enemies
    for (auto &enemy : this->enemies)
    {
        enemy.move(0.f, 1.f);
    }
}
void Game::update()
{
	this->pollEvent();

    this->updateMousePositions();

    this->updateEnemies();
}

void Game::renderEnemies()
{
    for (auto &enemy : this->enemies)
    {
        this->window->draw(enemy);
    }
}

void Game::render()
{
    this->window->clear();
    //draw object
    this->renderEnemies();
    this->window->display();
}
