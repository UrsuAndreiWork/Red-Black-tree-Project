
#include "Criminal.h"
using namespace std;
int Criminal::getID() const
{
    return ID;
}

void Criminal::setID(int ID)
{
    this->ID = ID;
}

string Criminal::getCrima() const
{
    return crima;
}

void Criminal::setNume(string nume)
{
    this->nume = nume;
}

string Criminal::getNume() const
{
    return nume;
}


void Criminal::setCrima(string crima)
{
    this->crima = crima;
}

char Criminal::getSex() const
{
    return sex;
}

void Criminal::setSex(char sex)
{
    this->sex = sex;
}

float Criminal::getInaltime() const
{
    return inaltime;
}

void Criminal::setInaltime(float inaltime)
{
    this->inaltime = inaltime;
}

int Criminal::getVarsta() const
{
    return varsta;
}

void Criminal::setVarsta(int varsta)
{
    this->varsta = varsta;
}

Criminal::Criminal(int ID,string nume, string crima, char sex, float inaltime, int varsta)
{
    this->ID = ID;
    this->nume = nume;
    this->crima = crima;
    this->sex = sex;
    this->inaltime = inaltime;
    this->varsta = varsta;
}
Criminal::Criminal()
{
    this->ID = 0;
    this->crima = "-";
    this->sex = '-';
    this->inaltime = 0;
    this->varsta = 0;
}


void Criminal::toStringList(vector<Criminal>& criminali)
{
    for (int i = 0; i < criminali.size();i++)
    {
        cout << "ID: " <<criminali[i].ID << endl;
        cout << "Nume: " << criminali[i].nume << endl;
        cout<<"Crima: " <<criminali[i].crima <<endl;
        cout << "Sex: " << criminali[i].sex<< endl;
        cout << "Inaltime: "<< criminali[i].inaltime << endl;
        cout <<"Varsta: "<<criminali[i].varsta << endl;
        cout << endl;
    }
}


 void Criminal::toString(Criminal cr)
{

        cout << "ID: " << cr.ID << endl;
        cout << "Nume: " << cr.nume << endl;
        cout << "Crima: " << cr.crima << endl;
        cout << "Sex: " << cr.sex << endl;
        cout << "Inaltime: " << cr.inaltime << endl;
        cout << "Varsta: " << cr.varsta << endl;
        cout << endl;
}

vector<Criminal> Criminal::generateCriminals(int nr)
{
    vector<Criminal> criminali;


    srand(time(NULL));
    char s;
    for (int i = 0; i < nr; i++)
    {
        if (i % 2 == 0)
            s = 'm';
        else s = 'f';
        criminali.push_back(Criminal(rand()%10000,"Costel "+to_string(i) , "-", s, 2+rand()%2 -static_cast <float> (rand()) / static_cast <float> (RAND_MAX), 7+rand() % 100));
    }

    return criminali;
}
