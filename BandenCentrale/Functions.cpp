#include "Functions.h"
#include "Article.h"
#include "Rim.h"
#include "Tire.h"
#include "Customer.h"
#include "Company.h"
#include "Invoice.h"

void Dummy(TireCenter * TC)
{
	//temp data for uninmplemented stuff, should go entirely unused in the end
	std::cout << "DUMMY FUNCTION\n";
}
void ReadBaseData(Article * A, char AType, std::string Name, std::string ManuFacturer, int Diameter, float Price, int Stock);
void AddRim(Article*);
void AddTire(Article*);

void (*AddArticlePerType[])(Article*) = { AddRim , AddTire};

void AddArticle(TireCenter * TC)
{
	Article* A;
	
	int TypeChoice = -1;
	while (TypeChoice != 0 && TypeChoice != 1)
	{
		std::cout << "Choose article type:\n0: Rim\n1: Tire\n";
		std::cin >> TypeChoice;
		std::cin.ignore();
	}

	char TypeA = 'N';

	if (TypeChoice == 0)
	{
		A = new Rim();
		TypeA = 'R';
	}
	else
	{
		A = new Tire();
		TypeA = 'T';
	}

#pragma region Input
	std::string Name;
	std::cout << "Name of product: ";
	std::getline(std::cin, Name);

	std::string ManuFacturer;
	std::cout << "Manufacturer of product: ";
	std::getline(std::cin, ManuFacturer);

	int Diameter;
	std::cout << "Diameter of product: ";
	std::cin.clear();
	std::cin >> Diameter;
	std::cin.ignore();

	float Price;
	std::cout << "Price of product: ";
	std::cin.clear();
	std::cin >> Price;
	std::cin.ignore();

	int Stock;
	std::cout << "Stock of product: ";
	std::cin.clear();
	std::cin >> Stock;
	std::cin.ignore();

#pragma endregion

	ReadBaseData(A, TypeA, Name, ManuFacturer, Diameter, Price, Stock);

	(*AddArticlePerType[TypeChoice])(A);

	TC->AddArticle(A);
}

void ReadBaseData(Article * A, char AType, std::string Name, std::string ManuFacturer, int Diameter, float Price, int Stock)
{
	A->SetAType(AType);
	A->SetName(Name);
	A->SetManuFacturer(ManuFacturer);
	A->SetDiameter(Diameter);
	A->SetPrice(Price);
	A->SetStock(Stock);
}

void AddRim(Article *A)
{
	//convert into Rim
	Rim* R;
	R = dynamic_cast<Rim*>(A);

#pragma region RimInput
	bool Aluminum;
	std::cout << "Is the rim aluminum (1/0)?\n";
	std::cin >> Aluminum;
	std::cin.ignore();

	std::string Colour;
	std::cout << "Rim colour\n";
	std::getline(std::cin, Colour);

	int W;
	std::cout << "Rim Width\n";
	std::cin >> W;
	std::cin.ignore();

	R->SetAluminium(Aluminum);
	R->SetColour(Colour);
	R->SetWidth(W);
#pragma endregion

	A = R;
}

void AddTire(Article *A)
{
	Tire* R;
	R = dynamic_cast<Tire*>(A);
#pragma region TireInput
	int Width;
	int Height;
	std::string SI;
	char Season;

	std::cout << "Tire Width\n";
	std::cin >> Width;
	std::cin.ignore();
	std::cout << "Tire Height\n";
	std::cin >> Height;
	std::cin.ignore();
	std::cout << "Tire Speed Index\n";
	std::getline(std::cin, SI);
	std::cin.ignore();
	std::cout << "Tire Season\n";
	std::cin >> Season;
	std::cin.ignore();

	R->SetWidth(Width);
	R->SetHeight(Height);
	R->SetSpeedIndex(SI);
	R->SetSeason(Season);
#pragma endregion

	A = R;
}

//visual studio extraction gebruikt reference IPV pointer
void DrawArticleInformation(int ArticleIndex, Article& A)
{
	std::cout << ArticleIndex << ":";
	A.PrintInfo();
}

