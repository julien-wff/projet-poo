#include "pch.h"
#include "PersonService.h"

DataTable^ Services::PersonService::GetPersons()
{
    return dbProvider->ExecuteDataTable(
        "SELECT *, id AS person_id FROM [management].[persons]");
}


Entities::PersonEntity^ Services::PersonService::GetPerson(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT *, id AS person_id FROM [management].[persons] WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto person = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::PersonEntity(person);
}


int Services::PersonService::AddPerson(Entities::PersonEntity^ person)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[persons] ([firstname], [lastname]) OUTPUT inserted.id VALUES (@firstname, @lastname)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@firstname", person->GetFirstname()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@lastname", person->GetLastname()));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}


bool Services::PersonService::UpdatePerson(Entities::PersonEntity^ person)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[persons] SET [firstname] = @firstname, [lastname] = @lastname WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@firstname", person->GetFirstname()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@lastname", person->GetLastname()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", person->GetPersonId()));
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::PersonService::DeletePerson(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "DELETE FROM [management].[persons] WHERE [id] = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::PersonService::DeletePerson(Entities::PersonEntity^ person)
{
    return DeletePerson(person->GetPersonId());
}
