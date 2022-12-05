#pragma once
#include "AbstractService.h"
#include "../entities/ArticleVariantEntity.h"
#include "../entities/OrderItemEntity.h"
#include "../entities/OrderEntity.h"
#include "../entities/ArticleEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class OrderItemService : public AbstractService
    {
    public:
        DataTable^ GetOrderItems();
        Entities::OrderItemEntity^ GetOrderItem(int articleVariantId, String^ orderReference);
        int AddOrderItem(Entities::OrderItemEntity^ orderItem);
        bool UpdateOrderItem(Entities::OrderItemEntity^ orderItem);
        bool DeleteOrderItem(int articleVariantId, String^ orderReference);
        bool DeleteOrderItem(Entities::OrderItemEntity^ orderItem);
        Entities::OrderEntity^ GetOrder(String^ orderReference);
        Entities::ArticleVariantEntity^ GetArticleVariant(int articleVariantId);
        Entities::ArticleEntity^ GetArticle(int articleReference);
    };
}