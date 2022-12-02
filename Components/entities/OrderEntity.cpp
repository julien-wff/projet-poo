#include "pch.h"
#include "OrderEntity.h"

Entities::OrderEntity::OrderEntity()
{
}

Entities::OrderEntity::OrderEntity(DateTime deliveryDate, DateTime creationDate, int clientId) :
    DeliveryDate(deliveryDate), CreationDate(creationDate), ClientId(clientId)
{
}

Entities::OrderEntity::OrderEntity(String^ orderReference, DateTime deliveryDate, DateTime creationDate, int clientId) :
    OrderReference(orderReference), DeliveryDate(deliveryDate), CreationDate(creationDate), ClientId(clientId)
{
}

Entities::OrderEntity::OrderEntity(DataRow^ row)
{
    this->ClientId = Convert::ToInt32(row["client_id"]);
    this->OrderReference = Convert::ToString(row["reference"]);
    this->DeliveryDate = Convert::ToDateTime(row["delivery_date"]);
    this->CreationDate = Convert::ToDateTime(row["creation_date"]);
}

String^ Entities::OrderEntity::GetOrderReference()
{
    return OrderReference;
}

DateTime Entities::OrderEntity::GetDeliveryDate()
{
    return DeliveryDate;
}

DateTime Entities::OrderEntity::GetCreationDate()
{
    return CreationDate;
}

int Entities::OrderEntity::GetClientId()
{
    return ClientId;
}

void Entities::OrderEntity::SetOrderReference(String^ orderReference)
{
    OrderReference = orderReference;
}

void Entities::OrderEntity::SetDeliveryDate(DateTime deliveryDate)
{
    DeliveryDate = deliveryDate;
}

void Entities::OrderEntity::SetCreationDate(DateTime creationDate)
{
    CreationDate = creationDate;
}

void Entities::OrderEntity::SetClientId(int clientId)
{
    ClientId = clientId;
}
