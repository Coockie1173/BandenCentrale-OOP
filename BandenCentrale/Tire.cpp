
#include "Tire.h"

int Tire::GetWidth()
{
    return Width;
}

void Tire::SetWidth(int InH)
{
    Width = InH;
}

int Tire::GetHeight()
{
    return Height;
}

void Tire::SetHeight(int InH)
{
    Height = InH;
}

std::string Tire::GetSpeedIndex()
{
    return SpeedIndex;
}

void Tire::SetSpeedIndex(std::string SPD)
{
    SpeedIndex = SPD;
}

char Tire::GetSeason()
{
    return Season;
}

void Tire::SetSeason(char C)
{
    Season = C;
}

Tire::Tire()
{
    Width = 0;
    Height = 0;
    SpeedIndex = "";
    Season = NULL;
}

Tire::Tire(int W, int H, int SI, char Seas)
{
    Width = W;
    Height = H;
    SpeedIndex = SI;
    Season = Seas;
}

Tire::~Tire()
{
    Width = NULL;
    Height = NULL;
    SpeedIndex = "";
    Season = NULL;
}
