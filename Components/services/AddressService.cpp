#include "pch.h"
#include "AddressService.h"

DataTable^ Services::AddressService::GetAddress()
{
    return dbProvider->ExecuteDataTable(
        "SELECT addresses.id, person_id, city_id, address_type_id, street, at.name AS address_type_name, c.name AS city_name, zipcode \
        FROM [management].[addresses] \
        LEFT JOIN [management].[address_types] at ON at.id = addresses.address_type_id \
        LEFT JOIN [management].[cities] c ON c.id = addresses.city_id");
}


Entities::AddressEntity^ Services::AddressService::GetAddress(int id)
{
    auto command = gcnew SqlClient::SqlCommand("SELECT * FROM [management].[addresses] WHERE addresses.id = @id");
    command->Parameters->AddWithValue("@id", id);
    auto address = dbProvider->ExecuteDataRow(command);
    if (address == nullptr)
        return nullptr;
    return gcnew Entities::AddressEntity(address);
}


int Services::AddressService::AddAddress(Entities::AddressEntity^ address)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[addresses] (person_id, city_id, address_type_id, street) \
        OUTPUT inserted.id \
        VALUES (@person_id, @city_id, @address_type_id, @street)");
    command->Parameters->AddWithValue("@person_id", address->GetPersonId());
    command->Parameters->AddWithValue("@city_id", address->GetCityId());
    command->Parameters->AddWithValue("@address_type_id", address->GetAddressTypeId());
    command->Parameters->AddWithValue("@street", address->GetStreet());
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}


bool Services::AddressService::UpdateAddress(Entities::AddressEntity^ address)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[addresses] \
        SET person_id = @person_id, city_id = @city_id, address_type_id = @address_type_id, street = @street \
        WHERE addresses.id = @id");
    command->Parameters->AddWithValue("@id", address->GetAddressId());
    command->Parameters->AddWithValue("@person_id", address->GetPersonId());
    command->Parameters->AddWithValue("@city_id", address->GetCityId());
    command->Parameters->AddWithValue("@address_type_id", address->GetAddressTypeId());
    command->Parameters->AddWithValue("@street", address->GetStreet());
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::AddressService::DeleteAddress(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[addresses] WHERE addresses.id = @id");
    command->Parameters->AddWithValue("@id", id);
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::AddressService::DeleteAddress(Entities::AddressEntity^ address)
{
    return DeleteAddress(address->GetAddressId());
}


Entities::CityEntity^ Services::AddressService::GetCity(Entities::AddressEntity^ address)
{
    auto cityService = gcnew CityService();
    return cityService->GetCity(address->GetCityId());
}


Entities::PersonEntity^ Services::AddressService::GetPerson(Entities::AddressEntity^ address)
{
    auto personService = gcnew PersonService();
    return personService->GetPerson(address->GetPersonId());
}


Entities::AddressTypeEntity^ Services::AddressService::GetAddressType(Entities::AddressEntity^ address)
{
    auto addressTypeService = gcnew AddressTypeService();
    return addressTypeService->GetAddressType(address->GetAddressTypeId());
}
