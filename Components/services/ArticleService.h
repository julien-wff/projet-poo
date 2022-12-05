#pragma once
#include "AbstractService.h"
#include "../entities/ArticleEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class ArticleService : public AbstractService
    {
    public:
        DataTable^ GetArticles();
        Entities::ArticleEntity^ GetArticle(int articleReference);
        int AddArticle(Entities::ArticleEntity^ article);
        bool UpdateArticle(Entities::ArticleEntity^ article);
        bool DeleteArticle(int articleReference);
        bool DeleteArticle(Entities::ArticleEntity^ article);
    };
}
