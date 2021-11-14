#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <SFML/Window.hpp>
#include <time.h>
using namespace std;
using namespace sf;
#define MAX_LICZBA_POZIOMOW 4

// klasy i funkcje  dotyczace menu:
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

//klasy i funkcje dotyczace samej gry:

class grzyb {
public:
	sf::Vector2f position;//wspolrzedne
	sf::RectangleShape GRZYB;
	grzyb(float x_in, float y_in);//tworz obiekt w polozeniu (x,y)
	void przesun(float x_in, float y_in);//przesun 
	void idz(float x1, float y1);
	sf::RectangleShape getGrzyb() { return GRZYB; }//zwroc obiekt
	sf::Vector2f getPos() { return GRZYB.getPosition(); };
	sf::Texture tekstura;
};

grzyb::grzyb(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	GRZYB.setPosition(position);
	GRZYB.setSize(sf::Vector2f(75, 75));
	GRZYB.setTexture(&tekstura);
}

void grzyb::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	GRZYB.move(pos);
}

int main()
{
	sf::RectangleShape tloMenu;
	tloMenu.setSize(sf::Vector2f(1440, 960));
	sf::Texture tekstura;
	tekstura.loadFromFile("tlo.jpg");
	tloMenu.setTexture(&tekstura);

	sf::RectangleShape tloGry;
	tloGry.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturaGry;
	teksturaGry.loadFromFile("tlo.png");
	tloGry.setTexture(&teksturaGry);

	sf::RectangleShape tloSterowanie;
	tloSterowanie.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturaSterowanie;
	teksturaSterowanie.loadFromFile("sterowanie.png");
	tloSterowanie.setTexture(&teksturaSterowanie);

	sf::RectangleShape tloINFO;
	tloINFO.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturaINFO;
	teksturaINFO.loadFromFile("info.png");
	tloINFO.setTexture(&teksturaINFO);

	sf::RectangleShape tlo;
	tlo.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturatlo;
	teksturatlo.loadFromFile("tlo.png");
	tlo.setTexture(&teksturatlo);
	grzyb p1(100, 100);//stworz pilke
	grzyb p2(200, 100);
	grzyb p3(300, 100);
	grzyb p4(100, 200);// pilka pr bedzie pilka ktora bedzie sterowana za pomoca WSAD



	int x = 0, y = 0;//pozycja pilki
	int dx = 10, dy = 10;//kierunek x, kierunek y
	int dx1 = 15, dy1 = 15;//kierunek x, kierunek y
	int dx2 = 20, dy2 = 20;//kierunek x, kierunek y
	sf::Clock zegar;

	int zmiennaPomocnicza = 0;
x:
x1:
x2:
	sf::RenderWindow window(sf::VideoMode(1440, 960), "Forest Game");
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
				if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
				{
					Sleep(100);
					menu.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
				{
					Sleep(100);
					menu.moveDown();
				}
				if (zmiennaPomocnicza == 0)
				{
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 1)
					{
						cout << "O co chodzi w tej grze..." << endl;
						while (window.isOpen())
						{
							sf::Event event;
							while (window.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
								{
									window.close();
								}
								window.clear();
								window.draw(tloINFO);
								window.display();
								if (event.key.code == sf::Keyboard::Escape)
								{
									window.clear();
									system("cls");
									goto x;

								}
							}
						}
						zmiennaPomocnicza = 1;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 2)
					{
						cout << "Opcje sterowania" << endl;
						while (window.isOpen())
						{
							sf::Event event;
							while (window.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
								{
									window.close();
								}
								window.clear();
								window.draw(tloSterowanie);
								window.display();
								if (event.key.code == sf::Keyboard::Escape)
								{
									window.clear();
									system("cls");
									goto x1;

								}
							}
						}
						zmiennaPomocnicza = 1;

					}
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 3)
					{
						cout << "Wyjscie z gry" << endl;
						zmiennaPomocnicza = 1;
						return 0;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.wybierzOpcje() == 0)
					{
						cout << "Uruchamiam gre" << endl;
						while (window.isOpen())
						{
							sf::Event event;
							// petla sprawdzajace zdarzenia
							while (window.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
									window.close();
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
							{
								p4.przesun(-1, 0);
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
							{
								p4.przesun(1, 0);
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
							{
								p4.przesun(0, -1);
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
							{
								p4.przesun(0, +1);
							}




							if (zegar.getElapsedTime().asMilliseconds() > 100.0f)
							{

								if (p1.getPos().x + 40 > window.getSize().x || p1.getPos().x - 20 < 0)
								{
									dx = -dx;//zmien kierunek na przeciwny
								}

								if (p1.getPos().y + 40 > window.getSize().y || p1.getPos().y - 20 < 0)
								{
									dy = -dy;
								}
								p1.przesun(dx, dy);
								if (p2.getPos().x + 40 > window.getSize().x || p2.getPos().x - 20 < 0)
								{
									dx1 = -dx1;//zmien kierunek na przeciwny
								}

								if (p2.getPos().y + 40 > window.getSize().y || p2.getPos().y - 20 < 0)
								{
									dy1 = -dy1;
								}
								p2.przesun(dx1, dy1);
								if (p3.getPos().x + 40 > window.getSize().x || p3.getPos().x - 20 < 0)

								{
									dx2 = -dx2;//zmien kierunek na przeciwny
								}

								if (p3.getPos().y + 40 > window.getSize().y || p3.getPos().y - 20 < 0)
								{
									dy2 = -dy2;
								}
								p3.przesun(dx2, dy2);
								zegar.restart();
							}

							if (p4.getPos().x - 70 <= p1.getPos().x && p4.getPos().x + 70 >= p1.getPos().x && p4.getPos().y + 70 >= p1.getPos().y && p4.getPos().y + -30 <= p1.getPos().y + 0)
							{

								Sleep(100);
								cout << "KOLIZJA!!!" << endl;
							}

							if (p4.getPos().x - 70 <= p2.getPos().x && p4.getPos().x + 70 >= p2.getPos().x && p4.getPos().y + 70 >= p2.getPos().y && p4.getPos().y - 30 <= p2.getPos().y + 0)
							{
								Sleep(100);
								cout << "KOLIZJA!!!" << endl;
							}

							if (p4.getPos().x - 70 <= p3.getPos().x && p4.getPos().x + 70 >= p3.getPos().x && p4.getPos().y + 70 >= p3.getPos().y && p4.getPos().y - 30 <= p3.getPos().y + 0)
							{
								Sleep(100);
								cout << "KOLIZJA!!!" << endl;
							}
							window.clear(sf::Color::White);
							window.draw(tlo);
							window.draw(p1.getGrzyb());
							window.draw(p2.getGrzyb());
							window.draw(p3.getGrzyb());
							window.draw(p4.getGrzyb());
							window.display();
							if (event.key.code == sf::Keyboard::Escape)
							{
								window.clear();
								system("cls");
								goto x2;

							}
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

	}
}