#include "pch.h"
#include "ArticleVariantEntity.h"

Entities::ArticleVariantEntity::ArticleVariantEntity()
{
}

Entities::ArticleVariantEntity::ArticleVariantEntity(int articleReference, String^ color, float reductionValue,
                                                     int reductionProductCount): ArticleReference(articleReference),
    Color(color), ReductionValue(reductionValue), ReductionProductCount(reductionProductCount)
{
}

Entities::ArticleVariantEntity::ArticleVariantEntity(int articleVariantId, int articleReference, String^ color,
                                                     float reductionValue, int reductionProductCount):
    ArticleVariantid(articleVariantId), ArticleReference(articleReference),
    Color(color), ReductionValue(reductionValue), ReductionProductCount(reductionProductCount)
{
}

Entities::ArticleVariantEntity::ArticleVariantEntity(DataRow^ row)
{
    this->ArticleVariantid = Convert::ToInt32(row["id"]);
    this->ArticleReference = Convert::ToInt32(row["articles_reference"]);
    this->Color = Convert::ToString(row["color"]);
    this->ReductionValue = Convert::ToSingle(row["reduction_value"]);
    this->ReductionProductCount = Convert::ToInt32(row["reduction_product_count"]);
}

int Entities::ArticleVariantEntity::GetArticleVariantId()
{
    return ArticleVariantid;
}

int Entities::ArticleVariantEntity::GetArticleReference()
{
    return ArticleReference;
}

String^ Entities::ArticleVariantEntity::GetColor()
{
    return Color;
}

float Entities::ArticleVariantEntity::GetReductionValue()
{
    return ReductionValue;
}

int Entities::ArticleVariantEntity::GetReductionProductCount()
{
    return ReductionProductCount;
}

void Entities::ArticleVariantEntity::SetArticleVariantId(int articleVariantId)
{
    ArticleVariantid = articleVariantId;
}

void Entities::ArticleVariantEntity::SetArticleReference(int articleReference)
{
    ArticleReference = articleReference;
}

void Entities::ArticleVariantEntity::SetColor(String^ color)
{
    Color = color;
}

void Entities::ArticleVariantEntity::SetReductionValue(float reductionValue)
{
    ReductionValue = reductionValue;
}

void Entities::ArticleVariantEntity::SetReductionProductCount(int reductionProductCount)
{
    ReductionProductCount = reductionProductCount;
}
