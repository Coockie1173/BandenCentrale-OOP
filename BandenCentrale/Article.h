#pragma once
#include <string>

class Article
{
private:
	std::string Name;
	std::string ManuFacturer;
	int Stock;
	int Diameter;
	float Price;
	char AType;
public:
	std::string GetName();
	void SetName(std::string NewName);
	std::string GetManuFacturer();
	void SetManuFacturer(std::string NewManuFacturer);
	int GetStock();
	void SetStock(int NewStock);
	int GetDiameter();
	void SetDiameter(int NewDiameter);
	float GetPrice();
	void SetPrice(float NewPrice);
	char GetAType();
	void SetAType(char NewType);
	Article(std::string Name, std::string Fac, int Stock, int Diameter, float Price, char Type);
	Article();
	//~Article();
	virtual ~Article();
};

