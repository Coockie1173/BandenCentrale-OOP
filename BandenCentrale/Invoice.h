#pragma once
#include "Customer.h"
#include "Article.h"
#include <vector>

class Invoice
{
private:
	Customer* Cust;
	std::vector<Article*> Articles;
	std::vector<int> Quantities;
	float Price;
	int Discount;
	float CalcDiscount();
public:
	Customer* GetCustomer();
	void SetCustomer(Customer* NewCust);
	std::vector<Article*> GetArticles();
	void AddArticle(Article* A);
	void SetArticles(std::vector<Article*> A);
	float GetPrice();
	void SetPrice(float P);
	int GetDiscount();
	//in percentage
	void SetDiscount(int D);	
	float CalcPrice();
	Invoice(Customer* C, std::vector<Article*> Arts, float Price, int Disc);
	Invoice();
	~Invoice();
	void AddQuantity(int Q);
	std::vector<int> GetQuantities();
	void SetQuantities(std::vector<int> Q);
	void PrintInfo();
};

