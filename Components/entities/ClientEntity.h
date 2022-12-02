#pragma once
#include "PersonEntity.h"

using namespace System;
using namespace Data;

namespace Entities
{
	public ref class ClientEntity : public Entities::PersonEntity
	{
	protected:
		int ClientId;
		DateTime BirthDate; 

	public:
		ClientEntity();
		ClientEntity(Entities :: PersonEntity^ person, DateTime birthDate);
		ClientEntity(int clientId, Entities:: PersonEntity^ person, DateTime birthDate);
		ClientEntity(DataRow^ row);
		int GetClientId();
		DateTime GetClientBirthDate();
		void SetClientId(int clientId);
		void SetBirthDate(DateTime birthDate);
	};
}


	




