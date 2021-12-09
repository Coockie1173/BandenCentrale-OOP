#pragma once
#include "Customer.h"
#include "Article.h"
#include <vector>

class Invoice
{
private:
	Customer Cust;
	std::vector<Article> Articles;
	float Price;
	int Discount;
public:
	Customer GetCustomer();
	void SetCustomer(Customer NewCust);
	std::vector<Article> GetArticles();
	void AddArticle(Article A);
	void SetArticles(std::vector<Article> A);
	float GetPrice();
	void SetPrice(float P);
	int GetDiscount();
	void SetDiscount(int D);
	float CalcDiscount();
	float CalcPrice();
	Invoice(Customer C, std::vector<Article> Arts, float Price, int Disc);
	Invoice();
	~Invoice();
};