void SearchArticle(TireCenter* TC)
{
	std::cout << "Filter on: " << "\t1. Name\n\t\t2. Type\n\t\t3. Manufacturer\n\t\t4. Display All\n\t\t5. Cancel\n";

	int Choice = 0;
	while (Choice != 5)
	{
		std::cin.clear();
		std::cin >> Choice;
		std::cin.ignore();

		switch (Choice)
		{
		case 1:
		{
			std::cout << "Give Name of Article to filter on\n";
			std::string Input = "";
			std::getline(std::cin, Input);
			int ArticleIndex = 0;
			for (Article* A : TC->GetArticles())
			{
				if (!A->GetName().find(Input))
				{
					DrawArticleInformation(ArticleIndex, *A);
				}
				ArticleIndex++;
			}
			break;
		}
		case 2:
		{
			std::cout << "Give Type Article (T/R)\n";
			char Input = NULL;
			std::cin.clear();
			std::cin >> Input;
			int ArticleIndex = 0;
			for (Article* A : TC->GetArticles())
			{
				if (A->GetAType() == Input)
				{
					DrawArticleInformation(ArticleIndex, *A);
				}
				ArticleIndex++;
			}
			break;
		}
		case 3:
		{
			std::cout << "Give Manufacturer of Article to filter on\n";
			char Input = NULL;
			std::cin.clear();
			std::cin >> Input;
			int ArticleIndex = 0;
			for (Article* A : TC->GetArticles())
			{
				if (!A->GetManuFacturer().find(Input))
				{
					DrawArticleInformation(ArticleIndex, *A);
				}
				ArticleIndex++;
			}
			break;
		}
		case 4:
		{
				int ArticleIndex = 0;
				for (Article* A : TC->GetArticles())
				{
					DrawArticleInformation(ArticleIndex, *A);
					ArticleIndex++;
				}
				break;
			}			
		default:
			break;
		}
	}
}

void ChangeCompany(TireCenter* TC)
{
	int Choice = -1;
	while (Choice != 3)
	{
		std::cout << "1. Change Company Name\n2. Change Company Address\n3. Exit";
		std::cin.clear();
		std::cin >> Choice;
		std::cin.ignore();
		switch (Choice)
		{
			case(1):
			{
				std::string NewName;
				std::cout << "Give new address:\n";
				std::getline(std::cin, NewName);
				TC->SetName(NewName);
				break;
			}
			case(2):
			{
				std::string NewName;
				std::cout << "Give new address:\n";
				std::getline(std::cin, NewName);
				TC->SetAddress(NewName);
				break;
			}
		}
	}
}

const std::string SharedArticleOptions[] = 
{
	"Name",
	"Manufacturer",
	"Diameter",
	"Price",
	"Stock"
};

const std::string TireOptions[]
{
	"Width",
	"Height",
	"SpeedIndex",
	"Season",
};

const std::string RimOptions[]
{
	"Width",
	"IsAluminium",
	"Colour",
};

