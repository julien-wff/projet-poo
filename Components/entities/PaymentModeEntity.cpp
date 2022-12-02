#include "pch.h"
#include "PaymentModeEntity.h"

Entities::PaymentModeEntity::PaymentModeEntity()
{
}

Entities::PaymentModeEntity::PaymentModeEntity(String^ name): Name(name)
{
}

Entities::PaymentModeEntity::PaymentModeEntity(int paymentModeId, String^ name): PaymentModeId(paymentModeId), Name(name)
{
}

Entities::PaymentModeEntity::PaymentModeEntity(DataRow^ row)
{
    this->PaymentModeId = Convert::ToInt32(row["id"]);
    this->Name = Convert::ToString(row["name"]);
}

int Entities::PaymentModeEntity::GetPaymentModeId()
{
    return PaymentModeId;
}

String^ Entities::PaymentModeEntity::GetName()
{
    return Name;
}

void Entities::PaymentModeEntity::SetPaymentModeId(int paymentModeId)
{
    PaymentModeId = paymentModeId;
}

void Entities::PaymentModeEntity::SetName(String^ name)
{
    Name = name;
}
