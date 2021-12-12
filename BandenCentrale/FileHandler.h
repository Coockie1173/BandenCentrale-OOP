#pragma once
#include <string>
#include "TireCenter.h"
//geen class nodig

static const std::string FilePath = ".\\TireCenterData";

void StoreInt(int AmmItems, std::ofstream& wf);

void SaveTireCenter(TireCenter*);

void ReadInt(std::ifstream& rf, int& AmmArticles);

TireCenter LoadTireCenter();