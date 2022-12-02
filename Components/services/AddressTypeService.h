#pragma once
#include "AbstractService.h"
#include "../entities/AddressTypeEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class AddressTypeService : public AbstractService
    {
    public:
        DataTable^ GetAddressTypes();
        Entities::AddressTypeEntity^ GetAddressType(int id);
        int AddAddressType(Entities::AddressTypeEntity^ addressType);
        bool UpdateAddressType(Entities::AddressTypeEntity^ addressType);
        bool DeleteAddressType(int id);
        bool DeleteAddressType(Entities::AddressTypeEntity^ addressType);
    };
}
