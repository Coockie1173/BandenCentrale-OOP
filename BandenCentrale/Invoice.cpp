#include "Invoice.h"

Customer Invoice::GetCustomer()
{
    return Cust;
}

void Invoice::SetCustomer(Customer NewCust)
{
    Cust = NewCust;
}

std::vector<Article> Invoice::GetArticles()
{
    return Articles;
}

void Invoice::AddArticle(Article A)
{
    Articles.push_back(A);
}

void Invoice::SetArticles(std::vector<Article> A)
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

Invoice::Invoice(Customer C, std::vector<Article> Arts, float Price, int Disc)
{
    Cust = C;
    Articles = Arts;
    this->Price = Price;
    Discount = Disc;
}

Invoice::Invoice()
{
}

Invoice::~Invoice()
{
    Price = NULL;
    Discount = NULL;
}
