#include "pch.h"
#include "StatisticService.h"


float Services::StatisticService::GetCommercialStockValue()
{
    auto command = gcnew SqlClient::SqlCommand("SELECT SUM(stock * buy_price) from [management].[articles];");
    return Convert::ToSingle((dbProvider->ExecuteScalar(command)));
}

array<Entities::ArticleEntity^>^ Services::StatisticService::GetWorstSellingArticles()
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT TOP 10 [reference], [name], SUM(stock) AS quantity FROM [management].[articles]\
        GROUP BY [name], [reference] ORDER BY quantity ASC");
    auto worstSellingsTable = dbProvider->ExecuteDataTable(command);
    auto worstSellings = gcnew array<Entities::ArticleEntity^>(worstSellingsTable->Rows->Count);
    for (int i = 0; i < worstSellingsTable->Rows->Count; i++)
        worstSellings[i] = gcnew Entities::ArticleEntity(worstSellingsTable->Rows[i]);
    return worstSellings;
}

array<Entities::ArticleEntity^>^ Services::StatisticService::GetBestSellingArticles()
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT TOP 10 [reference], [name], SUM(stock) AS quantity FROM [management].[articles]\
        GROUP BY [name], [reference] ORDER BY quantity DESC");
    auto bestSellingsTable = dbProvider->ExecuteDataTable(command);
    auto bestSellings = gcnew array<Entities::ArticleEntity^>(bestSellingsTable->Rows->Count);
    for (int i = 0; i < bestSellingsTable->Rows->Count; i++)
        bestSellings[i] = gcnew Entities::ArticleEntity(bestSellingsTable->Rows[i]);
    return bestSellings;
}

float Services::StatisticService::GetTotalSpentPerClient(Entities::ClientEntity^ client)
{
    auto command = gcnew SqlClient::SqlCommand("SELECT SUM(order_items.price * order_items.item_count)\
    as PRICE FROM [management].[order_items] JOIN  [management].[orders] ON [orders].[reference]\
    = [order_items].[order_reference] JOIN  [management].[clients]  ON  [clients].id = [orders].client_id\
    WHERE client_id = @id;");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", client->GetClientId()));
    return Convert::ToSingle((dbProvider->ExecuteScalar(command)));
}

float Services::StatisticService::GetTurnoverPerMonth(DateTime date)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT ROUND(SUM(item_count * (articles.price - articles.buy_price)),3) AS profit FROM [management].[articles]\
         INNER JOIN [management].[article_variants] ON [articles].[reference] = [article_variants].[articles_reference]\
         INNER JOIN [management].[order_items] ON [article_variants].[id] = [order_items].[article_variant_id]\
         INNER JOIN [management].[orders] ON [order_items].[order_reference] = [orders].[reference]\
         WHERE MONTH([management].[orders].[creation_date])=@month AND YEAR([management].[orders].[creation_date])=@year;");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@month", date.Month));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@year", date.Year));
    try
    {
        return Convert::ToSingle(dbProvider->ExecuteScalar(command));
    }
    catch (...)
    {
        return 0;
    }
}

float Services::StatisticService::GetAverageShoppingCartValue()
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT AVG((item_count * price)-reduction_value) AS Panier_Moyen\
        FROM [management].[order_items]\
        INNER JOIN [management].[orders]\
        ON [order_items].[order_reference] = [orders].[reference];");
    return Convert::ToSingle(dbProvider->ExecuteScalar(command));
}

array<Entities::ArticleEntity^>^ Services::StatisticService::GetProductToRestock(int threshold)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [management].[articles] WHERE [management].[articles].[stock] < @threshold;");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@threshold", threshold));
    auto restockTable = dbProvider->ExecuteDataTable(command);
    auto restocks = gcnew array<Entities::ArticleEntity^>(restockTable->Rows->Count);
    for (int i = 0; i < restockTable->Rows->Count; i++)
        restocks[i] = gcnew Entities::ArticleEntity(restockTable->Rows[i]);
    return restocks;
}
