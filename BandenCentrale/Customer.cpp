#include "Customer.h"
#include <iostream>

void Customer::PrintBaseData()
{
	std::cout << "\t" << "Name: " << this->GetName() << "\n";
	std::cout << "\t" << "Address: " << this->GetAddress() << "\n";
}

Customer* Customer::Clone()
{
	return new Customer(*this);
}

std::string Customer::GetName() { return Name; };
void Customer::SetName(std::string NewName) { Name = NewName; };
std::string Customer::GetAddress() { return Address; };
void Customer::SetAddress(std::string NewAddr) { Address = NewAddr; };
char Customer::GetCType() { return CType; };
void Customer::SetCType(char NewType) { CType = NewType; }
Customer::Customer()
{
	this->Name = "";
	this->Address = "";
	CType = NULL;
}

Customer::Customer(std::string Name, std::string Addr, char Type)
{
	this->Name = Name;
	this->Address = Addr;
	CType = Type;
}

void Customer::PrintData()
{
	PrintBaseData();
}
