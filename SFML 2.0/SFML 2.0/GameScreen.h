#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.h"

class GameScreen
{
public:
	GameScreen(void);
	~GameScreen(void);
	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &window,sf::Event event);
	virtual void Draw(sf::RenderWindow &window);
protected:
	InputManager input;
		std::vector <sf::Keyboard::Key> keys;
};

