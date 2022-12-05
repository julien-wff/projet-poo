#include "pch.h"
#include "PaymentService.h"

DataTable^ Services::PaymentService::GetPayments()
{
    return dbProvider->ExecuteDataTable(
        "Select * FROM [management].[payments] ");
}

Entities::PaymentEntity^ Services::PaymentService::GetPayment(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[payments] WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto payment = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::PaymentEntity(payment);
}

int Services::PaymentService::AddPayment(Entities::PaymentEntity^ payment)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[payment_mode_id] (order_reference), (expected_date), (payment_date), (amount) OUTPUT inserted.id VALUES (@expected_date,@payment_date, @amount ,@payment_id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@payment_id", payment->GetpaymentId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@order_reference", payment->GetorderReference()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@expected_date", payment->GetexpectedDate()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@payment_date", payment->GetpaymentDate()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@amount", payment->Getamount()));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}

bool Services::PaymentService::UpdatePayment(Entities::PaymentEntity^ payment)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[payments] SET Payment_mode_id = @payment_mode_id, @order_reference, @expected_date, @creation_date, @amount   =  WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@payment", payment->GetpaymentId()));
    command->Parameters->AddWithValue("@order_reference", payment->GetorderReference());
    command->Parameters->AddWithValue("@expected_date", payment->GetexpectedDate());
    command->Parameters->AddWithValue("@creation_date", payment->GetpaymentDate());
    command->Parameters->AddWithValue("@amount", payment->Getamount());
    return dbProvider->ExecuteNonQuery(command) == 1;;
}

bool Services::PaymentService::DeletePayment(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "DELETE FROM [management].[payments] WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::PaymentService::DeletePayment(Entities::PaymentEntity^ payment)
{
    return DeletePayment(payment->GetpaymentId());
}

array<Entities::OrderEntity^>^ Services::PaymentService::GetOrders(Entities::PaymentEntity^ order)
{
    auto command = gcnew SqlClient::SqlCommand(
"SELECT * FROM [managements].[payments] LEFT JOIN [managements].[orders] ON payments.order_reference = orders.reference WHERE payments.order_reference = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", order->GetorderReference()));
    auto orders = dbProvider->ExecuteDataTable(command);
    auto result = gcnew array<Entities::OrderEntity^>(orders->Rows->Count);
    for (int i = 0; i < orders->Rows->Count; i++)
        result[i] = gcnew Entities::OrderEntity(orders->Rows[i]);
    return result;
}

Entities::PaymentModeEntity^ Services::PaymentService::GetPaymentMode(int paymentModeId)
{
    auto command = gcnew SqlClient::SqlCommand(
"SELECT * FROM [management].[payments] LEFT JOIN [management].[payment_modes] \
        ON payments.id = payment_modes.id WHERE payment_modes.id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", paymentModeId));
    auto payment = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::PaymentModeEntity(payment);
}

