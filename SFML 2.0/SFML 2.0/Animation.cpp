#include "Animation.h"


Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}
void Animation::LoadContent(std::string text, sf::Image image,sf::Vector2f position)
{
	this->preText = text;
	this->image = image;
	this->position = position;
	alpha = 1.0f;
	textColor = sf::Color(114,77,255);
	sprite.setTexture(image);
	this->text.setString(text);


}
void Animation::UnloadContent()
{

}
void Animation::Update()
{

}
void Animation::Draw(sf::RenderWindow &window)
{
	std::string str = text.getString();
	if(str != "")
		window.draw(text);
	if(sprite.getTexture() != NULL)
		window.draw(sprite);
}
 
