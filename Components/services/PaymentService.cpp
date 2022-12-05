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
