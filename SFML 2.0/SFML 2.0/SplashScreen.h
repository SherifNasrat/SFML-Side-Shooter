#pragma once
#include "GameScreen.h"
#include "TitleScreen.h"
#include "ScreenManager.h"
#include <SFML/Graphics.hpp>

#include <iostream>
class SplashScreen :  public GameScreen
{
public:
	SplashScreen(void);
	~SplashScreen(void);
     void LoadContent();
	 void UnloadContent();
	 void Update(sf::RenderWindow &window,sf::Event event);
	 void Draw(sf::RenderWindow &window);
private:
	sf::Text text;
	sf::Font font;

};

