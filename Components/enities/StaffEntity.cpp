#include "pch.h"
#include "StaffEntity.h"

Entities::StaffEntity::StaffEntity()
{
}

Entities::StaffEntity::StaffEntity(Entities::PersonEntity^ person, DateTime hireDate, int supervisedBy) : Entities::PersonEntity(person), HireDate(hireDate), SupervisedBy(supervisedBy)
{
}

Entities::StaffEntity::StaffEntity(int staffId, Entities::PersonEntity^ person, DateTime hireDate, int supervisedBy)
	: StaffId(staffId), Entities::PersonEntity(person), HireDate(hireDate), SupervisedBy(supervisedBy)
{
}

Entities::StaffEntity::StaffEntity(DataRow^ row)
{
	this->StaffId = Convert::ToInt32(row["id"]);
	this->HireDate = Convert::ToDateTime(row["hire_date"]);
	this->SupervisedBy = Convert::ToInt32(row["supervisor_id"]);
}

int Entities::StaffEntity::GetStaffId()
{
	return StaffId;
}

DateTime Entities::StaffEntity::GetHireDate()
{
	return HireDate;
}

int Entities::StaffEntity::GetSupervisedBy()
{
	return SupervisedBy;
}

void Entities::StaffEntity::SetStaffId(int staffId)
{
	StaffId = staffId;
}

void Entities::StaffEntity::SetHireDate(DateTime hireDate)
{
	HireDate = hireDate;
}

void Entities::StaffEntity::SetSupervisedBy(int supervisedBy)
{
	SupervisedBy = supervisedBy;
}
