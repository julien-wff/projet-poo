#include "pch.h"
#include "ArticleEntity.h"

Entities::ArticleEntity::ArticleEntity()
{
}

Entities::ArticleEntity::ArticleEntity(int stock, String^ name, int maxStock, float vat, float price) : Stock(stock),
    Name(name), MaxStock(maxStock), Vat(vat), Price(price)
{
}

Entities::ArticleEntity::ArticleEntity(int articleReference, int stock, String^ name, int maxStock, float vat,
                                       float price) : ArticleReference(articleReference), Stock(stock), Name(name),
                                                      MaxStock(maxStock), Vat(vat), Price(price)
{
}

Entities::ArticleEntity::ArticleEntity(DataRow^ row)
{
    this->ArticleReference = Convert::ToInt32(row["reference"]);
    this->Name = row["name"]->ToString();
    this->MaxStock = Convert::ToInt32(row["max_stock"]);
    this->Vat = Convert::ToSingle(row["vat"]);
    this->Stock = Convert::ToInt32(row["stock"]);
    this->Price = Convert::ToSingle(row["price"]); 
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

int Entities::ArticleEntity::GetStock()
{
    return Stock;
}

void Entities::ArticleEntity::SetArticleReference(int articleReference)
{
    ArticleReference = articleReference;
}

void Entities::ArticleEntity::SetName(String^ name)
{
    Name = name;
}

void Entities::ArticleEntity::SetMaxStock(int maxStock)
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
void Entities::ArticleEntity::SetStock(int stock)
{
    Stock = stock;
}

