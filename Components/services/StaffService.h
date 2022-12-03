#pragma once
#include "PersonService.h"
#include "../entities/StaffEntity.h"

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
        Entities::StaffEntity^ GetSupervisor(Entities::StaffEntity^ staff);
    };
}
