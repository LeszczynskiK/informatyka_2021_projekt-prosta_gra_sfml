//zrodlo cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <SFML/Window.hpp>
#include <time.h>
#include <SFML/System.hpp>
#include <chrono>  // for high_resolution_clock
#include "deklaracje.h"
using namespace std;
using namespace sf;


int main()
{
	int punktyRozgrywkiTotal = 999;//startowa wartosc punktow rozgrywki
	int minPoints = 750; //minimalna ilosc punktow by odblokowac dalszy etap rozgrywki

	srand(time(NULL));
	int randomX = 100 + 15 * rand() % 10;;
	int randomY = 100 + 15 * rand() % 10;;

	sf::RectangleShape tloMenu;
	tloMenu.setSize(sf::Vector2f(1440, 960));
	sf::Texture tekstura;
	tekstura.loadFromFile("tlo.jpg");
	tloMenu.setTexture(&tekstura);

	/*sf::RectangleShape tloGry;
	tloGry.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturaGry;
	teksturaGry.loadFromFile("tlo1.jpg");
	tloGry.setTexture(&teksturaGry);*/

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

	sf::RectangleShape tloTrudnosci;
	tloTrudnosci.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturaTrudnosci;
	teksturaTrudnosci.loadFromFile("tlo3.png");
	tloTrudnosci.setTexture(&teksturaTrudnosci);

	sf::RectangleShape tlo;
	tlo.setSize(sf::Vector2f(1440, 960));
	sf::Texture teksturatlo;
	teksturatlo.loadFromFile("tloX.jpg");
	tlo.setTexture(&teksturatlo);

	grzyb p1(100, 100);//stworz obiekt
	grzyb p2(200, 100);
	grzyb p3(300, 100);
	grzyb p4(100, 200);// obiekt p4 jest sterowany za pomoca WSAD lub strzalek

	int x = 0, y = 0;//pozycja poczatkowa obiektu
	int dx = 15, dy = 15;//kierunek x, kierunek y
	int dx1 = 22, dy1 = 22;//kierunek x, kierunek y
	int dx2 = 30, dy2 = 30;//kierunek x, kierunek y
	sf::Clock zegar;
	int zmiennaPomocnicza = 0;
	int zmiennaPomocniczaTrudnosci = 0;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text("Chcesz zakonczyc rozgrywke?\nJesli tak kliknij F10", font);
	text.setCharacterSize(71);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Yellow);
	text.setPosition(sf::Vector2f(200, 500));

	sf::Font font1;
	font1.loadFromFile("arial.ttf");
	sf::Text text1("Punkty:", font1);
	text1.setCharacterSize(27);
	text1.setStyle(sf::Text::Bold);
	text1.setFillColor(sf::Color::Red);
	text1.setPosition(sf::Vector2f(50, 20));
