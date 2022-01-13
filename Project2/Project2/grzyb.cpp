#include <SFML/Graphics.hpp>
#include <iostream>
#include "deklaracje.h"
using namespace std;
using namespace sf;


grzyb::grzyb(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	GRZYB.setPosition(position);
	GRZYB.setSize(sf::Vector2f(75, 75));
	tekstura.loadFromFile("grzybtY.png");
	GRZYB.setTexture(&tekstura);
	GRZYBty.setPosition(position);
	GRZYBty.setSize(sf::Vector2f(75, 75));
	teksturaty.loadFromFile("grzybk.png");
	GRZYBty.setTexture(&teksturaty);
}

void grzyb::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	GRZYB.move(pos);
}
void grzyb::przesunTY(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	GRZYBty.move(pos);
}
