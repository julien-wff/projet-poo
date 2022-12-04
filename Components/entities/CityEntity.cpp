#include "pch.h"
#include "CityEntity.h"

Entities::CityEntity::CityEntity()
{
}

Entities::CityEntity::CityEntity(int zipCode, String^ city) : ZipCode(zipCode), City(city)
{
}

Entities::CityEntity::CityEntity(int cityId, int zipCode, String^ city) : CityId(cityId), ZipCode(zipCode), City(city)
{
}

Entities::CityEntity::CityEntity(CityEntity^ city)
    : CityId(city->GetCityId()), ZipCode(city->GetZipCode()), City(city->GetCity())
{
}

Entities::CityEntity::CityEntity(DataRow^ row)
{
    this->CityId = Convert::ToInt32(row["city_id"]);
    this->ZipCode = Convert::ToInt32(row["zipcode"]);
    this->City = row["name"]->ToString();
}

int Entities::CityEntity::GetCityId()
{
    return CityId;
}

String^ Entities::CityEntity::GetCity()
{
    return City;
}

int Entities::CityEntity::GetZipCode()
{
    return ZipCode;
}

void Entities::CityEntity::SetCityId(int cityId)
{
    CityId = cityId;
}

void Entities::CityEntity::SetCity(String^ city)
{
    City = city;
}

void Entities::CityEntity::SetZipCode(int zipCode)
{
    ZipCode = zipCode;
}