void ChangeArticle(TireCenter* TC)
{
	std::cout << "Give the item index of the item you want to modify: ";
	int Choice;
	std::cin.clear();
	std::cin >> Choice;
	std::cin.ignore();

	std::vector<Article*> Arts = TC->GetArticles();

	if (Choice >= 0 && (size_t)Choice < Arts.size())
	{
		//grab valid index
		Article* A = Arts[Choice];

		std::cout << "Select an option to change:\n";

		int SharedLength = sizeof(SharedArticleOptions) / sizeof(SharedArticleOptions[0]);

		for (int i = 0; i < SharedLength; i++)
		{
			std::cout << "\t" << i << " " << SharedArticleOptions[i] << "\n";
		}		

		switch (A->GetAType())
		{
			case 'R':
			{
				int TLen = sizeof(RimOptions) / sizeof(RimOptions[0]);
				for (int i = 0; i < TLen; i++)
				{
					std::cout << "\t" << i + SharedLength << " " << RimOptions[i] << "\n";
				}
				break;
			}
			case 'T':
			{
				int TLen = sizeof(TireOptions) / sizeof(TireOptions[0]);
				for (int i = 0; i < TLen; i++)
				{
					std::cout << "\t" << i + SharedLength << " " << TireOptions[i] << "\n";
				}
				break;
			}
		}

		Choice = 0;
		std::cin >> Choice;
		std::cin.ignore();		

		switch (Choice)
		{
		case 0:
		{
			std::cout << "Give new name: ";
			std::string B;
			std::getline(std::cin, B);
			A->SetName(B);
			break;
		}
		case 1:
		{
			std::cout << "Give new manufacturer: ";
			std::string B;
			std::getline(std::cin, B);
			A->SetManuFacturer(B);
			break;
		}
		case 2:
		{
			std::cout << "Give new diameter: ";
			int Dia;
			std::cin >> Dia;
			std::cin.ignore();
			A->SetDiameter(Dia);
			break;
		}
		case 3:
		{
			std::cout << "Give new price: ";
			float Dia;
			std::cin >> Dia;
			std::cin.ignore();
			A->SetPrice(Dia);
			break;
		}
		case 4:
		{
			std::cout << "Give new stock: ";
			int Dia;
			std::cin >> Dia;
			std::cin.ignore();
			A->SetStock(Dia);
			break;
		}
		case 5:
		{
			if (A->GetAType() == 'R')
			{
				Rim* R = dynamic_cast<Rim*>(A);
				std::cout << "Give new Width: ";
				int Dia;
				std::cin >> Dia;
				std::cin.ignore();
				R->SetWidth(Dia);
			}
			else
			{
				Tire* T = dynamic_cast<Tire*>(A);
				std::cout << "Give new Width: ";
				int Dia;
				std::cin >> Dia;
				std::cin.ignore();
				T->SetWidth(Dia);
			}
			break;
		}
		case 6:
		{
			if (A->GetAType() == 'R')
			{
				Rim* R = dynamic_cast<Rim*>(A);
				std::cout << "Give new aluminium setting: ";
				int Dia;
				std::cin >> Dia;
				std::cin.ignore();
				R->SetAluminium(Dia);
			}
			else
			{
				Tire* T = dynamic_cast<Tire*>(A);
				std::cout << "Give new Height: ";
				int Dia;
				std::cin >> Dia;
				std::cin.ignore();
				T->SetHeight(Dia);
			}
			break;
		}
		case 7:
		{
			if (A->GetAType() == 'R')
			{
				Rim* R = dynamic_cast<Rim*>(A);
				std::cout << "Give new colour: ";
				std::string B;
				std::getline(std::cin, B);
				R->SetColour(B);
			}
			else
			{
				Tire* T = dynamic_cast<Tire*>(A);
				std::cout << "Give new SpeedIndex: ";
				std::string B;
				std::getline(std::cin, B);
				T->SetSpeedIndex(B);
			}
			break;
		}
		case 8:
		{
			if (A->GetAType() == 'T')
			{
				Tire* T = dynamic_cast<Tire*>(A);
				std::cout << "Give new aluminium setting: ";
				char Dia;
				std::cin >> Dia;
				std::cin.ignore();
				T->SetSeason(Dia);
			}
			break;
		}
		}
	}
	else
	{
		std::cout << "Invalid index!\n";
	}
}

void DeleteArticle(TireCenter* TC)
{
	std::cout << "Give the item index of the item you want to delete: ";
	int Choice;
	std::cin.clear();
	std::cin >> Choice;
	std::cin.ignore();

	std::vector<Article*> Arts = TC->GetArticles();
	if (Choice >= 0 && (size_t)Choice < Arts.size())
	{
		TC->RemoveArticle(Choice);
	}
	else
	{
		std::cout << "Invalid index!\n";
	}
}

void DeleteCustomer(TireCenter* TC)
{
	std::cout << "Give the item index of the customer you want to delete: ";
	int Choice;
	std::cin.clear();
	std::cin >> Choice;
	std::cin.ignore();

	std::vector<Customer*> Custs = TC->GetCustomers();
	if (Choice >= 0 && (size_t)Choice < Custs.size())
	{
		TC->RemoveCustomer(Choice);
	}
	else
	{
		std::cout << "Invalid index!\n";
	}
}

