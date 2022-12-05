#pragma once
#include "AbstractService.h"
#include "../entities/ArticleEntity.h"
#include "../entities/ArticleVariantEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class ArticleVariantService : public AbstractService
    {
    private:
        void FillCommand(SqlClient::SqlCommand^ command, Entities::ArticleVariantEntity^ articleVariant);
    public:
        DataTable^ GetArticleVariants();
        Entities::ArticleVariantEntity^ GetArticleVariant(int id);
        int AddArticleVariant(Entities::ArticleVariantEntity^ articleVariant);
        bool UpdateArticleVariant(Entities::ArticleVariantEntity^ articleVariant);
        bool DeleteArticleVariant(int id);
        bool DeleteArticleVariant(Entities::ArticleVariantEntity^ articleVariant);
        Entities::ArticleEntity^ GetArticle(Entities::ArticleVariantEntity^ articleVariant);
    };
}
