#include <SFML/Graphics.hpp>
#include "inc/character.hpp"
#include "inc/stones.hpp"
#include <iostream>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

const int height = 800;
const int width = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(height,width), "Test");
	window.setFramerateLimit(120);

	fal::Character character(50, 50);
	fal::Stone stone(100, 100);
	sf::Vector2 characterPosition(0,0);
	sf::Vector2 stonePosition(0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::FloatRect characterBounds = (*character.Get()).getGlobalBounds();
		sf::FloatRect stoneBounds = (*stone.Get()).getGlobalBounds();

		if (characterBounds.intersects(stoneBounds))
		{
			if (character.GetHeroDirection() == 0)
			{
				(*stone.Get()).move(-2, 0);
				stone.Animate(1);
			}
			if (character.GetHeroDirection() == 1)
			{
				(*stone.Get()).move(2, 0);
				stone.Animate(0);
			}
			if (character.GetHeroDirection() == 2)
			{
				(*stone.Get()).move(0, 2);
				stone.Animate(2);
			}
			if (character.GetHeroDirection() == 3)
			{
				(*stone.Get()).move(0, -2);
				stone.Animate(2);
			}
		}
		
		//////////////////////////////////////////////////////////////////////////////////////////////////
		characterPosition.x = (*character.Get()).getPosition().x;
		characterPosition.y = (*character.Get()).getPosition().y;

		if ((characterPosition.x <= 0) && (characterPosition.y <= 0))
			(*character.Get()).setPosition(0, 0);

		else if ((characterPosition.x >= width+150) && (characterPosition.y >= height-275))
			(*character.Get()).setPosition(width+150,height-275);

		else if ((characterPosition.y >= height - 275) && (characterPosition.x >= 0))
			(*character.Get()).setPosition(characterPosition.x, height - 275);
		else if ((characterPosition.x >= width + 150) && (characterPosition.y >= 0))
			(*character.Get()).setPosition(width + 150, characterPosition.y);

		else if (characterPosition.x <= 0)
			(*character.Get()).setPosition(0, characterPosition.y);
		else if (characterPosition.y <= 0)
			(*character.Get()).setPosition(characterPosition.x, 0);
		//////////////////////////////////////////////////////////////////////////////////////////////////
		stonePosition.x = (*stone.Get()).getPosition().x;
		stonePosition.y = (*stone.Get()).getPosition().y;

		if ((stonePosition.x <= 0) && (stonePosition.y <= 0))
			(*stone.Get()).setPosition(0, 0);

		else if ((stonePosition.x >= width + 150) && (stonePosition.y >= height - 275))
			(*stone.Get()).setPosition(width + 150, height - 275);

		else if ((stonePosition.y >= height - 275) && (stonePosition.x >= 0))
			(*stone.Get()).setPosition(stonePosition.x, height - 275);
		else if ((stonePosition.x >= width + 150) && (stonePosition.y >= 0))
			(*stone.Get()).setPosition(width + 150, stonePosition.y);

		else if (stonePosition.x <= 0)
			(*stone.Get()).setPosition(0, stonePosition.y);
		else if (stonePosition.y <= 0)
			(*stone.Get()).setPosition(stonePosition.x, 0);
		//////////////////////////////////////////////////////////////////////////////////////////////////
		character.KeyboardMove();

		window.clear();

		window.draw(*stone.Get());
		window.draw(*character.Get());

		window.display();
	}

	return 0;
}