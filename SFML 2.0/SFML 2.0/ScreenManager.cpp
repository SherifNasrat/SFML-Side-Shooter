#include "ScreenManager.h"

GameScreen *currentScreen,*newScreen;
ScreenManager &ScreenManager::GetInstance()  //Don't understand this scope.
{
	static ScreenManager instance;
	return instance;
}
ScreenManager::ScreenManager(void)
{

}


ScreenManager::~ScreenManager(void)
{

}
void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen;
}
void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
}
void ScreenManager::Update(sf::RenderWindow &window,sf::Event event)
{
	currentScreen->Update(window,event);
}
void ScreenManager::Draw(sf::RenderWindow &window)
{
	currentScreen->Draw(window);
}

void ScreenManager::AddScreen(GameScreen *screen)
{
	currentScreen->UnloadContent();
	delete currentScreen;
	currentScreen = screen;
	currentScreen->LoadContent();

}