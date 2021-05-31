#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <Windows.h>
#include "cSection.h"
#include "cBody.h"
#include "cHead.h"
#include "sXY.h"



using namespace sf;
using namespace std;

int main()
{
	cHead* snake1;
	snake1 = new cHead();
	snake1->Grow();
	int DirectionVector[1] = { -1 };

	Vector2f Velocity;
	sf::RectangleShape mHead(sf::Vector2f(20, 20));
	mHead.setFillColor(sf::Color::Magenta);
	mHead.setOrigin(10, 10);
	mHead.setPosition(500, 300);
	sf::RectangleShape mBody(sf::Vector2f(20, 20));
	mBody.setFillColor(sf::Color::Blue);
	mBody.setOrigin(10, 10);
	mBody.setPosition(600, 400);
	//sf::Vector2f directSpeed1(0.f,0.f);
	sf::Event evnt;
	sf::RenderWindow window(sf::VideoMode(800, 800), "SNAKE 2D", sf::Style::Close);
	while (window.isOpen())
	{
		window.setFramerateLimit(280);

		while (window.pollEvent(evnt))
		{

			if (evnt.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::Escape)))
			{
				window.close();
			}
			if (evnt.type == Event::KeyPressed && evnt.key.code == Keyboard::Up)
			{
				if (DirectionVector[0] == 2)
				{
					break;
				}
				else
				{
					if (DirectionVector[0] == 1)
					{
						snake1->setDirection(5);
					}
					else
					{
						DirectionVector[0] = 4;
						snake1->setDirection(4);
					}

				}
			}
			if (evnt.type == Event::KeyPressed && evnt.key.code == Keyboard::Down)
			{

				if (DirectionVector[0] == 4)
				{
					continue;
				}
				else
				{
					DirectionVector[0] = 2;
					snake1->setDirection(2);
				}
			}
			if (evnt.type == Event::KeyPressed && evnt.key.code == Keyboard::Left)
			{
				if (DirectionVector[0] == 1)
				{
					continue;
				}
				else
				{
					DirectionVector[0] = 3;
					snake1->setDirection(3);
				}
			}
			if (evnt.type == Event::KeyPressed && evnt.key.code == Keyboard::Right)
			{
				if (DirectionVector[0] == 3)
				{
					continue;
				}
				else
				{
					DirectionVector[0] = 1;
					snake1->setDirection(1);
				}
			}

		}

		window.clear();


		mHead.setPosition(snake1->getCurrentPosition().x, snake1->getCurrentPosition().y);
		window.draw(mHead);
		snake1->Move();
		mBody.setPosition(snake1->mNextSection->getCurrentPosition().x, snake1->mNextSection->getCurrentPosition().y);
		window.draw(mBody);


		window.display();
	}
}
