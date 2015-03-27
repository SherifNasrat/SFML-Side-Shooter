#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class InputManager
{
public:
	InputManager(void);
	~InputManager(void);
	bool KeyPressed(sf::Keyboard::Key key);
	bool KeyPressed(std:: vector <sf::Keyboard::Key> keys);
	bool KeyReleased(sf::Keyboard::Key key);
	bool KeyReleased(std::vector <sf::Keyboard::Key> keys);
	void Update(sf::Event event);
	bool KeyDown(sf::RenderWindow &window,sf::Keyboard::Key key);
	bool KeyDown(sf::RenderWindow &window,std::vector <sf::Keyboard::Key> keys);
protected:
private:
	sf::Event event;
};

