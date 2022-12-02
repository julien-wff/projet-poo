#include "pch.h"
#include "AddressTypeEntity.h"

Entities::AddressTypeEntity::AddressTypeEntity()
{
}

Entities::AddressTypeEntity::AddressTypeEntity(String^ name): Name(name)
{
}

Entities::AddressTypeEntity::AddressTypeEntity(int addressId, String^ name): AddressId(addressId), Name(name)
{
}

Entities::AddressTypeEntity::AddressTypeEntity(DataRow^ row)
{
    this->AddressId = Convert::ToInt32(row["id"]);
    this->Name = Convert::ToString(row["name"]);
}

int Entities::AddressTypeEntity::GetAddressId()
{
    return AddressId;
}

String^ Entities::AddressTypeEntity::GetName()
{
    return  Name;
}

void Entities::AddressTypeEntity::SetAddressId(int addressId)
{
    AddressId = addressId;
}

void Entities::AddressTypeEntity::setName(String^ name)
{
    Name = name;
}
