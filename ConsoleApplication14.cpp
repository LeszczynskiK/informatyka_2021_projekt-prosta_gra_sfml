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
	int punktyRozgrywki;
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

class zwierze {
public:
	sf::Vector2f position1;//wspolrzedne
	sf::RectangleShape ZWIERZE;
	zwierze(float x_in1, float y_in1);//tworz obiekt w polozeniu (x,y)
	void przesun1(float x_in1, float y_in1);//przesun 
	void idz1(float x11, float y11);
	sf::RectangleShape getZwierze() { return ZWIERZE; }//zwroc obiekt
	sf::Vector2f getPos1() { return ZWIERZE.getPosition(); };
};

zwierze::zwierze(float x_in1, float y_in1)
{
	position1.x = x_in1;
	position1.y = y_in1;
	ZWIERZE.setPosition(position1);
	ZWIERZE.setSize(sf::Vector2f(75, 75));
}

void zwierze::przesun1(float x_in1, float y_in1)
{
	sf::Vector2f pos1;
	pos1.x = x_in1;
	pos1.y = y_in1;
	ZWIERZE.move(pos1);
}

int main()
{
	int punktyRozgrywkiTotal = 0;//startowa wartosc punktow rozgrywki
	int minPoints = 0; //minimalna ilosc punktow by odblokowac dalszy etap rozgrywki

	srand(time(NULL));
	int randomX;
	int randomY;
	randomX = 100 + 15 * rand() % 10;
	randomY = 100 + 15 * rand() % 10;
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

	sf::RectangleShape tloGry2;
	tloGry2.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturaGry2;
	teksturaGry2.loadFromFile("tloGry2.jpg");
	tloGry2.setTexture(&teksturaGry2);

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
	int dx = 15, dy = 15;//kierunek x, kierunek y
	int dx1 = 22, dy1 = 22;//kierunek x, kierunek y
	int dx2 = 30, dy2 = 30;//kierunek x, kierunek y
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
								punktyRozgrywkiTotal += 5;
								cout << "Aktualnie zdobyles" << punktyRozgrywkiTotal << "punktow" << endl;
								p1.przesun(randomX, randomY);
								if (p1.getPos().x < 0)
								{
									p1.przesun(700, 0);
								}
								else if (p1.getPos().x > window.getSize().x)
								{
									p1.przesun(-700, 0);
								}
								else if (p1.getPos().y < 0)
								{
									p1.przesun(0, +700);
								}
								else if (p1.getPos().y > window.getSize().y)
								{
									p1.przesun(0, -700);
								}
							}
							if (p4.getPos().x - 70 <= p2.getPos().x && p4.getPos().x + 70 >= p2.getPos().x && p4.getPos().y + 70 >= p2.getPos().y && p4.getPos().y - 30 <= p2.getPos().y + 0)
							{
								Sleep(100);
								cout << "KOLIZJA!!!" << endl;
								p2.przesun(randomX, randomY);
								punktyRozgrywkiTotal += 7;
								cout << "Aktualnie zdobyles" << punktyRozgrywkiTotal << "punktow" << endl;
								if (p2.getPos().x < 0)
								{
									p2.przesun(700, 0);
								}
								else if (p2.getPos().x > window.getSize().x)
								{
									p2.przesun(-700, 0);
								}
								else if (p2.getPos().y < 0)
								{
									p2.przesun(0, +700);
								}
								else if (p2.getPos().y > window.getSize().y)
								{
									p2.przesun(0, -700);
								}

							}

							if (p4.getPos().x - 70 <= p3.getPos().x && p4.getPos().x + 70 >= p3.getPos().x && p4.getPos().y + 70 >= p3.getPos().y && p4.getPos().y - 30 <= p3.getPos().y + 0)
							{
								Sleep(100);
								cout << "KOLIZJA!!!" << endl;
								p3.przesun(randomX, randomY);
								punktyRozgrywkiTotal += 10;
								cout << "Aktualnie zdobyles" << punktyRozgrywkiTotal << "punktow" << endl;
								if (p3.getPos().x < 0)
								{
									p3.przesun(700, 0);
								}
								else if (p3.getPos().x > window.getSize().x)
								{
									p3.przesun(-700, 0);
								}
								else if (p3.getPos().y < 0)
								{
									p3.przesun(0, +700);
								}
								else if (p3.getPos().y > window.getSize().y)
								{
									p3.przesun(0, -700);
								}

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
	system("cls");
	/*cout << "Dzielny wojowniku! Zdobyles:" << punktyRozgrywkiTotal << "punktow" << endl;
	cout << "Ale czy to aby napewno wystarczajaco aby odblokowac dalszy etap rozgrywki?" << endl;
	Sleep(2000);
	cout << "Sprawdzmy..." << endl;
	Sleep(1250);
	system("cls");*/
	float mnoznik = 0;
	mnoznik = punktyRozgrywkiTotal / 100.0;
	if (punktyRozgrywkiTotal >= minPoints)
	{
		cout << "Gratuluje!!!Udalo Ci sie zdobyc wystarczajaco ilosc punktow by odblokowac finalne starcie z potworami... " << endl;
		/*Sleep(1250);
		cout << "A teraz  statystyki twojej  podstaci zostana ulepszone!!!" << endl;
		Sleep(1250);
		cout << "Ilosc punktow ktore zdobyles bedzie miala wplyw na mnoznik punktow zdobytych za zabicie potworow oraz na predkosc twojej postaci" << endl;
		Sleep(1000);
		cout << "Oznacza to ,ze im lepiej CI poszlo w pierwszej czesci , tym prosciej i szybiej pojdzie Ci walka z potworami..." << endl;
		Sleep(1000);
		cout << "Zatem gra posiada rozne poziomy trudnosci...." << endl;
		Sleep(1000);
		cout << " Przelicznik wyglada nastepujaco: ilosc zdobytych przez ciebie punktow dzielic na 100" << endl;
		Sleep(1300);
		system("cls");
		cout << "Zdobyles: " << punktyRozgrywkiTotal << "punktow" << endl;
		Sleep(2000);
		cout << "Oznacza to ,ze twoj mnoznik punktow wynosi:" << mnoznik << "*pkt" << endl;
		Sleep(1000);
		system("cls");
		cout << "Ladowanie rozgrywki..." << endl;
		Sleep(675);*/
		sf::RenderWindow window1(sf::VideoMode(1440, 960), "Forest Game , next part of game");
		zwierze z1(200, 200);//stworz zwierze
		zwierze z2(400, 200);
		zwierze z3(600, 300);
		zwierze z4(800, 150);
		zwierze z5(500, 200);
		cout << "Gra zaladowana..." << endl;
		mnoznik = 10; //temporary - potem to usun(tylko do testow gry! 
		sf::Event event1;
		int dx2=5, dy2=5;
		int dx21 = 5, dy21 = 5;
		int dx22 = 5, dy22 = 5;
		int dx23 = 5, dy23 = 5;
		sf::Clock zegar2;
		int PODSUMOWANIEpkt = 0;
		while (window1.isOpen())
		{
			
			while (window1.pollEvent(event1))
			{
				if (event1.type == sf::Event::Closed)
				{
					window1.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
				{
					z5.przesun1(-1 * mnoznik, 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
				{
					z5.przesun1(1 * mnoznik, 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
				{
					z5.przesun1(0, -1 * mnoznik);
				}
				if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
				{
					z5.przesun1(0, +1 * mnoznik);
				}
				zegar.restart();
				zegar2.restart();
				if (zegar2.getElapsedTime().asMilliseconds() < 100.0f)
				{
					
					if (z1.getPos1().x + 40 > window1.getSize().x || z1.getPos1().x - 20 < 0)
					{
						dx2 = -dx2;//zmien kierunek na przeciwny

					}
					z1.przesun1(dx2, 0);
					if (z1.getPos1().y + 40 > window1.getSize().y || z1.getPos1().y - 20 < 0)
					{
						dy2 = -dy2;

					}
					z1.przesun1(0, dy2);
					if (z2.getPos1().x + 40 > window1.getSize().x || z2.getPos1().x - 20 < 0)
					{
						dx21 = -dx21;//zmien kierunek na przeciwny

					}
					z2.przesun1(dx21, 0);
					if (z2.getPos1().y + 40 > window1.getSize().y || z2.getPos1().y - 20 < 0)
					{
						dy21 = -dy21;

					}
					z2.przesun1(0, dy21);
					if (z3.getPos1().x + 40 > window1.getSize().x || z3.getPos1().x - 20 < 0)

					{
						dx22 = -dx22;//zmien kierunek na przeciwny

					}
					z3.przesun1(dx22, 0);
					if (z3.getPos1().y + 40 > window1.getSize().y || z3.getPos1().y - 20 < 0)
					{
						dy22 = -dy22;

					}
					z3.przesun1(0, dy22);
					if (z4.getPos1().x + 40 > window1.getSize().x || z4.getPos1().x - 20 < 0)
					{
						dx23 = -dx23;//zmien kierunek na przeciwny

					}
					z4.przesun1(dx23, 0);
					if (z4.getPos1().y + 40 > window1.getSize().y || z4.getPos1().y - 20 < 0)
					{
						dy23 = -dy23;

					}
					z4.przesun1(0, dy23);
					zegar2.restart();
				}
				
				int randomX1 = 15 * rand() % 40 + 100;
				int randomY1 = 15 * rand() % 40 + 100;
				
				if (z5.getPos1().x - 70 <= z1.getPos1().x && z5.getPos1().x + 70 >= z1.getPos1().x && z5.getPos1().y + 70 >= z1.getPos1().y && z5.getPos1().y + -30 <= z1.getPos1().y + 0)
				{
					cout << "Kolizja" << endl;
					cout << "Twoje punkty: " << PODSUMOWANIEpkt << endl;
					system("cls");
					z1.przesun1(randomX1, randomY1);
					PODSUMOWANIEpkt += 5;
					if (p1.getPos().x < 50)
					{
						p1.przesun(700, 0);
					}
					else if (z1.getPos1().x > window.getSize().x -50)
					{
						z1.przesun1(-700, 0);
					}
					else if (z1.getPos1().y < 50)
					{
						z1.przesun1(0, +700);
					}
					else if (p1.getPos().y > window.getSize().y -50)
					{
						z1.przesun1(0, -700);
					}
				}
				if (z5.getPos1().x - 70 <= z2.getPos1().x && z5.getPos1().x + 70 >= z2.getPos1().x && z5.getPos1().y + 70 >= z2.getPos1().y && z5.getPos1().y - 30 <= z2.getPos1().y + 0)
				{
					z2.przesun1(randomX1, randomY1);
					cout << "Kolizja" << endl;
					cout << "Twoje punkty: " << PODSUMOWANIEpkt << endl;
					system("cls");
					PODSUMOWANIEpkt += 5;
					if (z2.getPos1().x < 50)
					{
						z2.przesun1(700, 0);
					}
					else if (z2.getPos1().x > window.getSize().x -50)
					{
						z2.przesun1(-700, 0);
					}
					else if (z2.getPos1().y < 50)
					{
						z2.przesun1(0, +700);
					}
					else if (z2.getPos1().y > window.getSize().y -50)
					{
						z2.przesun1(0, -700);
					}

				}

				if (z5.getPos1().x - 70 <= z3.getPos1().x && z5.getPos1().x + 70 >= z3.getPos1().x && z5.getPos1().y + 70 >= z3.getPos1().y && z5.getPos1().y - 30 <= z3.getPos1().y + 0)
				{
					z3.przesun1(randomX1, randomY1);
					cout << "Kolizja" << endl;
					cout << "Twoje punkty: " << PODSUMOWANIEpkt << endl;
					system("cls");
					PODSUMOWANIEpkt += 5;
					if (z3.getPos1().x < 50)
					{
						z3.przesun1(700, 0);
					}
					else if (z3.getPos1().x > window.getSize().x -50)
					{
						z3.przesun1(-700, 0);
					}
					else if (z3.getPos1().y < 50)
					{
						z3.przesun1(0, +700);
					}
					else if (z3.getPos1().y > window.getSize().y -50)
					{
						z3.przesun1(0, -700);
					}

				}

				if (z5.getPos1().x - 70 <= z4.getPos1().x && z5.getPos1().x + 70 >= z4.getPos1().x && z5.getPos1().y + 70 >= z4.getPos1().y && z5.getPos1().y - 30 <= z4.getPos1().y + 0)
				{
					z4.przesun1(randomX1, randomY1);
					cout << "Kolizja" << endl;
					cout << "Twoje punkty: " << PODSUMOWANIEpkt << endl;
					system("cls");
					PODSUMOWANIEpkt += 5;
					if (z4.getPos1().x < 50)
					{
						z4.przesun1(700, 0);
					}
					else if (z4.getPos1().x > window.getSize().x - 50)
					{
						z4.przesun1(-700, 0);
					}
					else if (z4.getPos1().y < 50)
					{
						z4.przesun1(0, +700);
					}
					else if (z4.getPos1().y > window.getSize().y - 50)
					{
						z4.przesun1(0, -700);
					}

				}
				window1.clear();
				window1.draw(tloGry2);
				window1.draw(z1.getZwierze());
				window1.draw(z2.getZwierze());
				window1.draw(z3.getZwierze());
				window1.draw(z4.getZwierze());
				window1.draw(z5.getZwierze());
				window1.display();
				if (event1.key.code == sf::Keyboard::Escape)
				{
					system("cls");
					cout << "Koniec rozgrywki... wybrales opcje wyjscie ESC" << endl;
					return 0;

				}
			}
			PODSUMOWANIEpkt = 55; // tymczasowe przypisanie
		}cout << "Gratuluje , zdobyles : " << PODSUMOWANIEpkt << "punktow" << endl;
		sf::RectangleShape wygrana;
		wygrana.setSize(sf::Vector2f(1350, 1020));
		sf::Texture teksturaWygrana;
		teksturaWygrana.loadFromFile("wygrana.jpg");
		wygrana.setTexture(&teksturaWygrana);

		sf::RectangleShape przegrana;
		przegrana.setSize(sf::Vector2f(1000, 960));
		sf::Texture teksturaPrzegrana;
		teksturaPrzegrana.loadFromFile("lose.jpg");
		przegrana.setTexture(&teksturaPrzegrana);
		if (PODSUMOWANIEpkt > 50)
		{
			/*cout << "GRATULACJE!!! WYGRALES WALKE Z POTWORAMI..." << endl;
			Sleep(550);
			cout << "Oznacza to ,ze ocaliles las przed zaglada iiii....." << endl;
			Sleep(1000);
			cout << "Wygrales rozgrywke!!!GRATULUJE!!!" << endl;
			Sleep(250);*/
			sf::Event event2;
			sf::RenderWindow window2(sf::VideoMode(1350, 1020), "KONIEC GRY");
			while (window2.isOpen())
			{
				while (window2.pollEvent(event2))
				{
					while (event2.type == sf::Event::Closed)
					{
						window2.close();
					}

				}
				window2.clear();
				window2.draw(wygrana);
				window2.display();
				Sleep(7500);
				system("cls");
				cout << "Wyjscie..." << endl;
				return 0;
			}

		}
		else
		{
			cout << "Przykro mi... tym razem przegrales wojne i twoj las zostal zniszczony..." << endl;
			Sleep(750);
			sf::Event event3;
			sf::RenderWindow window3(sf::VideoMode(1000, 960), "PRZEGRANA");
			while (window3.isOpen())
			{
				while (window3.pollEvent(event3))
				{
					while (event3.type == sf::Event::Closed)
					{
						window3.close();
					}

				}
				window3.clear();
				window3.draw(przegrana);
				window3.display();
				Sleep(7500);
				cout << "Wyjscie..." << endl;
				return 0;
			}
		}
	}	
}
