#include "Article.h"

std::string Article::GetName() { return Name; }
void Article::SetName(std::string NewName) { Name = NewName; }
std::string Article::GetManuFacturer() { return ManuFacturer; }
void Article::SetManuFacturer(std::string NewManuFacturer) { ManuFacturer = NewManuFacturer; }
int Article::GetStock() { return Stock; }
void Article::SetStock(int NewStock) { Stock = NewStock; }
int Article::GetDiameter() { return Diameter; }
void Article::SetDiameter(int NewDiameter) { Diameter = NewDiameter; }
float Article::GetPrice() { return Price; }
void Article::SetPrice(float NewPrice) { Price = NewPrice; }
char Article::GetAType() { return AType; }
void Article::SetAType(char NewType) { AType = NewType; }


Article::Article(std::string Name, std::string Fac, int Stock, int Diameter, float Price, char Type)
{
	this->Name = Name;
	this->ManuFacturer = Fac;
	this->Stock = Stock;
	this->Diameter = Diameter;
	this->Price = Price;
	this->AType = Type;
}

Article::Article()
{
	this->Name = "";
	this->ManuFacturer = "";
	this->Stock = 0;
	this->Diameter = 0;
	this->Price = 0;
	this->AType = 0;
}

Article::~Article()
{
}

/*
Article::~Article()
{
	Name = "";
	ManuFacturer = "";
	Stock = NULL;
	Diameter = NULL;
	Price = NULL;
	AType = NULL;
}
*/
