#pragma once
#include "Customer.h"
class Company : public Customer
{
	//inherit Customer
private:
	std::string VAT;
	int VolumeDiscount;
public:
	void SetVAT(std::string NewVAT);
	std::string GetVat();
	void SetVolumeDiscount(int NewDisc);
	int GetVolumeDiscount();
	Company(std::string VAT, int Disc);
	Company();
	~Company();
};

