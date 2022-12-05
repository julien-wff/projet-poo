#pragma once
#include "AbstractService.h"
#include "../entities/PaymentModeEntity.h"
#include "../entities/PaymentEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class PaymentModeService : public AbstractService
    {
    public:
        DataTable^ GetPaymentModes();
        Entities::PaymentModeEntity^ GetPaymentmode(int id);
        bool AddPaymentMode (Entities::PaymentModeEntity^ paymentMode);
        bool UpdatePaymentMode(Entities::PaymentModeEntity^ paymentMode);
        bool DeletePaymentMode(int id);
        bool DeletePaymentMode(Entities::PaymentModeEntity^ paymentMode);
        array<Entities::PaymentEntity^>^ GetPayments(Entities::PaymentModeEntity^ payment);
    };
}