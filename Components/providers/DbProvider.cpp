#include "pch.h"
#include "DbProvider.h"

void Providers::DbProvider::BeforeQuery()
{
    LastException = nullptr;
}


Providers::DbProvider::DbProvider(String^ _connectionString) : connectionString(_connectionString)
{
    connection = gcnew SqlClient::SqlConnection();
    connection->ConnectionString = connectionString;
}


Providers::DbProvider::~DbProvider()
{
    Disconnect();
    delete connection;
}


Exception^ Providers::DbProvider::Connect()
{
    try
    {
        connection->Open();
        return nullptr;
    }
    catch (SqlClient::SqlException^ e)
    {
        LastException = e;
        return e;
    }
}


bool Providers::DbProvider::Disconnect()
{
    try
    {
        connection->Close();
        return true;
    }
    catch (SqlClient::SqlException^ e)
    {
        LastException = e;
        return false;
    }
}


bool Providers::DbProvider::IsConnected()
{
    return connection->State == ConnectionState::Open;
}


SqlClient::SqlException^ Providers::DbProvider::GetLastException()
{
    return LastException;
}


DataTable^ Providers::DbProvider::ExecuteDataTable(SqlClient::SqlCommand^ command)
{
    BeforeQuery();
    command->Connection = connection;
    auto table = gcnew DataTable();
    try
    {
        SqlClient::SqlDataAdapter^ adapter = gcnew SqlClient::SqlDataAdapter(command);
        adapter->Fill(table);
        return table;
    }
    catch (SqlClient::SqlException^ e)
    {
        LastException = e;
        return nullptr;
    }
}


DataTable^ Providers::DbProvider::ExecuteDataTable(String^ query)
{
    SqlClient::SqlCommand^ command = gcnew SqlClient::SqlCommand(query);
    return ExecuteDataTable(command);
}


DataRow^ Providers::DbProvider::ExecuteDataRow(SqlClient::SqlCommand^ command)
{
    auto table = ExecuteDataTable(command);
    if (table == nullptr || table->Rows->Count <= 0)
        return nullptr;
    return table->Rows[0];
}


DataRow^ Providers::DbProvider::ExecuteDataRow(String^ query)
{
    SqlClient::SqlCommand^ command = gcnew SqlClient::SqlCommand(query);
    return ExecuteDataRow(command);
}


int Providers::DbProvider::ExecuteNonQuery(SqlClient::SqlCommand^ command)
{
    BeforeQuery();
    command->Connection = connection;
    try
    {
        return command->ExecuteNonQuery();
    }
    catch (SqlClient::SqlException^ e)
    {
        LastException = e;
        return -1;
    }
}


int Providers::DbProvider::ExecuteNonQuery(String^ query)
{
    SqlClient::SqlCommand^ command = gcnew SqlClient::SqlCommand(query);
    return ExecuteNonQuery(command);
}


Object^ Providers::DbProvider::ExecuteScalar(SqlClient::SqlCommand^ command)
{
    BeforeQuery();
    command->Connection = connection;
    try
    {
        return command->ExecuteScalar();
    }
    catch (SqlClient::SqlException^ e)
    {
        LastException = e;
        return nullptr;
    }
}


Object^ Providers::DbProvider::ExecuteScalar(String^ query)
{
    SqlClient::SqlCommand^ command = gcnew SqlClient::SqlCommand(query);
    return ExecuteScalar(command);
}
