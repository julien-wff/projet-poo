#pragma once


using namespace System;
using namespace Data;

namespace Entities
{
    public ref class PaymentEntity
    {
    protected:
        int PaymentId;
        int PaymentModeId;
        String^ OrderReference;
        float Amount;
        DateTime PaymentDate;
        DateTime ExpectedDate;
    public:
        PaymentEntity();
        PaymentEntity(int paymentModeid, String^ orderReference, float amount, DateTime paymentDate,
                      DateTime expectedDate);
        PaymentEntity(int paymentId, int paymentModeid, String^ orderReference, float amount, DateTime paymentDate,
                      DateTime expectedDate);
        PaymentEntity(DataRow^ row);
        int GetpaymentId();
        int GetpaymentModel();
        DateTime GetpaymentDate();
        DateTime GetexpectedDate();
        String^ GetorderReference();
        float Getamount();
        void SetPaymentId(int paymentId);
        void SetExpectedDate(DateTime expectedDate);
        void SetPaymentDate(DateTime paymentDate);
        void SetAmount(float amount);
        void SetPaymentModeId(int paymentModeId);
        void SetOrderReference(String^ orderReference);
    };
}
