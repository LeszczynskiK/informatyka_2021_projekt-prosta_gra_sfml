#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "deklaracje.h"
using namespace std;
using namespace sf;
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LICZBA_POZIOMOW 4
Menu::Menu(float szerokosc, float wysokosc)
{
	if (!czcionka.loadFromFile("arial.ttf"))
	{
		return;
	}
	menu = new sf::Text[MAX_LICZBA_POZIOMOW];

	menu[0].setFont(czcionka);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("Nowa gra");
	menu[0].setPosition(sf::Vector2f(szerokosc / 7, wysokosc / (MAX_LICZBA_POZIOMOW + 1) * 1));

	menu[1].setFont(czcionka);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("O co chodzi w tej grze?");
	menu[1].setPosition(sf::Vector2f(szerokosc / 7, wysokosc / (MAX_LICZBA_POZIOMOW + 1) * 2));

	menu[2].setFont(czcionka);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Opcje sterowania");
	menu[2].setPosition(sf::Vector2f(szerokosc / 7, wysokosc / (MAX_LICZBA_POZIOMOW + 1) * 3));

	menu[3].setFont(czcionka);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Wyjscie z gry");
	menu[3].setPosition(sf::Vector2f(szerokosc / 7, wysokosc / (MAX_LICZBA_POZIOMOW + 1) * 4));
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (wybranaOpcja >= 0 && wybranaOpcja < MAX_LICZBA_POZIOMOW)
	{
		menu[wybranaOpcja].setFillColor(sf::Color::White);
		menu[wybranaOpcja].setStyle(sf::Text::Regular);
		wybranaOpcja--;
		if (wybranaOpcja < 0)
		{
			wybranaOpcja = MAX_LICZBA_POZIOMOW - 1;
		}
		menu[wybranaOpcja].setFillColor(sf::Color::Cyan);
		menu[wybranaOpcja].setStyle(sf::Text::Bold);

	}

}

void Menu::moveDown()
{
	if (wybranaOpcja >= 0 && wybranaOpcja < MAX_LICZBA_POZIOMOW)
	{
		menu[wybranaOpcja].setFillColor(sf::Color::White);
		menu[wybranaOpcja].setStyle(sf::Text::Regular);
		wybranaOpcja++;
		if (wybranaOpcja >= MAX_LICZBA_POZIOMOW)
		{
			wybranaOpcja = 0;
		}
		menu[wybranaOpcja].setFillColor(sf::Color::Cyan);
		menu[wybranaOpcja].setStyle(sf::Text::Bold);
	}

}