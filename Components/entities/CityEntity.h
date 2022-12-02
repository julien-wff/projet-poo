#pragma once


using namespace System;
using namespace Data;

namespace Entities
{
    public ref class CityEntity
    {
    protected:
        int CityId;
        int ZipCode;
        String^ City;
    public:
        CityEntity();
        CityEntity(int zipCode, String^ city);
        CityEntity(int cityId, int zipCode, String^ city);
        CityEntity(CityEntity^ city);
        CityEntity(DataRow^ row);
        int GetCityId();
        String^ GetCity();
        int GetZipCode();
        void SetCityId(int cityId);
        void SetCity(String^ city);
        void SetZipCode(int zipCode);
    };
}
