#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Article.h"

class TireCenter
{
private:
	std::string Name;
	std::string Address;
	std::vector<Article*> Articles;
	std::vector<Customer*> Customers;

public:
	std::string GetName();
	void SetName(std::string NewName);
	std::string GetAddress();
	void SetAddress(std::string NewAddr);
	Article* GetArticle(int ArticleNo);
	void SetArticle(int ArticleNo, Article* InArt);
	std::vector<Article*> GetArticles();
	void SetArticles(std::vector<Article*> NewList);	
	Customer* GetCustomer(int CustomerNo);
	void SetCustomer(int CustomerNo, Customer* NewCust);
	std::vector<Customer*> GetCustomers();
	void SetCustomers(std::vector<Customer*> NewCustomers);
	void AddCustomer(Customer* C);
	void AddArticle(Article* A);
	void RemoveArticle(int ArticleIndex);

	TireCenter();
	TireCenter(std::string Name, std::string addr, std::vector<Article*> Arts, std::vector<Customer*> Customers);
	~TireCenter();
};

