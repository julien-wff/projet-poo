#pragma once
#include "AbstractService.h"
#include "../entities/ArticleEntity.h"
#include "../entities/ClientEntity.h"

#pragma once
using namespace System;
using namespace Data;

namespace Services
{
    public ref class StatisticService : public AbstractService
    {
    public:
        float GetCommercialStockValue();
        array<Entities::ArticleEntity^>^ GetWorstSellingArticles();
        array<Entities::ArticleEntity^>^ GetBestSellingArticles();
        float GetTotalSpentPerClient(Entities::ClientEntity^ client);
        float GetTurnoverPerMonth(DateTime date);
        float GetAverageShoppingCartValue();
        array<Entities::ArticleEntity^>^ GetProductToRestock(int threshold);
        array<Entities::ClientEntity^>^ GetBirthdayClients();
        array<Entities::ClientEntity^>^ GetFutureBirthdayClients();
    };
}
