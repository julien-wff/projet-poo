#pragma once
#include "AbstractService.h"
#include "../entities/ClientEntity.h"
#include "../entities/OrderEntity.h"
#include "../entities/OrderItemEntity.h"
#include "../entities/PaymentEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class OrderService : AbstractService
    {
    public:
        DataTable^ GetOrders();
        Entities::OrderEntity^ GetOrder(String^ orderReference);
        String^ AddOrder(Entities::OrderEntity^ order);
        bool UpdateOrder(Entities::OrderEntity^ order);
        bool DeleteOrder(String^ orderReference);
        bool DeleteOrder(Entities::OrderEntity^ order);
        array<Entities::PaymentEntity^>^ GetPayments(Entities::OrderEntity^ order);
        array<Entities::OrderItemEntity^>^ GetOrderItems(Entities::OrderEntity^ order);
        Entities::ClientEntity^ GetClient(Entities::OrderEntity^ order);
        String^ GenerateOrderReference(Entities::ClientEntity^ client);
    };
}
