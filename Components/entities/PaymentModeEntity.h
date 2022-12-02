#pragma once
#pragma once

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class PaymentModeEntity
    {
    protected:
        int PaymentModeId;
        String^ Name;
    public:
        PaymentModeEntity();
        PaymentModeEntity(String^ name);
        PaymentModeEntity(int paymentModeId, String^ name);
        PaymentModeEntity(DataRow^ row);
        int GetPaymentModeId();
        String^ GetName();
        void SetPaymentModeId(int paymentModeId);
        void SetName(String^ name);
    };
}
