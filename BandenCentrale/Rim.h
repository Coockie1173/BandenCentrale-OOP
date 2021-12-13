#pragma once
#include "Article.h"
class Rim : public Article
{
	//inherit article
private:
	bool Aluminium;
	std::string Colour;
	int Width;
public:
	bool GetAluminium();
	void SetAluminium(bool A);
	std::string GetColour();
	void SetColour(std::string Col);
	int GetWidth();
	void SetWidth(int W);
	Rim(bool Al, std::string Col, int W);
	Rim();
	~Rim();

	void PrintInfo() override;
	Article* Clone() override;
};

