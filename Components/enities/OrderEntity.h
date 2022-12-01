#pragma once

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class OrderEntity
    {
    protected:
        String^ OrderReference;
        DateTime DeliveryDate;
        DateTime CreationDate;
        int ClientId;
    public:
        OrderEntity();
        OrderEntity(DateTime deliveryDate, DateTime creationDate, int clientId);
        OrderEntity(String^ orderReference, DateTime deliveryDate, DateTime creationDate, int clientId);
        OrderEntity(DataRow^ row);
        String^ GetOrderReference();
        DateTime GetDeliveryDate();
        DateTime GetCreationDate();
        int GetClientId();
        void SetOrderReference(String^ orderReference);
        void SetDeliveryDate(DateTime deliveryDate);
        void SetCreationDate(DateTime creationDate);
        void SetClientId(int clientId);
    };
}
