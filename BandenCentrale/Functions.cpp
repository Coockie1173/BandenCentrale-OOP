#include "Functions.h"
#include "Article.h"
#include "Rim.h"
#include "Tire.h"

void Dummy(TireCenter * TC)
{
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
		std::cin.clear();
		std::cin >> TypeChoice;
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
	std::cin.clear();
	std::cin >> Name;
	std::string ManuFacturer;
	std::cout << "Manufacturer of product: ";
	std::cin.clear();
	std::cin >> ManuFacturer;
	int Diameter;
	std::cout << "Diameter of product: ";
	std::cin.clear();
	std::cin >> Diameter;
	float Price;
	std::cout << "Price of product: ";
	std::cin.clear();
	std::cin >> Price;
	int Stock;
	std::cout << "Stock of product: ";
	std::cin.clear();
	std::cin >> Stock;

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
	std::cin >> Colour;
	std::cin.ignore();
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
	std::cin >> SI;
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
	std::cout << "Filter on: " << "\t1. Name\n\t\t2. Type\n\t\t3. Manufacturer\n\t\t4. Diameter (Tire)\n\t\t5. Width (Rim/Tire)\n\t\t6. Display All\n\t\t7. Cancel\n";

	int Choice = 0;
	while (Choice != 7)
	{
		std::cin.clear();
		std::cin >> Choice;

		switch (Choice)
		{
		case 1:

			break;
		case 2:
		{
			std::cout << "Geef Type Article (T/R)\n";
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
		case 6:
			{
				int ArticleIndex = 0;
				for (Article* A : TC->GetArticles())
				{
					DrawArticleInformation(ArticleIndex, *A);
					ArticleIndex++;
				}
			}
			break;
		default:
			break;
		}
	}
}

void ChangeCompany(TireCenter* TC)
{
	std::cout << "1. Change Company Name\n2. Change Company Address\n3. Exit";
	int Choice = -1;
	while (Choice != 3)
	{
		std::cin.clear();
		std::cin >> Choice;
		std::cin.ignore();
		switch (Choice)
		{
			case(1):
			{
				std::string NewName;
				std::cout << "Give new name (NO SPACES):\n";
				std::cin.clear();
				std::cin >> NewName;
				std::cin.ignore();
				TC->SetName(NewName);
				break;
			}
			case(2):
			{
				std::string NewName;
				std::cout << "Give new address (NO SPACES):\n";
				std::cin.clear();
				std::cin >> NewName;
				std::cin.ignore();
				TC->SetAddress(NewName);
				break;
			}
		}
	}
}

void ChangeArticle(TireCenter* TC)
{
	std::cout << "Give the item index of the item you want to modify: ";
	int Choice;
	std::cin.clear();
	std::cin >> Choice;

	if (Choice > 0 && (size_t)Choice < TC->GetArticles().size())
	{
		//grab valid index
		
	}
}