#include "Company.h"
#include "Customer.h"

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
}

Company::~Company()
{
	VAT = "";
	VolumeDiscount = NULL;
}
