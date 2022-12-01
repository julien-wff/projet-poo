#include "pch.h"
#include "ClientEntity.h"

Entities::ClientEntity::ClientEntity()
{
}

Entities::ClientEntity::ClientEntity(Entities::PersonEntity^ person, DateTime birthDate)
    : Entities::PersonEntity(person), BirthDate(birthDate)
{
}

Entities::ClientEntity::ClientEntity(int clientId, Entities::PersonEntity^ person, DateTime birthDate) :
    ClientId(clientId), Entities::PersonEntity(person), BirthDate(birthDate)
{
}

Entities::ClientEntity::ClientEntity(DataRow^ row) : PersonEntity(row)
{
    this->ClientId = Convert::ToInt32(row["id"]);
    this->BirthDate = Convert::ToDateTime(row["birth_date"]);
}

int Entities::ClientEntity::GetClientId()
{
    return ClientId;
}

DateTime Entities::ClientEntity::GetClientBirthDate()
{
    return BirthDate;
}

void Entities::ClientEntity::SetClientId(int clientId)
{
    ClientId = clientId;
}

void Entities::ClientEntity::SetBirthDate(DateTime birthDate)
{
    BirthDate = birthDate;
}
