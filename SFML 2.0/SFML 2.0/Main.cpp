#include<SFML/Graphics.hpp> 
#include<iostream>
#include <Windows.h>
#include <stdlib.h>     
#include <time.h>   
#include <stdio.h>   
using namespace std;

int main()
{

	enum Direction { Right, Left , Attack, Up , Down };
	 srand (time(NULL)); //Seeding the random number function.
	  sf::Vector2i Scarab; 
	  sf::Vector2i Fire;
	  Fire.x=0;
	  Fire.y=0;
	  int bugdeath_counter=0; // Counts the number of collision for the bug. 
	 bool bugdestroy=true; 
	 bool playerdeath=true;
	 bool FireShooting=false;
	 int playerdeath_counter=0;
	 bool Home=true;
	//----------------Loading the Render Window---------------------------------------------------------------------------------------------------
	 sf::RenderWindow Window(sf::VideoMode(1600, 900,32),  "ESSGB Game",sf::Style::Fullscreen); 
	//============================================================================================================================================
	 




	 //-------------------------------Loading the Sprites and Textures that are going to be used--------------------------------------------------
	sf::Texture texture; 
	sf::Texture enemy1;
	sf::Texture BG1;
	sf::Texture Fb;
	sf::Texture SplashScreen;
	sf::Texture HomeScreen;
	sf::Sprite player; 
	sf::Sprite scarab;
	sf::Sprite BG;
	sf::Sprite Fireball;
	sf::Sprite SC ;
	sf::Sprite HS ;
	//============================================================================================================================================

	
	
	
	sf::Vector2i source(0, Right); 

	
	//---------------Loading the Textures from the .png files-----------------------------------------------------------------------------------------------------
	if(!texture.loadFromFile( "Pharaoh2.png" ))
		std::cout <<  "could not locate the specified file"  << std::endl; 
	else
		player.setTexture(texture);
	    texture.isSmooth();
	
	if(!enemy1.loadFromFile("Scarab2.png"))
			std::cout <<  "could not locate the specified file"  << std::endl; 
	else
		scarab.setTexture(enemy1);
	scarab.setPosition(1500,200);
	if(!BG1.loadFromFile("Map.png"))
		std::cout<< "Could not locate the specified file" << std::endl;
	else
		BG.setTexture(BG1);
	if(!Fb.loadFromFile("Fireball.png"))
		std::cout<<"Could not Located the specified file" << std:: endl;
	else 
		Fireball.setTexture(Fb);
	Fireball.setPosition(player.getPosition().x+50,player.getPosition().y+20);
	if(!HomeScreen.loadFromFile("hds.png"))
		std::cout<<"Could not Located the specified file" << std:: endl;
	else 
		HS.setTexture(HomeScreen);
	if(!SplashScreen.loadFromFile("Team Gb.png"))
		std::cout<<"Could not locate the specified file"<< std::endl;
	else
		SC.setTexture(SplashScreen);
	//============================================================================================================================================================
	while(Window.isOpen()) //Gameloop
	{
		
		sf::Event Event; 
		while(Window.pollEvent(Event))
		 {
			if(Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
				Window.close();
		 }
		//-----------------------------------Animating the Pharaoh------------------------------------------------------------------------------------------------
	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		 {
			source.y = Direction::Up;
			
			    if(player.getPosition().y >= -40)
				player.move(0, -0.4); 
			

		 }
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		 {    
			source.y = Direction::Down; 
			    if(player.getPosition().y < 700)
				player.move(0,0.4 );

		 }
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		 {
		
			source.y = Direction::Right; 
		    if(player.getPosition().x < 1400)
			player.move(0.4, 0);

		 }
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		 {
			source.y = Direction::Left; 
		    if(player.getPosition().x >= -40)
			player.move(-0.4, 0);
		 }
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		 {  FireShooting= true;
			source.y=Attack;
			Fireball.setPosition(player.getPosition().x+215,player.getPosition().y+20);
	
			
			          
			
		 }
		
	 
	 	else
			source.y=Direction::Up;
			Fireball.move(0.9,0);
			//============================================================================================================================================





			//::::::::::::::::::COLLISIONS:                        
	
		   
		//-----------------Player Death on 3 Collisions---------------------------------------------------------------------------------------------------
		if(player.getGlobalBounds().intersects(scarab.getGlobalBounds())== true)
		{   playerdeath_counter++;
		   if(playerdeath_counter == 1263)
			playerdeath = false;
			
		}
	   //=================================================================================================================================================


		//----------------Fireball Collision--------------------------------------------------------------------------------------------------------------
		if(scarab.getGlobalBounds().intersects(Fireball.getGlobalBounds())==true)
		{
			bugdeath_counter++;
			if(bugdeath_counter >0)
				{
					bugdestroy = false;
					scarab.setPosition(1650,950);
			    }
		}
		//============================================================================================================================================

		
	    //----------------Generating Random numbers for the Co-Ordinates of the Flying Bugs-----------------------------------------------------------
		Scarab.x = 0;
	    Scarab.y  = rand() % 650 + 100;
		//============================================================================================================================================

		//-----------------------Adding Velocity to the bug's movement--------------------------------------------------------------------------------
		scarab.move(-0.7,0);
		if(scarab.getPosition().x < -1600)
			scarab.setPosition(1500,Scarab.y);
	  //==============================================================================================================================================
	

		

	
	    

		player.setTextureRect(sf::IntRect(source.x*250, source.y * 240, 250, 240));
		scarab.setTextureRect(sf::IntRect(0, 0, 100,60 ));
		BG.setTextureRect(sf::IntRect(0, 0, 1600,900 ));
		Window.clear(); 
		Window.draw(BG);

		if(playerdeath == true)
		{
			Window.draw(player);
		}

		if(FireShooting == true )
		Window.draw(Fireball);

		
		Window.draw(scarab);
	
		

		
		Window.display();
	}
	return 0; 
}