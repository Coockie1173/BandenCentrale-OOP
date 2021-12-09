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