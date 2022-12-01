#include "pch.h"
#include "AbstractService.h"

void Services::AbstractService::SetProvider(Providers::DbProvider^ provider)
{
    dbProvider = provider;
}
