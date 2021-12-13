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
void (*ExecutionPerState[])(TireCenter * TC) = { ChangeArticle, PlaceOrder, Dummy, AddCustomer, Dummy,
												 SearchArticle, SearchCustomer, AddArticle, DeleteArticle, DeleteCustomer,
												 ChangeCompany };

const std::string EmployeeOptions[] = {
	"Exit",
	"Change Article", //WIP
	"Place Order", //TODO
	"Check Invoices", //TODO
	"Add Customer",
	"Update Stock", //TODO?
	"Search Articles",
	"Search Customers",
};

const std::string ManagerOptions[]
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
		std::cin.ignore();
	}
	CurrentType = (TypeWerknemer)Input;

	int Choice = 1;
	while (Choice != 0)
	{
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

		std::cin.clear();
		std::cin >> Choice;

		if (((Choice > EmployeeArrSize - 1 && CurrentType == TypeWerknemer::Manager) || Choice <= EmployeeArrSize - 1) && Choice != 0)
		{
			(*ExecutionPerState[Choice-1])(&TC);
		}

	}

	SaveTireCenter(&TC);
	return 0;
}