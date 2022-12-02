#pragma once
#include "PersonEntity.h"

using namespace System;
using namespace Data;

namespace Entities
{
	public ref class StaffEntity : public Entities::PersonEntity 
	{
	protected:
		int StaffId;
		DateTime HireDate;
		int SupervisedBy;
	public:
		StaffEntity();
		StaffEntity(Entities::PersonEntity^ person, DateTime hireDate, int supervisedBy);
		StaffEntity(int staffId, Entities::PersonEntity^ person, DateTime hireDate, int supervisedBy);
		StaffEntity(DataRow^ row);
		int GetStaffId();
		DateTime GetHireDate();
		int GetSupervisedBy();
		void SetStaffId(int staffId);
		void SetHireDate(DateTime hireDate);
		void SetSupervisedBy(int supervisedBy);
	};
}
