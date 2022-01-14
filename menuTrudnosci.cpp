#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "deklaracje.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace sf;
#define LICZBA_POZIOMOW 3
MenuTrudnosci::MenuTrudnosci(float szerokoscTrudnosci, float wysokoscTrudnosci)
{
	if (!czcionkaTrudnosci.loadFromFile("arial.ttf"))
	{
		return;
	}
	menuTrudnosci = new sf::Text[LICZBA_POZIOMOW];

	menuTrudnosci[0].setFont(czcionkaTrudnosci);
	menuTrudnosci[0].setFillColor(sf::Color::Red);
	menuTrudnosci[0].setString("Poziom latwy");
	menuTrudnosci[0].setPosition(sf::Vector2f(szerokoscTrudnosci / 5, wysokoscTrudnosci / (LICZBA_POZIOMOW + 1) * 1));

	menuTrudnosci[1].setFont(czcionkaTrudnosci);
	menuTrudnosci[1].setFillColor(sf::Color::Yellow);
	menuTrudnosci[1].setString("Poziom sredni");
	menuTrudnosci[1].setPosition(sf::Vector2f(szerokoscTrudnosci / 5, wysokoscTrudnosci / (LICZBA_POZIOMOW + 1) * 2));

	menuTrudnosci[2].setFont(czcionkaTrudnosci);
	menuTrudnosci[2].setFillColor(sf::Color::Yellow);
	menuTrudnosci[2].setString("Poziom trudny!!!");
	menuTrudnosci[2].setPosition(sf::Vector2f(szerokoscTrudnosci / 5, wysokoscTrudnosci / (LICZBA_POZIOMOW + 1) * 3));
}

void MenuTrudnosci::drawTrudnosci(sf::RenderWindow& windowTrudnosci)
{
	for (int a = 0; a < LICZBA_POZIOMOW; a++)
	{
		windowTrudnosci.draw(menuTrudnosci[a]);
	}
}

void MenuTrudnosci::moveUpTrudnosci()
{
	if (wybranaOpcjaTrudnosci >= 0 && wybranaOpcjaTrudnosci < LICZBA_POZIOMOW)
	{
		menuTrudnosci[wybranaOpcjaTrudnosci].setFillColor(sf::Color::Yellow);
		menuTrudnosci[wybranaOpcjaTrudnosci].setStyle(sf::Text::Regular);
		wybranaOpcjaTrudnosci--;
		if (wybranaOpcjaTrudnosci < 0)
		{
			wybranaOpcjaTrudnosci = LICZBA_POZIOMOW - 1;
		}
		menuTrudnosci[wybranaOpcjaTrudnosci].setFillColor(sf::Color::Red);
		menuTrudnosci[wybranaOpcjaTrudnosci].setStyle(sf::Text::Bold);

	}

}

void MenuTrudnosci::moveDownTrudnosci()
{
	if (wybranaOpcjaTrudnosci >= 0 && wybranaOpcjaTrudnosci < LICZBA_POZIOMOW)
	{
		menuTrudnosci[wybranaOpcjaTrudnosci].setFillColor(sf::Color::Yellow);
		menuTrudnosci[wybranaOpcjaTrudnosci].setStyle(sf::Text::Regular);
		wybranaOpcjaTrudnosci++;
		if (wybranaOpcjaTrudnosci >= LICZBA_POZIOMOW)
		{
			wybranaOpcjaTrudnosci = 0;
		}
		menuTrudnosci[wybranaOpcjaTrudnosci].setFillColor(sf::Color::Red);
		menuTrudnosci[wybranaOpcjaTrudnosci].setStyle(sf::Text::Bold);
	}

}