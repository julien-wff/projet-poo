#pragma once
#include "AddressTypeEntity.h"
#include "CityEntity.h"
#include "PersonEntity.h"

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class AddressEntity : public Entities::CityEntity
    {
        protected :
        int AddressId;
        String^ Street;
        int PersonId;
        int AddressTypeId;
        
        public :
        AddressEntity();
        AddressEntity(CityEntity^ city, AddressTypeEntity^ addressType, PersonEntity^ person, String^ street);
        AddressEntity(int addressId, CityEntity^ city, AddressTypeEntity^ addressType, PersonEntity^ person, String^ street);
        AddressEntity(DataRow^ row);
        int GetAddressId();
        String^ GetStreet();
        int GetAddressTypeId();
        int GetPersonId ();
        void SetAddressId(int addressId);
        void SetStreet(String^ street);
        void SetAddressTypeId(int addressTypeId);
        void SetPersonId(int personId);
    };
        
        
        