#include "SplashScreen.h"


SplashScreen::SplashScreen(void)
{

}


SplashScreen::~SplashScreen(void)
{

}
void SplashScreen::LoadContent()
{
	if(!font.loadFromFile("SIXTY.ttf"))
		std::cout<< "Could not find the specified file"<< std::endl;
	text.setString("SplashScreen");
	text.setFont(font);
	keys.push_back(sf::Keyboard::Z);
	keys.push_back(sf::Keyboard::Return);
}
void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}
void SplashScreen::Update(sf::RenderWindow &window,sf::Event event)
{
	input.Update(event);
	if(input.KeyPressed(keys))
	ScreenManager::GetInstance().AddScreen(new TitleScreen);
}
void SplashScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
}