void AddCustomer(TireCenter* TC)
{
	Customer* C;
	std::cout << "Is this a company? (1 if true): ";
	int Comp;
	std::cin >> Comp;
	std::cin.ignore();
	std::cin.clear();
	if (Comp == 1)
	{
		C = new Company();
		C->SetCType('C');
	}
	else
	{
		C = new Customer();
		C->SetCType('P');
	}

	std::string Buf;
	std::cout << "Name: ";
	std::getline(std::cin, Buf, '\n');
	std::cin.clear();
	C->SetName(Buf);
	std::cout << "Address: ";
	std::getline(std::cin, Buf, '\n');
	std::cin.clear();
	C->SetAddress(Buf);

	if (Comp == 1)
	{
		Company* Comp = dynamic_cast<Company*>(C);
		std::cout << "VAT number: ";
		std::getline(std::cin, Buf, '\n');
		std::cin.clear();
		Comp->SetVAT(Buf);
		int VolDisc;
		std::cout << "Volume discount: ";
		std::cin >> VolDisc;
		std::cin.ignore();
		std::cin.clear();
		Comp->SetVolumeDiscount(VolDisc);
	}

	TC->AddCustomer(C);
}

void SearchCustomer(TireCenter* TC)
{
	int Choice = 0;
	while (Choice != 4)
	{
		std::cout << "Filter on: \n\t1. Name\n\t2. Address\n\t3. Type\n\t4. No Filter\n\t5. Exit";
		std::cin.clear();
		std::cin >> Choice;
		std::cin.ignore();

		switch (Choice)
		{
		case 1:
		{
			std::cout << "Give Name to filter on\n";
			std::string Input = "";
			std::getline(std::cin, Input);
			int ArticleIndex = 0;
			for (Customer* A : TC->GetCustomers())
			{
				if (!A->GetName().find(Input))
				{
					std::cout << ArticleIndex << ":\n";
					A->PrintData();
				}
				ArticleIndex++;
			}
			break;
		}
		case 2:
		{
			std::cout << "Give Address to filter on\n";
			std::string Input = "";
			std::getline(std::cin, Input);
			int ArticleIndex = 0;
			for (Customer* A : TC->GetCustomers())
			{
				if (!A->GetAddress().find(Input))
				{
					std::cout << ArticleIndex << ":\n";
					A->PrintData();
				}
				ArticleIndex++;
			}
			break;
		}
		case 3:
		{
			std::cout << "Give Type To filter on (P/C)\n";
			char Input = NULL;
			std::cin.clear();
			std::cin >> Input;
			int ArticleIndex = 0;
			for (Customer* A : TC->GetCustomers())
			{
				if (A->GetCType() == Input)
				{
					std::cout << ArticleIndex << ":\n";
					A->PrintData();
				}
				ArticleIndex++;
			}
			break;
		}
		case 4:
		{
			int ArticleIndex = 0;
			for (Customer* A : TC->GetCustomers())
			{
				std::cout << ArticleIndex << ":\n";
				A->PrintData();
				ArticleIndex++;
			}
			break;
		}
		default:
			break;
		}
	}
}

