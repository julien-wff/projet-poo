#pragma once

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class AddressTypeEntity
    {
    protected:
        int AddressId;
        String^ Name;
    public:
        AddressTypeEntity();
        AddressTypeEntity(String^ name);
        AddressTypeEntity(int addressId, String^ name);
        AddressTypeEntity(DataRow^ row);
        int GetAddressId();
        String^ GetName();
        void SetAddressId(int addressId);
        void setName(String^ name);
    };
}