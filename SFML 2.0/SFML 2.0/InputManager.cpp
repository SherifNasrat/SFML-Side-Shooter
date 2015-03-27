#include "InputManager.h"


InputManager::InputManager(void)
{

}
InputManager::~InputManager(void)
{

}
bool InputManager::KeyPressed(sf::Keyboard::Key key)
{
	if(event.key.code ==key)
		return true;
	return false;
}
void InputManager::Update(sf::Event event)
{
	this->event = event;
}
bool InputManager::KeyPressed(std::vector <sf::Keyboard::Key> keys)
{
	for(int i=0; i<keys.size(); i++)
	{
		if(event.key.code == keys[i])
			return true;
		return false;
	}
}
bool InputManager::KeyReleased(sf::Keyboard::Key key)
{
	if(event.key.code == key && event.type == sf::Event::KeyPressed)
		return true;
	return false;
}
bool InputManager::KeyReleased(std::vector <sf::Keyboard::Key> keys)
{
	for(int i=0 ; i<keys.size(); i++)
	{
		if(KeyReleased(keys[i]))
			return true;
	}
		return false;
	
}
bool InputManager::KeyDown(sf::RenderWindow &window, sf::Keyboard::Key keys)
{
	if(sf::Keyboard::isKeyPressed(keys))
		return true;
	return false;
}
bool InputManager::KeyDown(sf::RenderWindow &window, std::vector <sf::Keyboard::Key> keys)
{
	for(int i=0; i<keys.size(); i++)
	{
		if(sf::Keyboard::isKeyPressed(keys[i]))
		return true;
		return false;
	}
}
