#pragma once

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class OrderItemEntity
    {
    protected:
        int ArticleVariantId;
        String^ OrderReference;
        float Price;
        float Vat;
        float ReductionValue;
        int ItemCount;
    public:
        OrderItemEntity();
        OrderItemEntity(String^ orderReference, float price, float vat, float reductionValue, int itemCount);
        OrderItemEntity(int articleVariantId, String^ orderReference, float price, float vat, float reductionValue,
                        int itemCount);
        OrderItemEntity(DataRow^ row);
        int GetArticleVariantId();
        String^ GetOrderReference();
        float GetPrice();
        float GetVat();
        float GetReductionValue();
        int GetItemCount();
        void SetArticleVariantID(int articleVariantId);
        void SetOrderReference(String^ orderReference);
        void SetPrice(float price);
        void SetVat(float vat);
        void SetReductionValue(float reductionValue);
        void SetItemCount(int itemCount);
    };
}
