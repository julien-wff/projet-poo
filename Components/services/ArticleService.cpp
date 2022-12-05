#include "pch.h"
#include "ArticleService.h"

DataTable^ Services::ArticleService::GetArticles()
{
    return dbProvider->ExecuteDataTable(
        "SELECT *, reference as article_reference FROM [management].[articles]");
}

Entities::ArticleEntity^ Services::ArticleService::GetArticle(int articleReference)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT *, reference as article_reference FROM [management].[articles] WHERE [reference] = @articleReference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@articleReference", articleReference));
    auto article = dbProvider->ExecuteDataRow(command);
    return gcnew Entities::ArticleEntity(article);
}

int Services::ArticleService::AddArticle(Entities::ArticleEntity^ article)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[articles] (name, stock, max_stock, vat, price) OUTPUT inserted.id VALUES (@name, @stock, @max_stock, @vat, @price)");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@name", article->GetName()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@stock", article->GetStock()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@max_stock", article->GetMaxStock()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@vat", article->GetVat()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@price", article->GetPrice()));
    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}

bool Services::ArticleService::UpdateArticle(Entities::ArticleEntity^ article)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[articles] SET name = @name,  stock = @stock, max_stock = @max_stock, vat = @vat, price = @price WHERE reference = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@name", article->GetName()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@stock", article->GetStock()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@max_stock", article->GetMaxStock()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@vat", article->GetVat()));
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@price", article->GetPrice()));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::ArticleService::DeleteArticle(int articleReference)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[articles] WHERE reference = @reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@reference", articleReference));
    return dbProvider->ExecuteNonQuery(command) == 1;
}

bool Services::ArticleService::DeleteArticle(Entities::ArticleEntity^ article)
{
    return DeleteArticle(article->GetArticleReference());
}

array<Entities::ArticleVariantEntity^>^ Services::ArticleService::GetArticleVariants(Entities::ArticleEntity^ article)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT * FROM [managements].[articles] LEFT JOIN [managements].[article_variants] ON article_variants.id = articles_reference WHERE articles_reference = @articles_reference");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@articles_reference", article->GetArticleReference()));
    auto articles = dbProvider->ExecuteDataTable(command);
    auto result = gcnew array<Entities::ArticleVariantEntity^>(articles->Rows->Count);
    for (int i = 0; i < articles->Rows->Count; i++)
        result[i] = gcnew Entities::ArticleVariantEntity(articles->Rows[i]);
    return result;
}
