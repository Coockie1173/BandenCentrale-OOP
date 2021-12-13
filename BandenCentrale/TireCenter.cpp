#include "TireCenter.h"

std::string TireCenter::GetName()
{
    return Name;
}

void TireCenter::SetName(std::string NewName)
{
    Name = NewName;
}

std::string TireCenter::GetAddress()
{
    return Address;
}

void TireCenter::SetAddress(std::string NewAddr)
{
    Address = NewAddr;
}

Article* TireCenter::GetArticle(int ArticleNo)
{
    return Articles[ArticleNo];
}

void TireCenter::SetArticle(int ArticleNo, Article* InArt)
{
    Articles[ArticleNo] = InArt;
}

std::vector<Article*> TireCenter::GetArticles()
{
    return Articles;
}

void TireCenter::SetArticles(std::vector<Article*> NewList)
{
    Articles = NewList;
}

Customer* TireCenter::GetCustomer(int CustomerNo)
{
    return Customers[CustomerNo];
}

void TireCenter::SetCustomer(int CustomerNo, Customer* NewCust)
{
    Customers[CustomerNo] = NewCust;
}

std::vector<Customer*> TireCenter::GetCustomers()
{
    return Customers;
}

void TireCenter::SetCustomers(std::vector<Customer*> NewCustomers)
{
    Customers = NewCustomers;
}

void TireCenter::AddCustomer(Customer* C)
{
    Customers.push_back(C);
}

void TireCenter::AddArticle(Article* A)
{
    Articles.push_back(A);
}

void TireCenter::RemoveArticle(int ArticleIndex)
{
    Articles.erase(Articles.begin() + ArticleIndex);
}

void TireCenter::RemoveCustomer(int ArticleIndex)
{
    Customers.erase(Customers.begin() + ArticleIndex);
}

TireCenter::TireCenter()
{
}

TireCenter::TireCenter(std::string Name, std::string addr, std::vector<Article*> Arts, std::vector<Customer*> Customers)
{
    this->Name = Name;
    Address = addr;
    Articles = Arts;
    this->Customers = Customers;
}

TireCenter::~TireCenter()
{

}

