#pragma once


using namespace System;
using namespace Data;

namespace Entities
{
public ref class ArticleEntity
{
protected:
    int ArticleReference;
    String^ Name;
    int Stock;
    int MaxStock;
    float Vat;
    float Price;
public:
    ArticleEntity();
    ArticleEntity(String^ name);
    ArticleEntity(int articleReference, String^ firstname);
    ArticleEntity(ArticleEntity^ person);
    ArticleEntity(DataRow^ row);
    float GetPrice();
    int GetArticleReference();
    int GetMaxStock();
    float GetVat();
    String^ GetName();
    void SetArticleReference(int articleReference);
    void SetName(String^ name);
    void SetMaxstock(int maxStock);
    void SetVat(float vat);
    void SetPrice(float price);
};

}
