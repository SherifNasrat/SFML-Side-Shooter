#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Animation
{
public:
	Animation(void);
	~Animation(void);
	virtual void LoadContent(std::string text, sf::Image image,sf::Vector2f position);
	virtual void UnloadContent();
	virtual void Update();
	void Draw(sf::RenderWindow &window);
protected:
	float alpha;
	std::string preText;
	sf::Text text;
	sf::Image image;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Color textColor;

	sf::IntRect sourceRect;

private:

};

