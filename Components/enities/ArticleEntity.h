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
    ArticleEntity(int stock, String^ name, int maxStock, float vat, float price);
    ArticleEntity(int articleReference, int stock, String^ name, int maxStock, float vat, float price);
    ArticleEntity(DataRow^ row);
    float GetPrice();
    int GetArticleReference();
    int GetMaxStock();
    float GetVat();
    String^ GetName();
    int GetStock();
    void SetArticleReference(int articleReference);
    void SetName(String^ name);
    void SetMaxStock(int maxStock);
    void SetVat(float vat);
    void SetPrice(float price);
    void SetStock (int stock);
};


}
