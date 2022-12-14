#include "pch.h"
#include "OrderService.h"
#include "ClientService.h"

DataTable^ Services::OrderService::GetOrders()
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT orders.reference,\
       persons.firstname,\
       persons.lastname,\
       orders.creation_date,\
       ROUND((SELECT SUM(price) FROM [management].[order_items] WHERE order_reference = orders.reference), 2) AS order_price,\
       (SELECT SUM(item_count) FROM [management].[order_items] WHERE order_reference = orders.reference) AS item_count\
        FROM [management].[orders]\
         LEFT JOIN [management].[clients] ON clients.id = orders.client_id\
         LEFT JOIN [management].[persons] ON persons.id = clients.person_id");
    return dbProvider->ExecuteDataTable(command);
}

Entities::OrderEntity^ Services::OrderService::GetOrder(String^ orderReference)
{
    auto command = gcnew SqlClient::SqlCommand("SELECT * FROM [management].[orders] WHERE [reference] = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", orderReference));
    auto row = dbProvider->ExecuteDataRow(command);
    if (row == nullptr)
        return nullptr;
    return gcnew Entities::OrderEntity(row);
}

String^ Services::OrderService::AddOrder(Entities::OrderEntity^ order)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[orders] (reference, client_id, delivery_date, creation_date) \
        OUTPUT INSERTED.[reference] \
        VALUES (@reference, @client_id, @delivery_date, @creation_date)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", order->GetOrderReference()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@client_id", order->GetClientId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@delivery_date", order->GetDeliveryDate()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@creation_date", order->GetCreationDate()));
    return Convert::ToString(dbProvider->ExecuteScalar(command));
}

bool Services::OrderService::UpdateOrder(Entities::OrderEntity^ order)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[orders] \
        SET [client_id] = @client_id, [delivery_date] = @delivery_date, [creation_date] = @creation_date \
        WHERE [reference] = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", order->GetOrderReference()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@client_id", order->GetClientId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@delivery_date", order->GetDeliveryDate()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@creation_date", order->GetCreationDate()));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::OrderService::DeleteOrder(String^ orderReference)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[orders] WHERE [reference] = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", orderReference));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::OrderService::DeleteOrder(Entities::OrderEntity^ order)
{
    return DeleteOrder(order->GetOrderReference());
}

array<Entities::OrderItemEntity^>^ Services::OrderService::GetOrderItems(Entities::OrderEntity^ order)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[order_items] WHERE [order_id] = @order_reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@order_reference", order->GetOrderReference()));
    auto itemsTable = dbProvider->ExecuteDataTable(command);
    auto orderItems = gcnew array<Entities::OrderItemEntity^>(itemsTable->Rows->Count);
    for (int i = 0; i < itemsTable->Rows->Count; i++)
        orderItems[i] = gcnew Entities::OrderItemEntity(itemsTable->Rows[i]);
    return orderItems;
}

array<Entities::PaymentEntity^>^ Services::OrderService::GetPayments(Entities::OrderEntity^ order)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[payments] WHERE [order_reference] = @order_reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@order_reference", order->GetOrderReference()));
    auto paymentTable = dbProvider->ExecuteDataTable(command);
    auto payments = gcnew array<Entities::PaymentEntity^>(paymentTable->Rows->Count);
    for (int i = 0; i < paymentTable->Rows->Count; i++)
        payments[i] = gcnew Entities::PaymentEntity(paymentTable->Rows[i]);
    return payments;
}

Entities::ClientEntity^ Services::OrderService::GetClient(Entities::OrderEntity^ order)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT clients.*, persons.* \
        FROM [management].[orders] \
        LEFT JOIN [management].[clients] ON clients.id = orders.client_id \
        LEFT JOIN [management].[persons] ON persons.id = clients.person_id \
        WHERE orders.id = @id");
    auto person = dbProvider->ExecuteDataRow(command);
    if (person == nullptr)
        return nullptr;
    return gcnew Entities::ClientEntity(person);
}

String^ Services::OrderService::GenerateOrderReference(Entities::ClientEntity^ client)
{
    auto clientService = gcnew ClientService();
    auto clientDeliveryAddress = clientService->GetDeliveryAddress(client);
    String^ reference =
        client->GetLastname()->Substring(0, 2)->ToUpper() +
        client->GetFirstname()->Substring(0, 2)->ToUpper() +
        System::DateTime::Now.Year.ToString() +
        clientDeliveryAddress->GetCity()->Substring(0, 3)->ToUpper();
    // Count orders that match the beginning of reference
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT COUNT(orders.reference) AS orders FROM [management].[orders] WHERE [reference] LIKE @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", reference + "%"));
    auto count = safe_cast<int>(dbProvider->ExecuteScalar(command));
    return reference + (count + 1).ToString("D3");
}
