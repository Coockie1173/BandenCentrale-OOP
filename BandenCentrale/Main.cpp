#include <iostream>
#include "TireCenter.h"
#include "Functions.h"
#include "FileHandler.h"

enum class TypeWerknemer
{
	Undefined = -1,
	Manager = 0,
	Employee = 1
};

//update array accordingly
void (*ExecutionPerState[])(TireCenter * TC) = { Dummy, Dummy, Dummy, Dummy, Dummy, SearchArticle, AddArticle, Dummy, Dummy, ChangeCompany };

std::string EmployeeOptions[] = {
	"Exit",
	"Change Article",
	"Place Order",
	"Check Invoices",
	"Add Customer",
	"Update Stock",
	"Search Articles"
};

std::string ManagerOptions[]
{
	"Add Article",
	"Delete Article",
	"Delete Customer",
	"Change company Name and Address"
};

int main(void)
{
	int Input = -1;
	TypeWerknemer CurrentType = TypeWerknemer::Undefined;
	TireCenter TC = LoadTireCenter();
	//TireCenter TC;
	//TC.SetName("Nae Nae");
	//TC.SetAddress("CringeStraat 96 9111 Belsele");
	
	std::cout << TC.GetName() << "\n" << TC.GetAddress() << "\n\n";

	while (Input != 0 && Input != 1)
	{
		std::cout << "What type of employee are you?\nManager = 0\nEmployee = 1\n";
		std::cin >> Input;
	}
	CurrentType = (TypeWerknemer)Input;

	int Choice = 1;
	while (Choice != 0)
	{
		/*
		std::cout << "Make your choice:\n";
		std::cout << "0: Exit\n";
		std::cout << "1: Change Article\n";
		std::cout << "2: Change Customer\n";
		std::cout << "3: Place order\n";
		std::cout << "4: Check Invoices\n";
		std::cout << "5: Add Customer\n";
		std::cout << "6: Update Stock\n";
		if (CurrentType == TypeWerknemer::Manager)
		{
			std::cout << "7: Add Article\n";
			std::cout << "8: Delete Article\n";
			std::cout << "9: Delete Customer\n";
		}*/

		int EmployeeArrSize = sizeof(EmployeeOptions) / sizeof(EmployeeOptions[0]);

		for (int j = 0; j < EmployeeArrSize; j++)
		{
			std::cout << j << " " << EmployeeOptions[j] << "\n";
		}

		if (CurrentType == TypeWerknemer::Manager)
		{
			int ManagerArrSize = sizeof(ManagerOptions) / sizeof(ManagerOptions[0]);
			for (int j = 0; j < ManagerArrSize; j++)
			{
				std::cout << j + EmployeeArrSize << " " << ManagerOptions[j] << "\n";
			}
		}

		std::cin >> Choice;

		if (((Choice > EmployeeArrSize - 1 && CurrentType == TypeWerknemer::Manager) || Choice <= EmployeeArrSize - 1) && Choice != 0)
		{
			(*ExecutionPerState[Choice-1])(&TC);
		}

	}

	SaveTireCenter(&TC);
	return 0;
}