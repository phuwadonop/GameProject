#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>
#include<ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse position
	sf::Vector2i mousePosWindow;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;


	//Game Object
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private FUntion
	void initVariables(); 
	void initWindow();
	void initEnemies();

public: 
	//constructor/destructor
	Game();
	virtual ~Game();
	//Accessor
	const bool running() const ;

	//Function
	void spawnEnemy();

	void pollEvent();
	void updateMousePositions();
	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};

#endif // !GAME_H