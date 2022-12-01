#pragma once
#include "../providers/DbProvider.h"

namespace Services
{
    public ref class AbstractService
    {
    protected:
        static Providers::DbProvider^ dbProvider;
    public:
        static void SetProvider(Providers::DbProvider^ provider);
    };
}
