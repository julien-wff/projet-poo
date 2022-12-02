#pragma once
#include "../entities/AddressEntity.h"
#include "CityService.h"
#include "PersonService.h"
#include "AddressTypeService.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class AddressService : public CityService
    {
    public:
        DataTable^ GetAddress();
        Entities::AddressEntity^ GetAddress(int id);
        int AddAddress(Entities::AddressEntity^ address);
        bool UpdateAddress(Entities::AddressEntity^ address);
        bool DeleteAddress(int id);
        bool DeleteAddress(Entities::AddressEntity^ address);
        Entities::CityEntity^ GetCity(Entities::AddressEntity^ address);
        Entities::PersonEntity^ GetPerson(Entities::AddressEntity^ address);
        Entities::AddressTypeEntity^ GetAddressType(Entities::AddressEntity^ address);
    };
}
