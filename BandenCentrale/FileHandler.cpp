#include <iostream>
#include <bit>
#include <fstream>
#include "FileHandler.h"
#include "Rim.h"
#include "Tire.h"
#include "Company.h"
#include "Customer.h"

void StoreInt(int AmmItems, std::ofstream& wf)
{
	for (int i = 0; i < sizeof(int); i++)
	{
		char CurItem = (AmmItems >> (i * 8)) & 0b11111111;
		wf.write(&CurItem, sizeof(CurItem));
	}
}

void ReadInt(std::ifstream& rf, int& AmmArticles)
{
	AmmArticles = 0;
	char buf;
	for (int i = 0; i < sizeof(int); i++)
	{
		rf.read(&buf, sizeof(buf));
		//AmmArticles |= buf;
		//AmmArticles <<= (i * 8);
		//buf <<= (i * 8);
		int Temp = ((int)buf) << (i * 8) & (0b11111111 << (i * 8));
		AmmArticles |= Temp;
	}
}

void StoreFloat(float Amm, std::ofstream& wf)
{
	//cast float bits to int
	int buf = std::_Bit_cast<int>(Amm);
	StoreInt(buf, wf);
}

void ReadFloat(std::ifstream& rf, float& Amm)
{
	int buf = 0;
	ReadInt(rf, buf);
	Amm = std::_Bit_cast<float>(buf);
}

void StoreString(std::string str, std::ofstream& wf)
{
	int StrSize = str.size();
	StoreInt(StrSize, wf);
	wf.write(str.c_str(), StrSize);
}

std::string ReadString(std::ifstream& rf)
{
	int StrLen = 0;
	ReadInt(rf, StrLen);
	char* CharBuf = (char*)calloc(StrLen + 1, sizeof(char));
	rf.read(CharBuf, StrLen);
	std::string Name;
	if (CharBuf != 0)
	{
		return std::string(CharBuf);
	}
	else
	{
		return "";
	}
}

void SaveTireCenter(TireCenter* TC)
{
	//adhv https://www.tutorialspoint.com/reading-and-writing-binary-file-in-c-cplusplus
	std::ofstream wf(FilePath, std::ios::out | std::ios::binary | std::ios::trunc);

	if (!wf) {
		std::cout << "Cannot open file!" << std::endl;
		return;
	}

	//no lazy D:
	//wf.write((char*)TC, sizeof(TireCenter));

	//store string size + string, max 255 length on both
	StoreString(TC->GetName(), wf);
	StoreString(TC->GetAddress(), wf);

	//conver int to bytes and write
	int AmmItems = TC->GetArticles().size();
	StoreInt(AmmItems, wf);

	std::vector<Article*> Articles = TC->GetArticles();

	for (Article* A : Articles)
	{
		//iterate over every article
		//store generic data first
		//important for allocation, Type first;
		char buf = A->GetAType();
		wf.write(&buf, sizeof(buf));
		StoreInt(A->GetDiameter(), wf);
		StoreInt(A->GetStock(), wf);
		StoreString(A->GetManuFacturer(), wf);
		StoreString(A->GetName(), wf);
		StoreFloat(A->GetPrice(), wf);
		switch (buf)
		{
			case 'R':
			{
				Rim *R = dynamic_cast<Rim*>(A);
				int B = R->GetAluminium();
				StoreInt(B, wf);
				StoreString(R->GetColour(), wf);
				StoreInt(R->GetWidth(), wf);
				break;
			}
			case 'T':
			{
				Tire *T = dynamic_cast<Tire*>(A);
				StoreInt(T->GetWidth(), wf);
				StoreInt(T->GetHeight(), wf);
				StoreString(T->GetSpeedIndex(), wf);
				buf = T->GetSeason();
				wf.write(&buf, sizeof(buf));
				break;
			}
		}
	}

	AmmItems = TC->GetCustomers().size();
	StoreInt(AmmItems, wf);

	std::vector<Customer*> Customers = TC->GetCustomers();

	for (Customer* C : Customers)
	{
		char buf = C->GetCType();
		wf.write(&buf, sizeof(buf));
		StoreString(C->GetName(), wf);
		StoreString(C->GetAddress(), wf);
		if (buf == 'C')
		{
			Company* CMP = dynamic_cast<Company*>(C);
			StoreString(CMP->GetVat(),wf);
			StoreInt(CMP->GetVolumeDiscount(), wf);
		}
	}

	std::vector<Invoice*> Invoices = TC->GetInvoices();

	wf.close();

	if (!wf.good()) {
		std::cout << "Error occurred at writing time!\n";
		return;
	}
}