void PlaceOrder(TireCenter* TC)
{
	//allocate invoice
	Invoice* MyInvoice = new Invoice();

	//if cancelled anywhere, de-allocate to avoid memleaks. Don't wanna make unneeded invoices that mess everything up, do we now?
	int CustomerID;
	//keep ids stored for quantity sake
	//std::vector<int> SelectedArticleIds;
	int Quantity;

	std::cout << "Enter Customer ID: ";
	std::cin >> CustomerID;
	std::cin.ignore();

	std::vector<Customer*> Custs = TC->GetCustomers();
	if (CustomerID >= 0 && (size_t)CustomerID < Custs.size())
	{
		//VALID - start adding Articles
		int Choice = 0;
		std::vector<Article*> Arts = TC->GetArticles();
		std::vector<int> Choices;
		MyInvoice->SetCustomer(Custs[CustomerID]->Clone());
		while (Choice != -1 && Choice != -2)
		{
			std::cout << "Enter article ID (-1 to end adding, -2 to cancel making invoice): ";
			std::cin >> Choice;
			std::cin.ignore();
			if (Choice >= 0 && Choice < Arts.size() && std::find(Choices.begin(), Choices.end(), Choice) == Choices.end())
			{
				//GOOD INDEX
				std::cout << "Are you sure you want to add this article (0 for no, 1 for yes)?\n";
				Arts[Choice]->PrintInfo();
				//just making sure...
				int Reassure = 0;
				std::cin >> Reassure;
				std::cin.ignore();
				if (Reassure != 0)
				{
					//alright now quantity
					std::cout << "How many would you like to buy\n";
					std::cin >> Quantity;
					std::cin.ignore();

					if (Quantity <= Arts[Choice]->GetStock())
					{
						//enough in stock
						Article* A = Arts[Choice]->Clone();
						MyInvoice->AddArticle(A);
						MyInvoice->AddQuantity(Quantity);
						Choices.push_back(Choice);
					}
					else
					{
						std::cout << "Not enough in stock!\n";
					}
				}
			}
			else if (Choice != -1 && Choice != -2)
			{
				std::cout << "Invalid Index/index already added\n";
			}
		}		
		if (Choice != -2)
		{
			//not cancelled
			//calculate price once since it won't change
			int TotalItems = 0;
			float TotalPrice = 0;
			std::vector<int> Quantitties = MyInvoice->GetQuantities();
			for (int i = 0; i < Choices.size(); i++)
			{
				TotalItems += Quantitties[i];
				TotalPrice += MyInvoice->GetArticles()[i]->GetPrice() * TotalItems;
				Arts[Choices[i]]->SetStock(Arts[Choices[i]]->GetStock() - Quantitties[i]);
			}			
			MyInvoice->SetPrice(TotalPrice);
			//DISCOUNT PERCENTAGE IF BIG ORDER :)
			if (MyInvoice->GetCustomer()->GetCType() == 'C')
			{
				//ELIGIBLE FOR DISCOUNT
				Company* C = dynamic_cast<Company*>(MyInvoice->GetCustomer());
				if (C->GetVolumeDiscount() > TotalItems)
				{
					//real discount hours
					//10% discount
					MyInvoice->SetDiscount(10);
				}
			}
			else
			{
				MyInvoice->SetDiscount(0);
			}

			std::cout << "End price: " << MyInvoice->CalcPrice() << "\n";

			TC->AddInvoice(MyInvoice);
		}
		else
		{
			delete MyInvoice;
			return;
		}
	}
	else
	{
		//INVALID
		std::cout << "Invalid ID!\n";
		delete MyInvoice;
		return;
	}
}

void CheckInvoices(TireCenter* TC)
{	
	//show all invoices
	int i = 0;
	std::vector<Invoice*> Invoices = TC->GetInvoices();
	for (Invoice* I : Invoices)
	{
		std::cout << i << ":\t" << I->GetCustomer()->GetName() << "\n";
		std::cout << "\t" << I->GetPrice() << "\n";
		i++;
	}

	int Choice = 0;
	while (Choice != -1)
	{
		std::cout << "Type ID of invoice you want to read more about (-1 to stop): ";
		std::cin >> Choice;
		std::cin.ignore();


		if (Choice >= 0 && Choice < Invoices.size())
		{
			Invoices[Choice]->PrintInfo();
		}
	}
}

void ChangeCustomer(TireCenter* TC)
{
	std::cout << "Customer ID to modify: ";
	int Choice;
	std::cin >> Choice;
	std::cin.ignore();
	std::vector<Customer*> Customers = TC->GetCustomers();
	if (Choice >= 0 && Choice < Customers.size())
	{
		std::cout << "Select an option:\n\t1: Change Name\n\t2: Change Address\n";
		if (Customers[Choice]->GetCType() == 'C')
		{
			std::cout << "\t3: VAT number\n\t4: Volume Discount";
		}
		int NextChoice;
		std::cin >> NextChoice;
		std::cin.ignore();
		switch (NextChoice)
		{
		case 1:
		{
			std::cout << "Give new name: ";
			std::string B;
			std::getline(std::cin, B);
			Customers[Choice]->SetName(B);
			break;
		}
		case 2:
		{
			std::cout << "Give new address: ";
			std::string B;
			std::getline(std::cin, B);
			Customers[Choice]->SetAddress(B);
		}
		case 3:
		{
			Company* C = dynamic_cast<Company*>(Customers[Choice]);
			std::cout << "Give new VAT: ";
			std::string B;
			std::getline(std::cin, B);
			C->SetVAT(B);
		}
		case 4:
		{
			Company* C = dynamic_cast<Company*>(Customers[Choice]);
			std::cout << "Give new volumediscount: ";
			int Dia;
			std::cin >> Dia;
			std::cin.ignore();
			C->SetVolumeDiscount(Dia);
			break;
		}
		}
	}
}