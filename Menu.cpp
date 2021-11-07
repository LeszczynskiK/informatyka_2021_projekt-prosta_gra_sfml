#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
using namespace std;
using namespace sf;

#define MAX_LICZBA_POZIOMOW 4

class Menu
{
private:
	sf::Font czcionka;
	sf::Text* menu;
	int wybranaOpcja = 0;
public:
	Menu(float width, float height);
	~Menu() { delete[] menu; };
	void moveUp();
	void moveDown();
	int wybierzOpcje() { return wybranaOpcja; }
	void draw(sf::RenderWindow& window);
};

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

int main()
{
	sf::RectangleShape tloMenu;
	tloMenu.setSize(sf::Vector2f(1440, 960));
	sf::Texture tekstura;
	tekstura.loadFromFile("tlo.jpg");
	tloMenu.setTexture(&tekstura);
	

	int zmiennaPomocnicza = 0;
	sf::RenderWindow window(sf::VideoMode(1440, 960), "Moja gra");
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					Sleep(100);
					menu.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					Sleep(100);
					menu.moveDown();
				}
				if (zmiennaPomocnicza == 0)
				{
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 0)
					{
						cout << "Uruchamiam gre" << endl;
						zmiennaPomocnicza = 1;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 1)
					{
						cout << "O co chodzi w tej grze..." << endl;
						zmiennaPomocnicza = 1;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 2)
					{
						cout << "Opcje sterowania" << endl;
						zmiennaPomocnicza = 1;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 3)
					{
						cout << "Wyjscie z gry" << endl;
						zmiennaPomocnicza = 1;
					}
				}
			}
		}
		window.clear();
		window.draw(tloMenu);
		if (zmiennaPomocnicza == 0)
		{
			menu.draw(window);
		}
		window.display();
	}
	return 0;
}