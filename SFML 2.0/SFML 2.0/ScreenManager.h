#pragma once
#include <iostream>
#include <string>
#ifndef SCREENMANAGER_H
#define SCREENAMANGER_H
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include <SFML/Graphics.hpp>
class ScreenManager
{
public:

	~ScreenManager();
	static ScreenManager &GetInstance();

	void Initialize();
	void LoadContent();
	void Update(sf::RenderWindow &window,sf::Event event);
	void Draw(sf::RenderWindow &window);
	void AddScreen(GameScreen *screen);
protected:
private:
		ScreenManager();
		ScreenManager(ScreenManager const&);
		void operator=(ScreenManager const&);
			std::string text;
		//	GameScreen *currentScreen,*newScreen;
};
#endif // SCREENMANAGER_H
