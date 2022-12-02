#pragma once

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class AddressTypeEntity
    {
    protected:
        int AddressTypeId;
        String^ Name;
    public:
        AddressTypeEntity();
        AddressTypeEntity(String^ name);
        AddressTypeEntity(int addressTypeId, String^ name);
        AddressTypeEntity(DataRow^ row);
        int GetAddressTypeId();
        String^ GetName();
        void SetAddressTypeId(int addressTypeId);
        void SetName(String^ name);
    };
}
