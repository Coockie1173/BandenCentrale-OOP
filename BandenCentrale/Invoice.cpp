#include "Invoice.h"
#include <iostream>

Customer* Invoice::GetCustomer()
{
    return Cust;
}

void Invoice::SetCustomer(Customer* NewCust)
{
    Cust = NewCust;
}

std::vector<Article*> Invoice::GetArticles()
{
    return Articles;
}

void Invoice::AddArticle(Article* A)
{
    Articles.push_back(A);
}

void Invoice::SetArticles(std::vector<Article*> A)
{
    Articles = A;
}

float Invoice::GetPrice()
{
    return Price;
}

void Invoice::SetPrice(float P)
{
    Price = P;
}

int Invoice::GetDiscount()
{
    return Discount;
}

void Invoice::SetDiscount(int D)
{
    Discount = D;
}

float Invoice::CalcDiscount()
{
    return (Price / 100)*Discount;
}

float Invoice::CalcPrice()
{
    return Price - CalcDiscount();
}

Invoice::Invoice(Customer* C, std::vector<Article*> Arts, float Price, int Disc)
{
    Cust = C;
    Articles = Arts;
    this->Price = Price;
    Discount = Disc;
}

Invoice::Invoice()
{
    Cust = NULL;
    Discount = 0;
    Price = NULL;
}

Invoice::~Invoice()
{
    Price = NULL;
    Discount = NULL;
    for (Article* A : Articles)
    {
        delete A;
    }
    delete Cust;
}

void Invoice::AddQuantity(int Q)
{
    Quantities.push_back(Q);
}

std::vector<int> Invoice::GetQuantities()
{
    return Quantities;
}

void Invoice::SetQuantities(std::vector<int> Q)
{
    Quantities = Q;
}

void Invoice::PrintInfo()
{
    std::cout << "Customer info:\n";
    Cust->PrintData();
    std::cout << "Articles: \n";
    for (Article* A : Articles)
    {
        A->PrintInfo();
    }
    std::cout << "End price: " << CalcPrice() << "\n";
}
