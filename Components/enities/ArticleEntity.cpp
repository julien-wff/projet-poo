#include "pch.h"
#include "ArticleEntity.h"

Entities::ArticleEntity::ArticleEntity()
{
}

Entities::ArticleEntity::ArticleEntity(String^ name)
{
}

Entities::ArticleEntity::ArticleEntity(int articleReference, String^ firstname)
{
}

Entities::ArticleEntity::ArticleEntity(ArticleEntity^ person)
{
}

Entities::ArticleEntity::ArticleEntity(DataRow^ row)
{
    this->ArticleReference = Convert::ToInt32(row["reference"]);
    this->Name = row["name"]->ToString();
    this->MaxStock = Convert::ToInt32(row["stock"]);
    this->Vat = Convert::ToSingle(row["vat"]);
        
}

float Entities::ArticleEntity::GetPrice()
{
    return Price;
}

int Entities::ArticleEntity::GetArticleReference()
{
    return ArticleReference;
}

int Entities::ArticleEntity::GetMaxStock()
{
    return MaxStock;
}

float Entities::ArticleEntity::GetVat()
{
    return Vat;
}

String^ Entities::ArticleEntity::GetName()
{
    return Name;
}

void Entities::ArticleEntity::SetArticleReference(int articleReference)
{
    ArticleReference = articleReference;
    
}

void Entities::ArticleEntity::SetName(String^ name)
{
    Name = name;
}

void Entities::ArticleEntity::SetMaxstock(int maxStock)
{
    MaxStock = maxStock;
}

void Entities::ArticleEntity::SetVat(float vat)
{
    Vat = vat;
}

void Entities::ArticleEntity::SetPrice(float price)
{
    Price = price;
}



