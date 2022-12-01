#include "pch.h"
#include "PersonEntity.h"

Entities::PersonEntity::PersonEntity()
{
}

Entities::PersonEntity::PersonEntity(String^ firstname, String^ lastname) : Firstname(firstname), Lastname(lastname)
{
}

Entities::PersonEntity::PersonEntity(int personId, String^ firstname, String^ lastname)
    : PersonId(personId), Firstname(firstname), Lastname(lastname)
{
}

Entities::PersonEntity::PersonEntity(PersonEntity^ person) : PersonId(person->GetPersonId()),
                                                             Firstname(person->GetFirstname()),
                                                             Lastname(person->GetLastname())
{
}

Entities::PersonEntity::PersonEntity(DataRow^ row)
{
    this->PersonId = Convert::ToInt32(row["id"]);
    this->Firstname = row["Firstname"]->ToString();
    this->Lastname = row["Lastname"]->ToString();
}

int Entities::PersonEntity::GetPersonId()
{
    return PersonId;
}

void Entities::PersonEntity::SetPersonId(int personId)
{
    PersonId = personId;
}

String^ Entities::PersonEntity::GetFirstname()
{
    return Firstname;
}

void Entities::PersonEntity::SetFirstname(String^ firstname)
{
    Firstname = firstname;
}

String^ Entities::PersonEntity::GetLastname()
{
    return Lastname;
}

void Entities::PersonEntity::SetLastname(String^ lastname)
{
    Lastname = lastname;
}
