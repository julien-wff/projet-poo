#include "pch.h"
#include "PaymentEntity.h"

Entities::PaymentEntity::PaymentEntity()
{
}

Entities::PaymentEntity::PaymentEntity(int paymentModeid, String^ orderReference, float amount, DateTime paymentDate,
                                       DateTime expectedDate): PaymentModeId(paymentModeid),
                                                               OrderReference(orderReference), Amount(amount),
                                                               PaymentDate(paymentDate), ExpectedDate(expectedDate)
{
}

Entities::PaymentEntity::PaymentEntity(int paymentId, int paymentModeid, String^ orderReference, float amount,
DateTime paymentDate, DateTime expectedDate): PaymentId(paymentId), PaymentModeId(paymentModeid),
                        OrderReference(orderReference), Amount(amount),
                        PaymentDate(paymentDate), ExpectedDate(expectedDate)
{
}

Entities::PaymentEntity::PaymentEntity(DataRow^ row)
{
}

int Entities::PaymentEntity::GetpaymentId()
{
    return PaymentId;
}

int Entities::PaymentEntity::GetpaymentModel()
{
    return PaymentModeId;
}

DateTime Entities::PaymentEntity::GetpaymentDate()
{
    return PaymentDate;
}

DateTime Entities::PaymentEntity::GetexpectedDate()
{
    return ExpectedDate;
}

String^ Entities::PaymentEntity::GetorderReference()
{
    return OrderReference;
}

float Entities::PaymentEntity::Getamount()
{
    return Amount;
}

void Entities::PaymentEntity::SetPaymentId(int paymentId)
{
    PaymentId = paymentId;
}

void Entities::PaymentEntity::SetExpectedDate(DateTime expectedDate)
{
    ExpectedDate = expectedDate;
}

void Entities::PaymentEntity::SetPaymentDate(DateTime paymentDate)
{
    PaymentDate =paymentDate;
}

void Entities::PaymentEntity::SetAmount(float amount)
{
    Amount = amount;
}

void Entities::PaymentEntity::SetPaymentModeId(int paymentModeId)
{
    PaymentModeId = paymentModeId;
}

void Entities::PaymentEntity::SetOrderReference(String^ orderReference)
{
    OrderReference = orderReference;
}

