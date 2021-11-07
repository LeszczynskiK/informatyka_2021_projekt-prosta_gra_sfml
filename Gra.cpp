#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
using namespace sf;

class Player
{
public:
	int iloscPunktow = 0;
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	
}MojaPostac;

void Player::MoveUp()
{

}

void Player::MoveDown()
{

}

void Player::MoveRight()
{

}

void Player::MoveLeft()
{

}

int main()
{
	sf::Time czas;
	sf::Clock zegar;
	int totalPoints = 0;
		sf::RectangleShape tloGry;
		tloGry.setSize(sf::Vector2f(1440, 960));
		sf::Texture tekstura;
		tekstura.loadFromFile("tlo.png");
		tloGry.setTexture(&tekstura);


		sf::Texture teksturaGracz;
		teksturaGracz.loadFromFile("charakter.png");
		sf::Sprite Gracz(teksturaGracz, sf::IntRect(0, 0, 1440, 1440));
		Gracz.setScale(sf::Vector2f(0.075f, 0.075f));
		int X = 780; // poczatkowe kordynaty x dla sprite'a
		int Y = 450; // poczatkowe kordynaty y dla sprite'a

		sf::Texture tekstura1;
		tekstura1.loadFromFile("grzyb1.png");
		sf::Sprite Grzyb1(tekstura1, sf::IntRect(0, 0, 800, 600));
		Grzyb1.setScale(sf::Vector2f(0.075f, 0.075f));
		int X1 = 150;
		int Y1 = 150;
		Grzyb1.setPosition(X1, Y1);
		int grzyb1PKT = 2;

		sf::Texture tekstura2;
		tekstura2.loadFromFile("grzyb2.png");
		sf::Sprite Grzyb2(tekstura2, sf::IntRect(0, 0, 800, 600));
		Grzyb2.setScale(sf::Vector2f(0.075f, 0.075f));
		int X2 = 350;
		int Y2 = 180;
		Grzyb2.setPosition(X2, Y2);
		int grzyb2PKT = 5;

		sf::Texture tekstura3;
		tekstura3.loadFromFile("grzyb3.png");
		sf::Sprite Grzyb3(tekstura3, sf::IntRect(0, 0, 800, 600));
		Grzyb3.setScale(sf::Vector2f(0.075f, 0.075f));
		int X3 = 575;
		int Y3 = 280;
		Grzyb3.setPosition(X3, Y3);
		int grzyb3PKT = 7;

		sf::Texture tekstura4;
		tekstura4.loadFromFile("grzyb4.png");
		sf::Sprite Grzyb4(tekstura4, sf::IntRect(0, 0, 800, 600));
		Grzyb4.setScale(sf::Vector2f(0.1f, 0.1f));
		int X4 = 730;
		int Y4 = 800;
		Grzyb4.setPosition(X4, Y4);
		int grzyb4PKT = 10;

		sf::Texture tekstura5;
		tekstura5.loadFromFile("grzyb5.png");
		sf::Sprite Grzyb5(tekstura5, sf::IntRect(0, 0, 800, 600));
		Grzyb5.setScale(sf::Vector2f(0.1f, 0.1f));
		int X5 = 1150;
		int Y5 = 200;
		Grzyb5.setPosition(X5, Y5);
		int grzyb5PKT = 13;

		sf::RenderWindow window(sf::VideoMode(1440, 960), "Forest Game!");
		sf::Event event;
		zegar.restart();
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
				{
					window.close();
				}

				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))

				{
					X -= 10;

				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
				{
					X += 10;
				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))

				{
					Y -= 10;

				}
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
				{
					Y += 10;
				}

			}

			Gracz.setPosition(X, Y);
			if (Gracz.getPosition().x > window.getSize().x - 100 || Gracz.getPosition().x < 0)
			{
				X = 650;
			}
			else if (Gracz.getPosition().y > window.getSize().y - 100 || Gracz.getPosition().y < 0)
			{
				Y = 500;
			}

		           if (Gracz.getPosition().x - 50 <= Grzyb1.getPosition().x && Gracz.getPosition().x +105 >= Grzyb1.getPosition().x && Gracz.getPosition().y +70 >= Grzyb1.getPosition().y && Gracz.getPosition().y -10 <= Grzyb1.getPosition().x +0)
			{
				Grzyb1.setPosition(X1+=167, Y1+=123);
				while (X1 >= 1375 || Y1 >=900)
				{
					X1 = 200, Y1 = 150;
					Grzyb1.setPosition(X1, Y1);
				}
				
				totalPoints += grzyb1PKT;
				system("cls");
				cout << "Razem zebrales punktow: " << endl;
				cout << totalPoints << endl;
			};

				   if (Gracz.getPosition().x - 50 <= Grzyb2.getPosition().x && Gracz.getPosition().x + 105 >= Grzyb2.getPosition().x && Gracz.getPosition().y + 70 >= Grzyb2.getPosition().y && Gracz.getPosition().y - 10 <= Grzyb2.getPosition().x + 0)
				   {
					   Grzyb2.setPosition(X2 += 167, Y2 += 123);
					   while (X2 >= 1375 || Y2 >= 900)
					   {
						   X2 = 200, Y2 = 150;
						   Grzyb2.setPosition(X2, Y2);
					   }

					   totalPoints += grzyb2PKT;
					   system("cls");
					   cout << "Razem zebrales punktow: " << endl;
					   cout << totalPoints << endl;
				   };

				   if (Gracz.getPosition().x - 50 <= Grzyb3.getPosition().x && Gracz.getPosition().x + 105 >= Grzyb3.getPosition().x && Gracz.getPosition().y + 70 >= Grzyb3.getPosition().y && Gracz.getPosition().y - 10 <= Grzyb3.getPosition().x + 0)
				   {
					   Grzyb3.setPosition(X3 += 167, Y3 += 123);
					   while (X3 >= 1375 || Y3 >= 900)
					   {
						   X3 = 200, Y3 = 150;
						   Grzyb3.setPosition(X3, Y3);
					   }

					   totalPoints += grzyb3PKT;
					   system("cls");
					   cout << "Razem zebrales punktow: " << endl;
					   cout << totalPoints << endl;
				   };

				   if (Gracz.getPosition().x - 50 <= Grzyb4.getPosition().x && Gracz.getPosition().x + 105 >= Grzyb4.getPosition().x && Gracz.getPosition().y + 70 >= Grzyb4.getPosition().y && Gracz.getPosition().y - 10 <= Grzyb4.getPosition().x + 0)
				   {
					   Grzyb4.setPosition(X4 += 167, Y4 += 123);
					   while (X4 >= 1375 || Y4 >= 900)
					   {
						   X4 = 200, Y4 = 150;
						   Grzyb4.setPosition(X4, Y4);
					   }

					   totalPoints += grzyb4PKT;
					   system("cls");
					   cout << "Razem zebrales punktow: " << endl;
					   cout << totalPoints << endl;
				   };


				   if (Gracz.getPosition().x - 50 <= Grzyb5.getPosition().x && Gracz.getPosition().x + 105 >= Grzyb5.getPosition().x && Gracz.getPosition().y + 70 >= Grzyb5.getPosition().y && Gracz.getPosition().y - 10 <= Grzyb5.getPosition().x + 0)
				   {
					   Grzyb5.setPosition(X5 += 167, Y5 += 123);
					   while (X5 >= 1375 || Y5 >= 900)
					   {
						   X5 = 200, Y5 = 150;
						   Grzyb5.setPosition(X5, Y5);
					   }

					   totalPoints += grzyb5PKT;
					   system("cls");
					   cout<<"Razem zebrales punktow: "<<endl;
					   cout << totalPoints << endl;
				   };
			window.clear();
			window.draw(tloGry);
			window.draw(Gracz);
			window.draw(Grzyb1);
			window.draw(Grzyb2);
			window.draw(Grzyb3);
			window.draw(Grzyb4);
			window.draw(Grzyb5);
			window.display();
			
			if (zegar.getElapsedTime().asSeconds() > 30)
			{
				window.close();
				system("cls");
				cout << "Dzielny wojowniku , twoj czas sie skonczyl..." << endl;
				cout << "Zdobyles: " << totalPoints << "punktow" << endl;
			}
		}

	
	return 0;
}