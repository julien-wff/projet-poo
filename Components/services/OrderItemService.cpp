#include "pch.h"
#include "OrderItemService.h"

DataTable^ Services::OrderItemService::GetOrderItems()
{
    return dbProvider->ExecuteDataTable(
    "SELECT * FROM [management].[order_items]");
}

Entities::OrderItemEntity^ Services::OrderItemService::GetOrderItem(int articleVariantId, String^ orderReference)
{
    auto command = gcnew SqlClient::SqlCommand(
    "SELECT * FROM [management].[articles] WHERE [order_reference] = @orderReference and [article_variant_id] = @articleVariantId");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@orderReference", orderReference));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@articleVariantId", articleVariantId));
    auto orderItem = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::OrderItemEntity(orderItem);
}

int Services::OrderItemService::AddOrderItem(Entities::OrderItemEntity^ orderItem)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[order_items] (article_variant_id, order_reference, price, vat \
        , reduction_value, item_count) OUTPUT (@article_variant_id, @order_reference, @price, @vat \
        , @reduction_value, @item_count)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@article_variant_id", orderItem->GetArticleVariantId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@order_reference", orderItem->GetOrderReference()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@price", orderItem->GetPrice()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@vat", orderItem->GetVat()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reduction_value", orderItem->GetReductionValue()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@item_count", orderItem->GetItemCount()));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}

bool Services::OrderItemService::UpdateOrderItem(Entities::OrderItemEntity^ orderItem)
{
    auto command = gcnew SqlClient::SqlCommand(
    "UPDATE [management].[order_items] SET article_variant_id = @article_variant_id,\
    order_reference = @order_reference, price = @price, vat = @vat,\
    reduction_value = @reduction_value, item_count = @item_count");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@article_variant_id", orderItem->GetArticleVariantId()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@order_reference", orderItem->GetOrderReference()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@price", orderItem->GetPrice()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@vat", orderItem->GetVat()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reduction_value", orderItem->GetReductionValue()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@item_count", orderItem->GetItemCount()));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::OrderItemService::DeleteOrderItem(int articleVariantId, String^ orderReference)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[articles] WHERE reference = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@article_variant_id", articleVariantId));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@order_reference", orderReference));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::OrderItemService::DeleteOrderItem(Entities::OrderItemEntity^ orderItem)
{
    return DeleteOrderItem(orderItem->GetArticleVariantId(), orderItem->GetOrderReference());
}

Entities::OrderEntity^ Services::OrderItemService::GetOrder(String^ orderReference)
{
    auto command = gcnew SqlClient::SqlCommand(
"SELECT * FROM [management].[order_items] LEFT JOIN [management].[articles] \
        ON order_items.order_reference = orders.reference WHERE orders.reference = @orders.reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@orders.reference", orderReference));
    auto order = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::OrderEntity(order);
}

Entities::ArticleVariantEntity^ Services::OrderItemService::GetArticleVariant(int articleVariantId)
{
    auto command = gcnew SqlClient::SqlCommand(
"SELECT * FROM [management].[order_items] LEFT JOIN [management].[article_variants] \
        ON order_items.article_variant_id = article_variants.id WHERE article_variants.id = @article_variants.id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@article_variants.id", articleVariantId));
    auto articleVariant = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::ArticleVariantEntity(articleVariant);
}

Entities::ArticleEntity^ Services::OrderItemService::GetArticle(int articleReference)
{
    auto command = gcnew SqlClient::SqlCommand(
"SELECT * FROM [management].[order_items] LEFT JOIN [management].[article_variants] ON order_items.article_variant_id = article_variants.id \
        LEFT JOIN [management].[articles] ON order_items.article_variant_id = article_variants.id \
        WHERE article_variants.id = @articles.reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@articles.reference", articleReference));
    auto article = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::ArticleEntity(article);
}