x:
x1:
x2:sf::RenderWindow window(sf::VideoMode(1440, 960), "Forest Game");
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
						auto start = std::chrono::high_resolution_clock::now();

						cout << "Uruchamiam gre" << endl;
						Sleep(1250);
						system("cls");
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
								p4.przesunTY(-1, 0);
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
							{
								p4.przesunTY(1, 0);
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
							{
								p4.przesunTY(0, -1);
							}
							if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
							{
								p4.przesunTY(0, +1);
							}

							sf::Text text2;
							text2.setPosition(sf::Vector2f(160, 20));
							text2.setFont(font);
							text2.setString(to_string(punktyRozgrywkiTotal));
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

							if (p4.getPosTY().x - 70 <= p1.getPos().x && p4.getPosTY().x + 70 >= p1.getPos().x && p4.getPosTY().y + 70 >= p1.getPos().y && p4.getPosTY().y + -30 <= p1.getPos().y + 0)
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
							if (p4.getPosTY().x - 70 <= p2.getPos().x && p4.getPosTY().x + 70 >= p2.getPos().x && p4.getPosTY().y + 70 >= p2.getPos().y && p4.getPosTY().y - 30 <= p2.getPos().y + 0)
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

							if (p4.getPosTY().x - 70 <= p3.getPos().x && p4.getPosTY().x + 70 >= p3.getPos().x && p4.getPosTY().y + 70 >= p3.getPos().y && p4.getPosTY().y - 30 <= p3.getPos().y + 0)
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
							window.draw(p4.getGrzybTY());
							window.draw(text1);
							window.draw(text2);
							window.display();
							if (event.key.code == sf::Keyboard::Escape)
							{
								window.draw(text);
								window.display();
								Sleep(1000);
							}
							if (event.key.code == sf::Keyboard::F10)
							{
								system("cls");
								cout << "Wybrano i potwierdzono wyjscie";
								return 0;
							}
							zmiennaPomocnicza = 1;
							auto finish = std::chrono::high_resolution_clock::now();
							std::chrono::duration<double> elapsed = finish - start;
							if (elapsed.count() > 60.0)
							{
								cout << "Wylaczone okno po minucie rozgrywki... to planowy czas gry do zdobycia punktow" << endl;
								window.close();
							}
						}

					}
				}
			}
			window.clear();
			window.draw(tloMenu);
			event.type == sf::Event::Closed;
			if (zmiennaPomocnicza == 0)
			{
				menu.draw(window);
			}
			window.display();
		}
	}
	system("cls");	
	if (punktyRozgrywkiTotal >= minPoints)
	{
		cout << "Potrzebna ilosc punktow by przejsc dalej: " << minPoints << endl;
		cout << "Twoja ilosc punktow: " << punktyRozgrywkiTotal << endl;
		cout << "Zdobyto wystarczajaco duzo punktow w pierwszym etapie gry" << endl;
		sf::RenderWindow windowTrudnosci(sf::VideoMode(1440, 960), "Part II of the game");
		MenuTrudnosci menuTrudnosci(windowTrudnosci.getSize().x, windowTrudnosci.getSize().y);
		int szybkosc;// ta zmienna jest wyznacznikiem poziomu trudnosci 2giej czesci rozgrywki
		while (windowTrudnosci.isOpen())
		{
			sf::Event eventTrudnosci;
			while (windowTrudnosci.pollEvent(eventTrudnosci))
			{
				if (eventTrudnosci.type == sf::Event::Closed)
				{
					windowTrudnosci.close();
				}
				if (eventTrudnosci.type == sf::Event::KeyPressed)
				{
					if (eventTrudnosci.key.code == sf::Keyboard::Up || eventTrudnosci.key.code == sf::Keyboard::W)
					{
						Sleep(100);
						menuTrudnosci.moveUpTrudnosci();
					}
					if (eventTrudnosci.key.code == sf::Keyboard::Down || eventTrudnosci.key.code == sf::Keyboard::S)
					{
						Sleep(100);
						menuTrudnosci.moveDownTrudnosci();
					}
					if (zmiennaPomocniczaTrudnosci == 0)
					{
						if (eventTrudnosci.key.code == sf::Keyboard::Enter && menuTrudnosci.wybierzOpcjeTrudnosci() == 0)
						{
							system("cls");
							cout << "Wybrano poziom latwy" << endl;
							szybkosc = 1;
							windowTrudnosci.close();
							eventTrudnosci.type == sf::Event::Closed;
						}
						if (eventTrudnosci.key.code == sf::Keyboard::Enter && menuTrudnosci.wybierzOpcjeTrudnosci() == 1)
						{
							system("cls");
							cout << "Wybrano poziom sredni" << endl;
							szybkosc = 3;
							windowTrudnosci.close();
							eventTrudnosci.type == sf::Event::Closed;
						}
						if (eventTrudnosci.key.code == sf::Keyboard::Enter && menuTrudnosci.wybierzOpcjeTrudnosci() == 2)
						{
							system("cls");
							cout << "Wybrano poziom trudny" << endl;
							szybkosc = 5;
							windowTrudnosci.close();
							eventTrudnosci.type == sf::Event::Closed;
						}
					}
				}
			}
			windowTrudnosci.clear();
			windowTrudnosci.draw(tloTrudnosci);
			if (zmiennaPomocniczaTrudnosci == 0)
			{
				menuTrudnosci.drawTrudnosci(windowTrudnosci);
			}
			windowTrudnosci.display();
		}
		zwierze z1(200, 200);//stworz zwierze
		zwierze z2(400, 200);
		zwierze z3(600, 300);
		zwierze z4(800, 150);
		zwierze z5(500, 200);
		int PODSUMOWANIEpkt = 0;
		int dx2 = 4 * szybkosc, dy2 = 9 * szybkosc;
		int dx21 = 7 * szybkosc, dy21 = 1 * szybkosc;
		int dx22 = 3 * szybkosc, dy22 = 11 * szybkosc;
		int dx23 = 2 * szybkosc, dy23 = 5 * szybkosc;
		cout << "Zdobyles: " << punktyRozgrywkiTotal << "punktow" << endl;


		sf::RenderWindow window1(sf::VideoMode(1440, 960), "Game part II");
		while (window1.isOpen())
		{
			sf::Event event1;
			while (window1.pollEvent(event1))
			{
				
				if (event1.type == sf::Event::Closed)
				{
					window1.close();
				}
				if (event1.type == sf::Event::KeyPressed)
				{
					if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
					{
						z5.przesun1TY(-75/szybkosc, 0);
					}
					if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
					{
						z5.przesun1TY(75/szybkosc, 0);
					}
					if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
					{
						z5.przesun1TY(0, -75/szybkosc);
					}
					if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
					{
						z5.przesun1TY(0, +75/szybkosc);
					}
				}
				sf::Clock zegar2;
				zegar2.restart();
				if (zegar2.getElapsedTime().asMilliseconds() > 100.0f)
				{
					if (z1.getPos1().x + 40 > window1.getSize().x || z1.getPos1().x - 20 < 0)
					{
						dx2 = -dx2;//zmien kierunek na przeciwny
					}
					if (z1.getPos1().y + 40 > window1.getSize().y || z1.getPos1().y - 20 < 0)
					{
						dy2 = -dy2;
					}
					if (z2.getPos1().x + 40 > window1.getSize().x || z2.getPos1().x - 20 < 0)
					{
						dx21 = -dx21;//zmien kierunek na przeciwny
					}
					if (z2.getPos1().y + 40 > window1.getSize().y || z2.getPos1().y - 20 < 0)
					{
						dy21 = -dy21;
					}
					if (z3.getPos1().x + 40 > window1.getSize().x || z3.getPos1().x - 20 < 0)
					{
						dx22 = -dx22;//zmien kierunek na przeciwny
					}
					if (z3.getPos1().y + 40 > window1.getSize().y || z3.getPos1().y - 20 < 0)
					{
						dy22 = -dy22;
					}
					if (z4.getPos1().x + 40 > window1.getSize().x || z4.getPos1().x - 20 < 0)
					{
						dx23 = -dx23;//zmien kierunek na przeciwny
					}
					if (z4.getPos1().y + 40 > window1.getSize().y || z4.getPos1().y - 20 < 0)
					{
						dy23 = -dy23;
					}
					zegar2.restart();
				}
				int randomX1 = (15 * rand() % 40 + 100)*1.7;
				int randomY1 = (15 * rand() % 40 + 100)*1.7;

				if (z5.getPos1TY().x - 70 <= z1.getPos1().x && z5.getPos1TY().x + 70 >= z1.getPos1().x && z5.getPos1TY().y + 70 >= z1.getPos1().y && z5.getPos1TY().y + -30 <= z1.getPos1().y + 0)
				{
					cout << "Kolizja" << endl;
					cout << "Twoje punkty: " << PODSUMOWANIEpkt << endl;
					system("cls");
					z1.przesun1(randomX1, randomY1);
					PODSUMOWANIEpkt += 5;
					if (z1.getPos1().x < 50)
					{
						z1.przesun1(700, 0);
					}
					else if (z1.getPos1().x > window1.getSize().x - 50)
					{
						z1.przesun1(-700, 0);
					}
					else if (z1.getPos1().y < 50)
					{
						z1.przesun1(0, +700);
					}
					else if (z1.getPos1().y > window1.getSize().y - 50)
					{
						z1.przesun1(0, -700);
					}
				}
				if (z5.getPos1TY().x - 70 <= z2.getPos1().x && z5.getPos1TY().x + 70 >= z2.getPos1().x && z5.getPos1TY().y + 70 >= z2.getPos1().y && z5.getPos1TY().y - 30 <= z2.getPos1().y + 0)
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
					else if (z2.getPos1().x > window1.getSize().x - 50)
					{
						z2.przesun1(-700, 0);
					}
					else if (z2.getPos1().y < 50)
					{
						z2.przesun1(0, +700);
					}
					else if (z2.getPos1().y > window1.getSize().y - 50)
					{
						z2.przesun1(0, -700);
					}
				}

				if (z5.getPos1TY().x - 70 <= z3.getPos1().x && z5.getPos1TY().x + 70 >= z3.getPos1().x && z5.getPos1TY().y + 70 >= z3.getPos1().y && z5.getPos1TY().y - 30 <= z3.getPos1().y + 0)
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
					else if (z3.getPos1().x > window1.getSize().x - 50)
					{
						z3.przesun1(-700, 0);
					}
					else if (z3.getPos1().y < 50)
					{
						z3.przesun1(0, +700);
					}
					else if (z3.getPos1().y > window1.getSize().y - 50)
					{
						z3.przesun1(0, -700);
					}
				}

				if (z5.getPos1TY().x - 70 <= z4.getPos1().x && z5.getPos1TY().x + 70 >= z4.getPos1().x && z5.getPos1TY().y + 70 >= z4.getPos1().y && z5.getPos1TY().y - 30 <= z4.getPos1().y + 0)
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
					else if (z4.getPos1().x > window1.getSize().x - 50)
					{
						z4.przesun1(-700, 0);
					}
					else if (z4.getPos1().y < 50)
					{
						z4.przesun1(0, +700);
					}
					else if (z4.getPos1().y > window1.getSize().y - 50)
					{
						z4.przesun1(0, -700);
					}
				}
				if (z5.getPos1TY().x <= -130)
				{
					z5.przesun1TY(700,0);
				}
				if (z5.getPos1TY().x >= window1.getSize().x + 100)
				{
					z5.przesun1TY(-700, 0);
				}
				if (z5.getPos1TY().y + 70 >= window1.getSize().y  + 100)
				{
					z5.przesun1TY(0,-700);
				}
				if (z5.getPos1TY().y <= 0 - 100)
				{
					z5.przesun1TY(0, 700);
				}
				sf::Text text3;
				text3.setPosition(sf::Vector2f(160, 20));
				text3.setFont(font);
				text3.setString(to_string(PODSUMOWANIEpkt));
				window1.clear();
				window1.draw(tloGry2);
				window1.draw(text3);
				window1.draw(z1.getZwierze());
				window1.draw(z2.getZwierze());
				window1.draw(z3.getZwierze());
				window1.draw(z4.getZwierze());
				window1.draw(z5.getZwierzeTY());
				window1.draw(text1);				
				window1.display();
				if (event1.key.code == sf::Keyboard::Escape)
				{
					window1.draw(text);
					window1.display();
					Sleep(1000);
				}
				if (event1.key.code == sf::Keyboard::F10)
				{
					system("cls");
					cout << "Wybrano i potwierdzono wyjscie";
					return 0;
				}
			}
		}
		cout << "Gratuluje , zdobyles : " << PODSUMOWANIEpkt << "punktow" << endl;

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

		if (PODSUMOWANIEpkt > 1250)
		{
			cout << "Wygrales rozgrywke!!!GRATULUJE!!!" << endl;
			Sleep(250);
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
				Sleep(3000);
				system("cls");
				cout << "Wyjscie..." << endl;
				return 0;
			}
		}
		else
		{
			cout << "Przykro mi... tym razem przegrales..." << endl;
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
				Sleep(3000);//wylacz okno po 3sek
				cout << "Wyjscie..." << endl;
				return 0;
			}
		}
	}
	else
	{
	cout << "Nie zdobyto wystarczajacej ilosci punktow w pierwszym etapie rozgrywki..." << endl;
	Sleep(1000);
	cout << "Gra za 3 sekundy sie wylaczy..." << endl;
	Sleep(3000);
	return 0;
	}
}



