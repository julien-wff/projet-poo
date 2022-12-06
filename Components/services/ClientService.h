#pragma once
#include "PersonService.h"
#include "../entities/AddressEntity.h"
#include "../entities/ClientEntity.h"

namespace Services
{
    public ref class ClientService : public PersonService
    {
    public:
        DataTable^ GetClients();
        Entities::ClientEntity^ GetClient(int id);
        int AddClient(Entities::ClientEntity^ client);
        bool UpdateClient(Entities::ClientEntity^ client);
        bool DeleteClient(int id);
        bool DeleteClient(Entities::ClientEntity^ client);
        Entities::AddressEntity^ GetBillingAddress(Entities::ClientEntity^ client);
        Entities::AddressEntity^ GetDeliveryAddress(Entities::ClientEntity^ client);
    };
}
