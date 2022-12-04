#include "pch.h"
#include "AddressEntity.h"

Entities::AddressEntity::AddressEntity()
{
}

Entities::AddressEntity::AddressEntity(CityEntity^ city, AddressTypeEntity^ addressType, PersonEntity^ person,
                                       String^ street)
    : CityEntity(city), AddressTypeId(addressType->GetAddressTypeId()), PersonId(person->GetPersonId()), Street(street)
{
}

Entities::AddressEntity::AddressEntity(int addressId, CityEntity^ city, AddressTypeEntity^ addressType,
                                       PersonEntity^ person, String^ street)
    : AddressId(addressId), CityEntity(city), AddressTypeId(addressType->GetAddressTypeId()),
      PersonId(person->GetPersonId()), Street(street)
{
}

Entities::AddressEntity::AddressEntity(DataRow^ row) : CityEntity(row)
{
    this->CityId = Convert::ToInt32(row["city_id"]);
    this->AddressId = Convert::ToInt32(row["id"]);
    this->AddressTypeId = Convert::ToInt32(row["address_type_id"]);
    this->Street = row["street"]->ToString();
    this->PersonId = Convert::ToInt32(row["person_id"]);
}

int Entities::AddressEntity::GetAddressId()
{
    return AddressId;
}

String^ Entities::AddressEntity::GetStreet()
{
    return Street;
}

int Entities::AddressEntity::GetAddressTypeId()
{
    return AddressTypeId;
}

int Entities::AddressEntity::GetPersonId()
{
    return PersonId;
}

void Entities::AddressEntity::SetAddressId(int addressId)
{
    AddressId = addressId;
}

void Entities::AddressEntity::SetStreet(String^ street)
{
    Street = street;
}

void Entities::AddressEntity::SetAddressTypeId(int addressTypeId)
{
    AddressTypeId = addressTypeId;
}

void Entities::AddressEntity::SetPersonId(int personId)
{
    PersonId = personId;
}
