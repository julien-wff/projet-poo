#pragma once

using namespace System;
using namespace Data;

namespace Entities
{
    public ref class PersonEntity
    {
    protected:
        int PersonId;
        String^ Firstname;
        String^ Lastname;
    public:
        PersonEntity();
        PersonEntity(String^ firstname, String^ lastname);
        PersonEntity(int personId, String^ firstname, String^ lastname);
        PersonEntity(DataRow^ row);
        int GetPersonId();
        String^ GetFirstname();
        String^ GetLastname();
        void SetPersonId(int personId);
        void SetFirstname(String^ firstname);
        void SetLastname(String^ lastname);
    };    
}
