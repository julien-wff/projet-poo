#pragma once
#include "AbstractService.h"
#include "../entities/CityEntity.h"

using namespace System;
using namespace Data;

namespace Services
{
    public ref class CityService : public AbstractService
    {
    public:
        DataTable^ GetCities();
        Entities::CityEntity^ GetCity(int id);
        int AddCity(Entities::CityEntity^ city);
        bool UpdateCity(Entities::CityEntity^ city);
        bool DeleteCity(int id);
        bool DeleteCity(Entities::CityEntity^ city);
        array<Entities::CityEntity^>^ GetCitiesByZipCode(int zipCode);
    };
}
