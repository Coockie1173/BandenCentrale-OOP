#pragma once
#include <string>
#include "TireCenter.h"
//geen class nodig

static const std::string FilePath = ".\\TireCenterData";

void StoreInt(int AmmItems, std::ofstream& wf);

void StoreArticle(Article* A, std::ofstream& wf);

void SaveTireCenter(TireCenter*);

void StoreCustomer(Customer* C, std::ofstream& wf);

void ReadInt(std::ifstream& rf, int& AmmArticles);

TireCenter LoadTireCenter();