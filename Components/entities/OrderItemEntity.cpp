#include "pch.h"
#include "OrderItemEntity.h"

Entities::OrderItemEntity::OrderItemEntity()
{
}

Entities::OrderItemEntity::OrderItemEntity(String^ orderReference, float price, float vat, float reductionValue,
                                           int itemCount) : OrderReference(orderReference), Price(price), Vat(vat),
                                                            ReductionValue(reductionValue), ItemCount(itemCount)
{
}

Entities::OrderItemEntity::OrderItemEntity(int articleVariantId, String^ orderReference, float price, float vat,
                                           float reductionValue, int itemCount) :
    ArticleVariantId(articleVariantId), OrderReference(orderReference), Price(price), Vat(vat),
    ReductionValue(reductionValue), ItemCount(itemCount)
{
}

Entities::OrderItemEntity::OrderItemEntity(DataRow^ row)
{
    this->ArticleVariantId = Convert::ToInt32(row["article_variant_id"]);
    this->OrderReference = Convert::ToString(row["order_reference"]);
    this->Price = Convert::ToSingle(row["price"]);
    this->Vat = Convert::ToSingle(row["vat"]);
    this->ReductionValue = Convert::ToSingle(row["reduction_value"]);
    this->ItemCount = Convert::ToInt32(row["item_count"]);
}

int Entities::OrderItemEntity::GetArticleVariantId()
{
    return ArticleVariantId;
}

String^ Entities::OrderItemEntity::GetOrderReference()
{
    return OrderReference;
}

float Entities::OrderItemEntity::GetPrice()
{
    return Price;
}

float Entities::OrderItemEntity::GetVat()
{
    return Vat;
}

int Entities::OrderItemEntity::GetItemCount()
{
    return ItemCount;
}

void Entities::OrderItemEntity::SetArticleVariantID(int articleVariantId)
{
    ArticleVariantId = articleVariantId;
}

void Entities::OrderItemEntity::SetOrderReference(String^ orderReference)
{
    OrderReference = orderReference;
}

void Entities::OrderItemEntity::SetPrice(float price)
{
    Price = price;
}

void Entities::OrderItemEntity::SetVat(float vat)
{
    Vat = vat;
}

void Entities::OrderItemEntity::SetReductionValue(float reductionValue)
{
    ReductionValue = reductionValue;
}

void Entities::OrderItemEntity::SetItemCount(int itemCount)
{
    ItemCount = itemCount;
}

float Entities::OrderItemEntity::GetReductionValue()
{
    return ReductionValue;
}
