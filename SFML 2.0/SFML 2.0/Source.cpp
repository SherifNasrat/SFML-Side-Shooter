#include <iostream>
#include "ScreenManager.h"
#include <SFML/Graphics.hpp>

using namespace std;
int main()
{
	sf::RenderWindow Window(sf::VideoMode(800,600,32),"SiGMA");
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();
	Window.setKeyRepeatEnabled(false);

	while(Window.isOpen())
	{
		sf::Event event;
		if(Window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed ||event.type == sf::Keyboard::Escape)
				Window.close();
			


		}
		Window.clear();
		ScreenManager::GetInstance().Update(Window,event);
		ScreenManager::GetInstance().Draw(Window);
		Window.display();
	}
	return 0;
}