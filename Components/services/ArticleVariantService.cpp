#include "pch.h"
#include "ArticleVariantService.h"


void Services::ArticleVariantService::FillCommand(SqlClient::SqlCommand^ command,
                                                  Entities::ArticleVariantEntity^ articleVariant)
{
    command->Parameters->Add(
        gcnew SqlClient::SqlParameter("@articles_reference", articleVariant->GetArticleReference()));

    if (articleVariant->GetReductionValue() == 0)
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@reduction_value", DBNull::Value));
    else
        command->Parameters->
                 Add(gcnew SqlClient::SqlParameter("@reduction_value", articleVariant->GetReductionValue()));

    if (articleVariant->GetReductionProductCount() == 0)
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@reduction_product_count", DBNull::Value));
    else
        command->Parameters->Add(
            gcnew SqlClient::SqlParameter("@reduction_product_count", articleVariant->GetReductionProductCount()));

    if (articleVariant->GetColor() == nullptr)
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@color", DBNull::Value));
    else
        command->Parameters->Add(gcnew SqlClient::SqlParameter("@color", articleVariant->GetColor()));
}


DataTable^ Services::ArticleVariantService::GetArticleVariants()
{
    auto command = gcnew SqlClient::SqlCommand("SELECT * FROM [management].[article_variants]");
    return dbProvider->ExecuteDataTable(command);
}


Entities::ArticleVariantEntity^ Services::ArticleVariantService::GetArticleVariant(int id)
{
    auto command = gcnew SqlClient::SqlCommand("SELECT * FROM [management].[article_variants] WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return gcnew Entities::ArticleVariantEntity(dbProvider->ExecuteDataRow(command));
}


int Services::ArticleVariantService::AddArticleVariant(Entities::ArticleVariantEntity^ articleVariant)
{
    auto command = gcnew SqlClient::SqlCommand(
        "INSERT INTO [management].[article_variants] (articles_reference, reduction_value, reduction_product_count, color) \
        OUTPUT INSERTED.id \
        VALUES (@articles_reference, @reduction_value, @reduction_product_count, @color)");

    FillCommand(command, articleVariant);

    return safe_cast<int>(dbProvider->ExecuteScalar(command));
}


bool Services::ArticleVariantService::UpdateArticleVariant(Entities::ArticleVariantEntity^ articleVariant)
{
    auto command = gcnew SqlClient::SqlCommand(
        "UPDATE [management].[article_variants] \
        SET articles_reference = @articles_reference, reduction_value = @reduction_value, reduction_product_count = @reduction_product_count, color = @color \
        WHERE id = @id");

    FillCommand(command, articleVariant);
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", articleVariant->GetArticleVariantId()));

    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::ArticleVariantService::DeleteArticleVariant(int id)
{
    auto command = gcnew SqlClient::SqlCommand("DELETE FROM [management].[article_variants] WHERE id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", id));
    return dbProvider->ExecuteNonQuery(command) == 1;
}


bool Services::ArticleVariantService::DeleteArticleVariant(Entities::ArticleVariantEntity^ articleVariant)
{
    return DeleteArticleVariant(articleVariant->GetArticleVariantId());
}


Entities::ArticleEntity^ Services::ArticleVariantService::GetArticle(Entities::ArticleVariantEntity^ articleVariant)
{
    auto command = gcnew SqlClient::SqlCommand(
        "SELECT articles.* FROM [management].[article_variants] \
        INNER JOIN [management].[articles] ON [articles].reference = [article_variants].articles_reference \
        WHERE [article_variants].id = @id");
    command->Parameters->Add(gcnew SqlClient::SqlParameter("@id", articleVariant->GetArticleVariantId()));
    return gcnew Entities::ArticleEntity(dbProvider->ExecuteDataRow(command));
}
