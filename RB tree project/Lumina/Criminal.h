#include "Header.h"
using namespace std;
class Criminal
{
	int ID;
    string nume;
	string crima;
	char sex;
	float inaltime;
	int varsta;

public:
    int getID() const;
    void setID(int ID);

    string getNume() const;
    void setNume(string nume);

    string getCrima() const;
    void setCrima(string crima);

    char getSex() const;
    void setSex(char sex);

    float getInaltime() const;
    void setInaltime(float inaltime);

    int getVarsta() const;
    void setVarsta(int varsta);

   Criminal(int ID,string nume, string crima, char sex, float inaltime, int varsta);
   Criminal();
    static vector<Criminal> generateCriminals(int nr);

    static void toStringList(vector<Criminal>& criminali);
    static void toString(Criminal cr);
};

