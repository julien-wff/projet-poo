#pragma once
#include "AbstractService.h"
#include "../entities/OrderEntity.h"
#include "../entities/PaymentEntity.h"
#include "../entities/PaymentModeEntity.h"

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
        array<Entities::OrderEntity^>^ GetOrders(Entities::PaymentEntity^ order);
        Entities::PaymentModeEntity^ GetPaymentMode(int paymentModeId);
    };
}
