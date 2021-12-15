#include "Company.h"
#include "Customer.h"
#include <iostream>

void Company::SetVAT(std::string NewVAT)
{
	Company::VAT = NewVAT;
}
std::string Company::GetVat()
{
	return Company::VAT;
}
void Company::SetVolumeDiscount(int NewDisc)
{
	Company::VolumeDiscount = NewDisc;
}
int Company::GetVolumeDiscount()
{
	return Company::VolumeDiscount;
}

Company::Company(std::string VAT, int Disc)
{
	this->VAT = VAT;
	VolumeDiscount = Disc;
}

Company::Company()
{
	VolumeDiscount = 0;
	VAT = "";
}

Company::~Company()
{
	VAT = "";
	VolumeDiscount = NULL;
}

void Company::PrintData()
{
	PrintBaseData();
	std::cout << "\t" << "VAT: " << this->GetVat() << "\n";
	std::cout << "\t" << "VolumeDiscount: " << this->GetVolumeDiscount() << "\n";
}

Customer* Company::Clone()
{
	return new Company(*this);
}
