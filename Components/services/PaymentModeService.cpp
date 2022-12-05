#include "pch.h"
#include "PaymentModeService.h"

DataTable^ Services::PaymentModeService::GetPaymentModes()
{
    return dbProvider->ExecuteDataTable(
"SELECT * FROM [management].[payment_modes]");
}

Entities::PaymentModeEntity^ Services::PaymentModeService::GetPaymentmode(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[payment_modes] WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto paymentMode  = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::PaymentModeEntity(paymentMode);
}

bool Services::PaymentModeService::AddPaymentMode(Entities::PaymentModeEntity^ paymentMode)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[payment_modes] (name) OUTPUT inserted.id VALUES (@name)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@name", paymentMode->GetName()));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}

bool Services::PaymentModeService::UpdatePaymentMode(Entities::PaymentModeEntity^ paymentMode)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[articles] SET name = @name WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@name", paymentMode->GetName()));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::PaymentModeService::DeletePaymentMode(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[payment_modes] WHERE id =@id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::PaymentModeService::DeletePaymentMode(Entities::PaymentModeEntity^ paymentMode)
{
    return DeletePaymentMode(paymentMode->GetPaymentModeId());
}

array<Entities::PaymentEntity^>^ Services::PaymentModeService::GetPayments(Entities::PaymentModeEntity^ payment)
{
    auto command = gcnew SqlClient::SqlCommand(
    "SELECT * FROM [managements].[payment_modes] LEFT JOIN [managements].[payments] ON payment_modes.id = payments.payments_mode_id WHERE payment_modes.id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", payment->GetPaymentModeId()));
    auto payments = dbProvider->ExecuteDataTable(command);
    auto result = gcnew array<Entities::PaymentEntity^>(payments->Rows->Count);
    for (int i = 0; i < payments->Rows->Count; i++)
        result[i] = gcnew Entities::PaymentEntity(payments->Rows[i]);
    return result;
}
