#pragma once
#include "TireCenter.h"
#include <iostream>

//dummy function that does NOTHING
void Dummy(TireCenter*);

void AddArticle(TireCenter*);
void DrawArticleInformation(int ArticleIndex, Article& A);
void SearchArticle(TireCenter*);
void ChangeCompany(TireCenter*);
void ChangeArticle(TireCenter*);
void DeleteArticle(TireCenter*);
void AddCustomer(TireCenter*);
void DeleteCustomer(TireCenter*);
void SearchCustomer(TireCenter*);
void PlaceOrder(TireCenter*);