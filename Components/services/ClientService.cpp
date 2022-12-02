#include "pch.h"
#include "ClientService.h"

DataTable^ Services::ClientService::GetClients()
{
    return dbProvider->ExecuteDataTable(
        "SELECT * FROM [management].[clients] LEFT JOIN [management].[persons] ON persons.id = clients.person_id");
}

Entities::ClientEntity^ Services::ClientService::GetClient(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[clients] LEFT JOIN [management].[persons] ON persons.id = clients.person_id WHERE clients.id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto client = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::ClientEntity(client);
}

int Services::ClientService::AddClient(Entities::ClientEntity^ client)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[clients] (person_id, birth_date) OUTPUT inserted.id VALUES (@person_id, @birth_date)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@person_id", client->GetPersonId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@birth_date", client->GetClientBirthDate()));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}

bool Services::ClientService::UpdateClient(Entities::ClientEntity^ client)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[clients] SET person_id = @person_id, birth_date = @birth_date WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@person_id", client->GetPersonId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@birth_date", client->GetClientBirthDate()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", client->GetClientId()));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::ClientService::DeleteClient(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[clients] WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::ClientService::DeleteClient(Entities::ClientEntity^ client)
{
    return DeleteClient(client->GetClientId());
}
