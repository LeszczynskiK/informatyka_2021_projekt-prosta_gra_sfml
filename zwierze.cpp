#include <SFML/Graphics.hpp>
#include <iostream>
#include "deklaracje.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace sf;

zwierze::zwierze(float x_in1, float y_in1)
{
	position1.x = x_in1;
	position1.y = y_in1;
	ZWIERZE.setPosition(position1);
	ZWIERZE.setSize(sf::Vector2f(75, 75));
	tekstura1.loadFromFile("dzik.png");
	ZWIERZE.setTexture(&tekstura1);
	tekstura1ty.loadFromFile("mysliwy.png");
	ZWIERZEty.setPosition(position1);
	ZWIERZEty.setSize(sf::Vector2f(75, 75));
	ZWIERZEty.setTexture(&tekstura1ty);
}

void zwierze::przesun1(float x_in1, float y_in1)
{
	sf::Vector2f pos1;
	pos1.x = x_in1;
	pos1.y = y_in1;
	ZWIERZE.move(pos1);
}
void zwierze::przesun1TY(float x_in1, float y_in1)
{
	sf::Vector2f pos1;
	pos1.x = x_in1;
	pos1.y = y_in1;
	ZWIERZEty.move(pos1);
}
