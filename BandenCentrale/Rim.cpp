#include "Rim.h"

bool Rim::GetAluminium()
{
    return Aluminium;
}

void Rim::SetAluminium(bool A)
{
    Aluminium = A;
}

std::string Rim::GetColour()
{
    return Colour;
}

void Rim::SetColour(std::string Col)
{
    Colour = Col;
}

int Rim::GetWidth()
{
    return Width;
}

void Rim::SetWidth(int W)
{
    Width = W;
}

Rim::Rim(bool Al, std::string Col, int W)
{
    Aluminium = Al;
    Colour = Col;
    Width = W;
}

Rim::Rim()
{
}

Rim::~Rim()
{
    Aluminium = NULL;
    Colour = "";
    Width = NULL;
}
