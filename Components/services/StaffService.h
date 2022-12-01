#pragma once
#include "PersonService.h"
#include "../enities/StaffEntity.h"

namespace Services
{
    public ref class StaffService : public PersonService
    {
    public:
        DataTable^ GetStaffs();
        Entities::StaffEntity^ GetStaff(int id);
        int AddStaff(Entities::StaffEntity^ staff);
        bool UpdateStaff(Entities::StaffEntity^ staff);
        bool DeleteStaff(int id);
        bool DeleteStaff(Entities::StaffEntity^ staff);
        Entities::StaffEntity^ GetSupervisior(Entities::StaffEntity^ staff);
    };
}