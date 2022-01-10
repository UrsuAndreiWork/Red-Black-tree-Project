
#include "Engine.h"

using namespace std;
using namespace sf;

 sf::Event ev;

void Engine::DrawWindow(int x, int y)
{
    window.create(sf::VideoMode(x, y), "SFML window");
    heightWindow = x;
    lenghtWindow = y;
   
    sf::Texture* t=new sf::Texture();
    t->loadFromFile("imagini/bgpolitie.jpg");
    fundal.setTexture(*t);
    window.draw(fundal);
 
     
    sf::Texture* t1 = new sf::Texture();
    t1->loadFromFile("imagini/text_box.png");
    text_box.setTexture(*t1);
    text_box.setScale(0.8f,1.0f);
    text_box.setPosition(140, 600);

    sf::Texture* t2 = new sf::Texture();
    t2->loadFromFile("imagini/id_card.png");
    id_card.setTexture(*t2);
    id_card.setScale(1.1f, 1.0f);
    id_card.setPosition(430, 80);

    sf::Texture* t3 = new sf::Texture();
    t3->loadFromFile("imagini/button.png");
    button1.setTexture(*t3);
    button1.setScale(0.1f, 0.1f);
    button1.setPosition(80, 770);

    sf::Texture* t4 = new sf::Texture();
    t4->loadFromFile("imagini/button.png");
    button2.setTexture(*t4);
    button2.setScale(0.1f, 0.1f);
    button2.setPosition(380, 770);


    sf::Texture* t5 = new sf::Texture();
    t5->loadFromFile("imagini/button.png");
    button3.setTexture(*t5);
    button3.setScale(0.1f, 0.1f);
    button3.setPosition(680, 770);

    sf::Texture* t6 = new sf::Texture();
    t6->loadFromFile("imagini/button.png");
    button4.setTexture(*t6);
    button4.setScale(0.1f, 0.1f);
    button4.setPosition(980, 770);




    window.display();
}

void Engine::LoadData()
{
 
     crim = Criminal::generateCriminals(6);
      Criminal::toStringList(crim);

     for (int i = 0; i < crim.size(); i++)
     {
        RB->RBInsert(RBTree::createNode(crim[i]));  //* ADD
     }
  //*  RB->del(RB->search(RB->root, 5555555));  DEL + search
   //* RB->indentedDisplay();
    
}


