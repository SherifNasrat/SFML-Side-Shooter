#pragma once
#include "GameScreen.h"
#include "ScreenManager.h"
#include "SplashScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class TitleScreen :  public GameScreen
{
public:
	TitleScreen(void);
	~TitleScreen(void);
     void LoadContent();
	 void UnloadContent();
	 void Update(sf::RenderWindow &window,sf::Event event);
	 void Draw(sf::RenderWindow &window);
private:
	sf::Text text;
	sf::Font font;
};

