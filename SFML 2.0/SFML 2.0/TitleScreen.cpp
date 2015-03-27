#include "TitleScreen.h"


TitleScreen::TitleScreen(void)
{
}


TitleScreen::~TitleScreen(void)
{
}
void TitleScreen::LoadContent()
{
	if(!font.loadFromFile("SIXTY.ttf"))
		std::cout<< "Could not find the specified file"<< std::endl;
	text.setString("TitleScreen");
	text.setFont(font);
		keys.push_back(sf::Keyboard::Z);
	keys.push_back(sf::Keyboard::Return);
}
void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}
void TitleScreen::Update(sf::RenderWindow &window,sf::Event event)
{
		input.Update(event);
		if(input.KeyDown(window,keys))
	ScreenManager::GetInstance().AddScreen(new SplashScreen);
}
void TitleScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
}