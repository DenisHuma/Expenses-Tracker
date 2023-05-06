#include <iostream>
using namespace std;

class Tranzactie
{
private:
    int suma;
    int ziua;
    int id;
    string type;
    string descriere;

public:
    Tranzactie();
    Tranzactie(int suma, int ziua, string type, string descriere);
    ~Tranzactie();
    void setSuma(int suma);
    void setZiua(int ziua);
    void setType(string type);
    void setDescriere(string descriere);
    int getSuma();
    int getZiua();
    string getType();
    string getDescriere();
    int getId();
    void setId(int id);
};