void Engine::Play()
{
    sf::Font font;
    font.loadFromFile("Amaranth-Regular.otf");
    string inputS = "";
    Text outputS;
    outputS.setFillColor(Color::White);
    outputS.setPosition(270, 615);
    outputS.setString("...");
    outputS.setFont(font);
    outputS.setCharacterSize(100);
    window.setFramerateLimit(60);
    int i = 0;
    //*modele de scris
   //* Scris PorcBNB(font, "PorcBNB", 75, 640, 60, false, sf::Color(255, 255, 255));
   //* Scris PorcBNBOrange(font, "PorcBNB", 75, 140, 60, true, sf::Color(100, 153, 24));
   
    Scris ID(font, "", 20, 680, 225, true , sf::Color(0, 0, 0));
    Scris Nume(font, "", 20, 680, 255, true, sf::Color(0, 0, 0));
    Scris Crima(font, "", 20, 680, 285, true, sf::Color(0, 0, 0));
    Scris Sex(font, "", 20, 680, 315, true, sf::Color(0, 0, 0));
    Scris Inaltime(font, "", 20, 680, 345, true, sf::Color(0, 0, 0));
    Scris Varsta(font, "", 20, 680, 375, true, sf::Color(0, 0, 0));
    Scris Delete(font, "Delete", 40, 130, 780, true, sf::Color(0, 0, 0));
    Scris Scroll(font, "Display", 40, 420, 780, true, sf::Color(0, 0, 0));
    Scris Add(font, "Add", 40, 750, 780, true, sf::Color(0, 0, 0));
    Scris Modify(font, "Modify", 40, 1030, 780, true, sf::Color(0, 0, 0));

    int ok = 10,ok1=10,ok2=10; //*ceva timer,n-are imp, belive me
    while (window.isOpen())
    {

        if (ok == 10)
        {    button2.setColor(sf::Color(255, 255, 255));}
        else { ok++; }
        if (ok1 == 10)
        { button3.setColor(sf::Color(255, 255, 255));}
        else { ok1++; }
        if (ok2 == 10)
        {   button4.setColor(sf::Color(255, 255, 255));}
        else { ok2++; }

            window.draw(fundal);
            window.draw(text_box);
            window.draw(id_card);
            window.draw(button1);

            while (window.pollEvent(ev))
            {




                // Request for closing the window
                if (ev.type == sf::Event::Closed)
                    window.close();

                if (ev.type == sf::Event::TextEntered)
                {
                    //*  cout << "A fost apasat:" << static_cast<char>(ev.text.unicode) << endl;
                }

                if (ev.type == sf::Event::MouseButtonPressed)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                   //* cout << position.x << " " << position.y << endl;

                    //*delete
                    if (position.x >= 76 && position.x <= 296 && position.y >= 768 && position.y <= 855)
                    {

                        if (del == false)
                        {
                            button1.setColor(sf::Color(66, 245, 72));
                            del = true;
                        }
                        else if (del == true)
                        {
                            button1.setColor(sf::Color(255, 255, 255));
                            del = false;
                        }
                    }
                
   
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    //*afisare
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    if (position.x >= 372 && position.x <= 593 && position.y >= 768 && position.y <= 855)
                    {
                        ok = 0;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        RB->indentedDisplay();
               
                        button2.setColor(sf::Color(66, 245, 72));
                        
                    }
                    //*add
                    if (position.x >= 676 && position.x <= 893 && position.y >= 768 && position.y <= 855)
                    {
                        ok1 = 0;
                        
                        int id1, varsta1; string nume1, crima1;
                        char sex1; float inaltime1;
                        cout << "ID criminal: ";
                        cin >> id1;
                        cout << "Nume criminal: ";
                        cin >> nume1;
                        cout << "Crima criminal: ";
                        cin >> crima1;
                        cout << "Sex criminal: ";
                        cin >> sex1;
                        cout << "Inaltime criminal: ";
                        cin >> inaltime1;
                        cout << "Varsta criminal: ";
                        cin >> varsta1;
                       Criminal criminal(id1,nume1,crima1,sex1,inaltime1,varsta1);
                       RB->RBInsert(RBTree::createNode(criminal));
                       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                       RB->indentedDisplay();
                       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        button3.setColor(sf::Color(66, 245, 72));
                    }
                    //*modify
                    if (position.x >= 977 && position.x <= 1192 && position.y >= 768 && position.y <= 855)
                    {
                        ok2 = 0;
                        int id1;
                        cout << "ID criminal de modificat: ";
                        cin >> id1;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                       RBNode *nod= RBTree::search(RB->root,id1);
                       Criminal::toString(nod->criminal);
                       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                       int varsta1; string nume1, crima1;
                       char sex1; float inaltime1;
                       cout << "Change ID criminal: ";
                       cin >> id1;
                       cout << "Change nume criminal: ";
                       cin >> nume1;
                       cout << "Change crima criminal: ";
                       cin >> crima1;
                       cout << "Change sex criminal: ";
                       cin >> sex1;
                       cout << "Change inaltime criminal: ";
                       cin >> inaltime1;
                       cout << "Change varsta criminal: ";
                       cin >> varsta1;

                       Criminal newCrim(id1, nume1, crima1, sex1, inaltime1, varsta1);
                       RB->del(nod);
                       RB->RBInsert(RBTree::createNode(newCrim));
                       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                       Criminal::toString(newCrim);
                       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                       RB->indentedDisplay();
                       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        button4.setColor(sf::Color(66, 245, 72));
                    }
                }
                //*sa cauti

                if (ev.type == sf::Event::TextEntered) {
                    if (ev.text.unicode < 128 && static_cast<char>(ev.text.unicode) >= 48 && static_cast<char>(ev.text.unicode) <= 122) {
                        if (inputS.size() < 4)
                        {
                            inputS += (static_cast<char>(ev.text.unicode));
                            outputS.setString(inputS);
                
                        }
                    }
                }

                if (ev.type == sf::Event::KeyPressed)
                {
                    if (ev.key.code == sf::Keyboard::BackSpace)
                    {
                        if (inputS.size() > 0)
                        {
                            inputS.erase(inputS.size() - 1, 1);
                            outputS.setString(inputS);
                        }
         
                    }

                    if (ev.key.code == sf::Keyboard::Enter)
                    {
                        //*se sterge
                        if (inputS.size() > 0 && del == true)
                        {

                            ID.setScris("ID: " + to_string(RBTree::search(RB->root, stoi(inputS))->criminal.getID()));
                            Nume.setScris("Nume: " + RBTree::search(RB->root, stoi(inputS))->criminal.getNume());
                            Crima.setScris("Crima: " + RBTree::search(RB->root, stoi(inputS))->criminal.getCrima());
                            string s;
                            s = RBTree::search(RB->root, stoi(inputS))->criminal.getSex();
                            Sex.setScris("Sex: " + s);
                            Inaltime.setScris("Inaltime: " + to_string(RBTree::search(RB->root, stoi(inputS))->criminal.getInaltime()));
                            Varsta.setScris("Varsta: " + to_string(RBTree::search(RB->root, stoi(inputS))->criminal.getVarsta()));

                            //*sa nu sterg de 2 ori un nod deja sters ca ia foc si plang
                            if (RBTree::isNil(RBTree::search(RB->root, stoi(inputS))) == false)
                            {
                                RB->del(RB->search(RB->root, stoi(inputS)));
                            }
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            RB->indentedDisplay();

                        }
                        //*se afiseaza
                        if (inputS.size() > 0 && del == false)
                        {
                            ID.setScris("ID: " + to_string(RBTree::search(RB->root, stoi(inputS))->criminal.getID()));
                            Nume.setScris("Nume: " + RBTree::search(RB->root, stoi(inputS))->criminal.getNume());
                            Crima.setScris("Crima: " + RBTree::search(RB->root, stoi(inputS))->criminal.getCrima());
                            string s;
                            s = RBTree::search(RB->root, stoi(inputS))->criminal.getSex();
                            Sex.setScris("Sex: " + s);
                            Inaltime.setScris("Inaltime: " + to_string(RBTree::search(RB->root, stoi(inputS))->criminal.getInaltime()));
                            Varsta.setScris("Varsta: " + to_string(RBTree::search(RB->root, stoi(inputS))->criminal.getVarsta()));

                        }
                    }

                }
            }
       
            window.draw(button2);
            window.draw(button3);
            window.draw(button4);
            window.draw(ID.getText());
            window.draw(Nume.getText());
            window.draw(Crima.getText());
            window.draw(Sex.getText());
            window.draw(Inaltime.getText());
            window.draw(Varsta.getText());
            window.draw(Add.getText());
            window.draw(Delete.getText());
            window.draw(Scroll.getText());
            window.draw(Modify.getText());
            window.draw(outputS);
            window.display();
            window.clear();
        }

    }


int Engine::getHeigtWindow()
{
    return heightWindow;
}
int Engine::getLenghtWindow()
{
    return lenghtWindow;
}
