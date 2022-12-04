#include "pch.h"
#include "CityService.h"

DataTable^ Services::CityService::GetCities()
{
    return dbProvider->ExecuteDataTable("SELECT * FROM [management].[cities]");
}


Entities::CityEntity^ Services::CityService::GetCity(int id)
{
    auto command = gcnew SqlClient::SqlCommand("SELECT id AS city_id, name, zipcode FROM [management].[cities] WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto cityRow = dbProvider->ExecuteDataRow(command);
    if (cityRow == nullptr)
        return nullptr;
    return gcnew Entities::CityEntity(cityRow);
}


int Services::CityService::AddCity(Entities::CityEntity^ city)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[cities] (name, zipcode) OUTPUT inserted.id VALUES (@name, @zipcode)");
    command->Parameters->AddWithValue("@name", city->GetCity());
    command->Parameters->AddWithValue("@zipcode", city->GetZipCode());
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}


bool Services::CityService::UpdateCity(Entities::CityEntity^ city)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[cities] SET name = @name, zipcode = @zipcode WHERE id = @id");
    command->Parameters->AddWithValue("@name", city->GetCity());
    command->Parameters->AddWithValue("@zipcode", city->GetZipCode());
    command->Parameters->AddWithValue("@id", city->GetCityId());
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::CityService::DeleteCity(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[cities] WHERE id = @id");
    command->Parameters->AddWithValue("@id", id);
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::CityService::DeleteCity(Entities::CityEntity^ city)
{
    return DeleteCity(city->GetCityId());
}
