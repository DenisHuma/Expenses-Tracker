#include "tranzactie.h"

Tranzactie::Tranzactie()
{
    this->suma = 0;
    this->ziua = 0;
    this->id = 0;
    this->descriere = ' ';
    this->type = ' ';
}
Tranzactie::Tranzactie(int suma, int ziua, string descriere, string type)
{
    this->suma = suma;
    this->ziua = ziua;
    this->descriere = descriere;
    this->type = type;
    this->id = 0;
}
Tranzactie::~Tranzactie()
{
    this->suma = 0;
    this->ziua = 0;
    this->descriere = ' ';
    this->type = ' ';
}
void Tranzactie::setSuma(int suma)
{
    this->suma = suma;
}
void Tranzactie::setZiua(int ziua)
{
    this->ziua = ziua;
}
void Tranzactie::setDescriere(string descriere)
{
    this->descriere = descriere;
}
void Tranzactie::setType(string type)
{
    this->type = type;
}
int Tranzactie::getSuma()
{
    return this->suma;
}
int Tranzactie::getZiua()
{
    return this->ziua;
}
string Tranzactie::getDescriere()
{
    return this->descriere;
}
string Tranzactie::getType()
{
    return this->type;
}

int Tranzactie::getId()
{
    return this->id;
}

void Tranzactie::setId(int id)
{
    this->id = id;
}