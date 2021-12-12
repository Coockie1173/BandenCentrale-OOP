#include "Rim.h"
#include <iostream>

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
    Aluminium = false;
    Width = 0;
    Colour = "";
}

Rim::~Rim()
{
    Aluminium = NULL;
    Colour = "";
    Width = NULL;
}

void Rim::PrintInfo()
{
    PrintBaseData();
    std::cout << "\t" << "Aluminium: " << this->GetAluminium() << "\n";
    std::cout << "\t" << "Colour: " << this->GetColour() << "\n";
    std::cout << "\t" << "Width (Rim): " << this->GetWidth() << "\n";
}