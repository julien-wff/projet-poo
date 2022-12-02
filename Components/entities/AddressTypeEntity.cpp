#include "pch.h"
#include "AddressTypeEntity.h"

Entities::AddressTypeEntity::AddressTypeEntity()
{
}

Entities::AddressTypeEntity::AddressTypeEntity(String^ name) : Name(name)
{
}

Entities::AddressTypeEntity::AddressTypeEntity(int addressTypeId, String^ name) : AddressTypeId(addressTypeId), Name(name)
{
}

Entities::AddressTypeEntity::AddressTypeEntity(DataRow^ row)
{
    this->AddressTypeId = Convert::ToInt32(row["id"]);
    this->Name = Convert::ToString(row["name"]);
}

int Entities::AddressTypeEntity::GetAddressTypeId()
{
    return AddressTypeId;
}

String^ Entities::AddressTypeEntity::GetName()
{
    return  Name;
}

void Entities::AddressTypeEntity::SetAddressTypeId(int addressTypeId)
{
    AddressTypeId = addressTypeId;
}

void Entities::AddressTypeEntity::SetName(String^ name)
{
    Name = name;
}
