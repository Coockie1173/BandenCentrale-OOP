#pragma once
#include "Article.h"
#include <string>
class Tire : public Article
{
	//inherit Article
private:
	int Width;
	int Height;
	std::string SpeedIndex;
	char Season;
public:
	int GetWidth();
	void SetWidth(int InH);
	int GetHeight();
	void SetHeight(int InH);
	std::string GetSpeedIndex();
	void SetSpeedIndex(std::string SPD);
	char GetSeason();
	void SetSeason(char C);

	Tire();
	Tire(int W, int H, int SI, char Seas);
	~Tire();
};

