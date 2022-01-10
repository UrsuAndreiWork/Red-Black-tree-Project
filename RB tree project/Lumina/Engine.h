#include "RBNode.h"
#include "Header.h"
using namespace std;
using namespace sf;

class Engine
{

protected:
	RBTree *RB=new RBTree();
	sf::RenderWindow window;
	vector<Criminal> crim;

	sf::Sprite fundal;
	sf::Sprite text_box;
	sf::Sprite id_card;
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Sprite button4;

	bool del=false;
	bool scroll = false;

	int heightWindow, lenghtWindow;
private:

public:
	void DrawWindow(int x, int y);
	void Play();
	int getHeigtWindow();
	int getLenghtWindow();
	void LoadData();

};



class Scris:public Engine{
	Text text;
	int pozX, pozY;
	string scris;
public:
	Scris(sf::Font& fontulet, string s, int size, int x, int y, bool cul, sf::Color culoare)
	{
		text.setFont(fontulet);
		scris = s;
		text.setString(scris);
		pozX = x;
		pozY = y;
		text.setCharacterSize(size);
		text.setPosition(x, y);
		if (cul == true)
			text.setFillColor(culoare);
	}
	void setColor(sf::Color cul)
	{
		text.setColor(cul);
	}
	//* nu mai mere oof
	void afisare()
	{
		window.draw(text);
	}
	int getX()
	{
		return pozX;
	}
	int getY()
	{
		return pozY;
	}
	void afisarePozitii()
	{
		cout << "X: " << pozX << endl;
		cout << "Y: " << pozY << endl;
	}
	void setFont(sf::Font& fontulet)
	{
		text.setFont(fontulet);
	}
	void setScris(string s)
	{
		scris = s;
		text.setString(scris);
	}
	void setPozitii(int x, int y)
	{
		pozX = x;
		pozY = y;
		text.setPosition(pozX, pozY);
	}
	Text getText()
	{
		return text;
	}


};


