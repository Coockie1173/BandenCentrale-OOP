#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Article.h"
#include "Invoice.h"

class TireCenter
{
private:
	std::string Name;
	std::string Address;
	std::vector<Article*> Articles;
	std::vector<Customer*> Customers;
	std::vector<Invoice*> Invoices;
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
	void RemoveCustomer(int ArticleIndex);
	void AddInvoice(Invoice* I);
	void RemoveInvoice(int InvoiceID);
	void SetInvoices(std::vector<Invoice*> Invoices);
	Invoice* GetInvoice(int InvoiceID);
	std::vector<Invoice*> GetInvoices();
	void SetInvoice(Invoice* I, int Index);

	TireCenter();
	TireCenter(std::string Name, std::string addr, std::vector<Article*> Arts, std::vector<Customer*> Customers);
	~TireCenter();
};

