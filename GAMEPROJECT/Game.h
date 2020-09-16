#ifndef GAME_H
#define GAME_H

#include<iostream>
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

	//Game Object
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
	void pollEvent();
	void update();
	void render();
};

#endif // !GAME_H