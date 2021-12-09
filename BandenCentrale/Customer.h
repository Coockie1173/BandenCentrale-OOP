#pragma once
#include <string>

class Customer
{
private:
	std::string Name;
	std::string Address;
	char CType;
public:
	std::string GetName();
	void SetName(std::string NewName);
	std::string GetAddress();
	void SetAddress(std::string NewAddr);
	char GetCType();
	void SetCType(char NewType);
	Customer();
	Customer(std::string Name, std::string Addr, char Type);
	~Customer();
};

