#pragma once


using namespace System;
using namespace Data;

namespace Entities
{
    public ref class ArticleVariantEntity
    {
    protected:
        int ArticleVariantid;
        int ArticleReference;
        String^ Color;
        float ReductionValue;
        int ReductionProductCount;
    public:
        ArticleVariantEntity();
        ArticleVariantEntity(int articleReference, String^ color, float reductionValue, int reductionProductCount);
        ArticleVariantEntity(int articleVariantId, int articleReference, String^ color, float reductionValue,
                             int reductionProductCount);
        ArticleVariantEntity(DataRow^ row);
        int GetArticleVariantId();
        int GetArticleReference();
        String^ GetColor();
        float GetReductionValue();
        int GetReductionProductCount();
        void SetArticleVariantId(int articleVariantId);
        void SetArticleReference(int articleReference);
        void SetColor(String^ color);
        void SetReductionValue(float reductionValue);
        void SetReductionProductCount(int reductionProductCount);
    };
}