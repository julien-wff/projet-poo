#pragma once
#include "AbstractService.h"
#include "../entities/PaymentEntity.h"

#pragma once
using namespace System;
using namespace Data;

namespace Services
{
    public ref class PaymentService : public AbstractService
    {
    public:
        DataTable^ GetPayments();
        Entities::PaymentEntity^ GetPayment(int id);
        int AddPayment(Entities::PaymentEntity^ payment);
        bool UpdatePayment(Entities::PaymentEntity^ payment);
        bool DeletePayment(int id);
        bool DeletePayment(Entities::PaymentEntity^ payment);
    };
}
