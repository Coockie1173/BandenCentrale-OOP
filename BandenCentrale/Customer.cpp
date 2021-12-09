#include "Customer.h"

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
Customer::~Customer()
{
	Name = "";
	Address = "";
	CType = NULL;
}