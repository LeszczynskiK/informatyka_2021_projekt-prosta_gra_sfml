#pragma once

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

class MenuTrudnosci
{
private:
	sf::Font czcionkaTrudnosci;
	sf::Text* menuTrudnosci;
	int wybranaOpcjaTrudnosci = 0;
public:
	MenuTrudnosci(float widthTrudnosci, float heightTrudnosci);
	~MenuTrudnosci() { delete[] menuTrudnosci; };
	void moveUpTrudnosci();
	void moveDownTrudnosci();
	int wybierzOpcjeTrudnosci() { return wybranaOpcjaTrudnosci; }
	void drawTrudnosci(sf::RenderWindow& windowTrudnosci);
};



class grzyb {
public:
	sf::Vector2f position;//wspolrzedne
	sf::Texture tekstura;
	sf::Texture teksturaty;//tekstura
	sf::RectangleShape GRZYB;
	grzyb(float x_in, float y_in);//tworz obiekt w polozeniu (x,y)
	void przesun(float x_in, float y_in);//przesun 
	void przesunTY(float x_in, float y_in);//przesun TY
	void idz(float x1, float y1);
	sf::RectangleShape getGrzyb() { return GRZYB; }//zwroc obiekt
	sf::Vector2f getPos() { return GRZYB.getPosition(); };
	sf::RectangleShape GRZYBty;
	sf::RectangleShape getGrzybTY() { return GRZYBty; }//zwroc obiekt	
	sf::Vector2f getPosTY() { return GRZYBty.getPosition(); };
	int punktyRozgrywki;
};

class zwierze {
public:
	sf::Vector2f position1;//wspolrzedne
	sf::RectangleShape ZWIERZE;
	sf::RectangleShape ZWIERZEty;
	zwierze(float x_in1, float y_in1);//tworz obiekt w polozeniu (x,y)
	void przesun1(float x_in1, float y_in1);//przesun 
	void idz1(float x11, float y11);
	sf::RectangleShape getZwierze() { return ZWIERZE; }//zwroc obiekt
	sf::RectangleShape getZwierzeTY() { return ZWIERZEty; }//zwroc obiekt
	sf::Vector2f getPos1() { return ZWIERZE.getPosition(); };
	sf::Vector2f getPos1TY() { return ZWIERZEty.getPosition(); };
	void przesun1TY(float x_in, float y_in);//przesun TY
	sf::Texture tekstura1;//tekstura
	sf::Texture tekstura1ty;//tekstura
};