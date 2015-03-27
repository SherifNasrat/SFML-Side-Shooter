#include<SFML/Graphics.hpp> 
#include<iostream>
#include<stdio.h>
#include<conio.h>
 
int main()
{
    enum Direction { Down, Left, Right, Up };
 
	sf::RenderWindow Window(sf::VideoMode(800, 600,32),  "Keyboard Input" ); 
 
    sf::Texture texture; 
    sf::Sprite sprite; 
     
    sf::Clock clock;
    sf::Vector2i source(0, Down);
 
    int frameCounter = 0, switchFrame = 100,frameSpeed = 500;
 
    if(!texture.loadFromFile( "mega.png" ))
        std::cout <<  "could not locate the specified file"  << std::endl; 
    else
        sprite.setTexture(texture);
 
    while(Window.isOpen())
    {
        sf::Event Event; 
        while(Window.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
                Window.close();
        }
 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            source.y = Direction::Down;
			
			
			source.x++;
			if(source.x*100>= texture.getSize().x)
				source.x=0;
            sprite.move(0.06, 0); 
			
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            source.y = Direction::Down; 
			source.x++;
			if(source.x*100>= texture.getSize().x)
				source.x = 0;
            sprite.move(0, 0.06);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            source.y = Direction::Right; 
			source.x++;
			if(source.x*100 >= texture.getSize().x)
				source.x = 0;
            sprite.move(0.06, 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            source.y = Direction::Left; 
			source.x++;
			if(source.x*100 >= texture.getSize().x)
				source.x = 0;
            sprite.move(-0.06, 0);
        }
 
        frameCounter += frameSpeed *clock.restart().asSeconds();
        if(frameCounter >= switchFrame)
        {
            source.x++; 
 
            if(source.x*100 >= texture.getSize().x)
                source.x = 0;
 
            frameCounter = 0;
        }
 
        sprite.setTextureRect(sf::IntRect(source.x*100, source.y * 170, 100, 170));
 
        Window.clear(); 
        Window.draw(sprite);
        Window.display();
    }
    return 0; 
}