TireCenter LoadTireCenter()
{
	std::ifstream rf(FilePath, std::ios::out | std::ios::binary);
	if (!rf) {
		std::cout << "Cannot open file!\n";
		return TireCenter();
	}

	TireCenter TC;

	TC.SetName(ReadString(rf));
	TC.SetAddress(ReadString(rf));

	//restore int
	int AmmArticles = 0;
	ReadInt(rf, AmmArticles);

	std::vector<Article*> Articles;

	for (int i = 0; i < AmmArticles; i++)
	{
		//read type
		char Typ;
		rf.read(&Typ, sizeof(Typ));

		Article* A;

		switch (Typ)
		{
			case 'R':
			{
				A = new Rim();
				break;
			}
			case 'T':
			{
				A = new Tire();
				break;
			}
			default:
			{
				//???? someone is modifying our files! Let's assume it's a rim and pray!
				A = new Rim();
			}
		}

		A->SetAType(Typ);
		int Num;
		ReadInt(rf, Num);
		A->SetDiameter(Num);
		ReadInt(rf, Num);
		A->SetStock(Num);
		A->SetManuFacturer(ReadString(rf));
		A->SetName(ReadString(rf));
		float F;
		ReadFloat(rf, F);
		A->SetPrice(F);

		switch (Typ)
		{
			case 'R':
			{
				Rim* R = dynamic_cast<Rim*>(A);
				ReadInt(rf, Num);
				R->SetAluminium(Num);
				R->SetColour(ReadString(rf));
				ReadInt(rf, Num);
				R->SetWidth(Num);
				TC.AddArticle(R);
				break;
			}
			case 'T':
			{
				Tire* T = dynamic_cast<Tire*>(A);
				ReadInt(rf, Num);
				T->SetHeight(Num);
				ReadInt(rf, Num);
				T->SetWidth(Num);
				T->SetSpeedIndex(ReadString(rf));
				/*ReadInt(rf, Num);
				T->SetWidth(Num);*/
				char buf;
				rf.read(&buf, sizeof(buf));
				T->SetSeason(buf);
				TC.AddArticle(T);
				break;
			}
			default:
			{
				//just in case something does go wrong
				TC.AddArticle(A);
				break;
			}
		}
	}

	std::vector<Customer*> Customers;
	ReadInt(rf, AmmArticles);

	for (int i = 0; i < AmmArticles; i++)
	{
		Customer* C;
		char Typ;
		rf.read(&Typ, sizeof(Typ));

		if (Typ == 'C')
		{
			C = new Company();
		}
		else
		{
			C = new Customer();
		}

		C->SetName(ReadString(rf));
		C->SetAddress(ReadString(rf));
		if (Typ == 'C')
		{
			Company* CMP = dynamic_cast<Company*>(C);
			CMP->SetVAT(ReadString(rf));
			int Disc;
			ReadInt(rf, Disc);
			CMP->SetVolumeDiscount(Disc);
		}

		Customers.push_back(C);
	}
	TC.SetCustomers(Customers);

	rf.close();
	//not using .good because it doesn't hit EOF somehow?
	if (rf.fail()) {
		std::cout << "Error occurred at reading time!\n";
		//error reading, send out clean TireCenter
		return TireCenter();
	}

	return TC;
}
