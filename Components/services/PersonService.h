#pragma once
#include "AbstractService.h"
#include "../enities/PersonEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class PersonService : public AbstractService
    {
    public:
        DataTable^ GetPersons();
        Entities::PersonEntity^ GetPerson(int id);
        bool AddPerson(Entities::PersonEntity^ person);
        bool UpdatePerson(Entities::PersonEntity^ person);
        bool DeletePerson(int id);
        bool DeletePerson(Entities::PersonEntity^ person);
    };
}
