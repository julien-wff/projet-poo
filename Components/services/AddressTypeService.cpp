#include "pch.h"
#include "AddressTypeService.h"

DataTable^ Services::AddressTypeService::GetAddressTypes()
{
    return dbProvider->ExecuteDataTable("SELECT * FROM [management].[cities]");
}


Entities::AddressTypeEntity^ Services::AddressTypeService::GetAddressType(int id)
{
    auto command = gcnew SqlClient::SqlCommand("SELECT * FROM [management].[address_types] WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto cityRow = dbProvider->ExecuteDataRow(command);
    if (cityRow == nullptr)
        return nullptr;
    return gcnew Entities::AddressTypeEntity(cityRow);
}


int Services::AddressTypeService::AddAddressType(Entities::AddressTypeEntity^ addressType)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[address_types] (name) OUTPUT inserted.id VALUES (@name)");
    command->Parameters->AddWithValue("@name", addressType->GetName());
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}


bool Services::AddressTypeService::UpdateAddressType(Entities::AddressTypeEntity^ addressType)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[address_types] SET name = @name WHERE id = @id");
    command->Parameters->AddWithValue("@name", addressType->GetName());
    command->Parameters->AddWithValue("@id", addressType->GetAddressTypeId());
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::AddressTypeService::DeleteAddressType(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[address_types] WHERE id = @id");
    command->Parameters->AddWithValue("@id", id);
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::AddressTypeService::DeleteAddressType(Entities::AddressTypeEntity^ addressType)
{
    return DeleteAddressType(addressType->GetAddressTypeId());
}
