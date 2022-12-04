#include "pch.h"
#include "StaffService.h"

DataTable^ Services::StaffService::GetStaffs()
{
    return dbProvider->ExecuteDataTable(
        "SELECT * FROM [management].[staffs] LEFT JOIN [management].[persons] ON persons.id = staffs.person_id");
}


Entities::StaffEntity^ Services::StaffService::GetStaff(int id)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[staffs] LEFT JOIN [management].[persons] ON persons.id = staffs.person_id WHERE staffs.id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    auto staff = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::StaffEntity(staff);
}


int Services::StaffService::AddStaff(Entities::StaffEntity^ staff)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[staffs] (person_id, hire_date, supervisor_id) OUTPUT inserted.id VALUES (@person_id, @hire_date, @supervisor_id)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@person_id", staff->GetPersonId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@hire_date", staff->GetHireDate()));
    if (staff->GetSupervisedBy() > 1)
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@supervisor_id", staff->GetSupervisedBy()));
    else
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@supervisor_id", DBNull::Value));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}


bool Services::StaffService::UpdateStaff(Entities::StaffEntity^ staff)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[staffs] SET person_id = @person_id, hire_date = @hire_date, supervisor_id = @supervisor_id WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", staff->GetStaffId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@person_id", staff->GetPersonId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@hire_date", staff->GetHireDate()));
    if (staff->GetSupervisedBy() > 0)
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@supervisor_id", staff->GetSupervisedBy()));
    else
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@supervisor_id", DBNull::Value));
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::StaffService::DeleteStaff(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[staffs] WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::StaffService::DeleteStaff(Entities::StaffEntity^ staff)
{
    return DeleteStaff(staff->GetStaffId());
}


Entities::StaffEntity^ Services::StaffService::GetSupervisor(Entities::StaffEntity^ staff)
{
    if (!staff->GetSupervisedBy())
        return nullptr;
    return GetStaff(staff->GetSupervisedBy());
}


array<Entities::StaffEntity^>^ Services::StaffService::GetPossibleSupervisors(Entities::StaffEntity^ staff)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[staffs] \
        LEFT JOIN [management].[persons] \
        ON persons.id = staffs.person_id \
        WHERE (staffs.supervisor_id != @id OR staffs.supervisor_id IS NULL) AND staffs.id != @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", staff->GetStaffId()));
    auto staffs = dbProvider->ExecuteDataTable(command);
    auto result = gcnew array<Entities::StaffEntity^>(staffs->Rows->Count);
    for (int i = 0; i < staffs->Rows->Count; i++)
        result[i] = gcnew Entities::StaffEntity(staffs->Rows[i]);
    return result;
}


Entities::AddressEntity^ Services::StaffService::GetAddress(Entities::StaffEntity^ staff)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT addresses.id AS id, person_id, city_id, address_type_id, street, cities.name AS name, zipcode  \
                FROM management.addresses \
                LEFT JOIN management.cities ON cities.id = addresses.city_id \
                LEFT JOIN management.address_types ON address_types.id = addresses.address_type_id \
                WHERE address_types.name = 'staff' AND person_id = @person_id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@person_id", staff->GetPersonId()));
    auto address = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::AddressEntity(address);
}
