#pragma once

using namespace System;
using namespace Data;

namespace Providers
{
    public ref class DbProvider
    {
    private:
        String^ connectionString;
        SqlClient::SqlConnection^ connection;
    public:
        /**
         * \brief The constructor that initializes the connection string. It does not open the connection,
         * you need to call the Connect method to do that.
         * \param connectionString The connection string to use.
         */
        DbProvider(String^ connectionString);
        ~DbProvider();
        /**
         * \brief Connects to the database.
         * \return Return the exception if there is one, otherwise return a null pointer.
         */
        Exception^ Connect();
        /**
         * \brief Disconnects from the database.
         * \return A boolean that indicates if the disconnection was successful.
         */
        bool Disconnect();
        /**
         * \brief checks if the connection is open.
         * \return A boolean that indicates if the connection is open.
         */
        bool IsConnected();
        /**
         * \brief Executes a query that returns a whole table.
         * \param command An instance of SqlCommand that contains the query. It does not need to be contain the connection.
         * \return DataTable that contains the result of the query.
         */
        DataTable^ ExecuteDataTable(SqlClient::SqlCommand^ command);
        /**
         * \brief Executes a query that returns a whole table.
         * \param query A string that contains the query.
         * \return DataTable that contains the result of the query.
         */
        DataTable^ ExecuteDataTable(String^ query);
        /**
         * \brief Executes a query that returns a single row.
         * \param command An instance of SqlCommand that contains the query. It does not need to be contain the connection.
         * \return DataRow that contains the result of the query.
         */
        DataRow^ ExecuteDataRow(SqlClient::SqlCommand^ command);
        /**
         * \brief Executes a query that returns a single row.
         * \param query A string that contains the query.
         * \return DataRow that contains the result of the query.
         */
        DataRow^ ExecuteDataRow(String^ query);
        /**
         * \brief Executes a query that returns a single value.
         * \param command An instance of SqlCommand that contains the query. It does not need to be contain the connection.
         * \return Object that contains the result of the query. You need to use `safe_cast` to convert it to the correct type.
         */
        Object^ ExecuteScalar(SqlClient::SqlCommand^ command);
        /**
         * \brief Executes a query that returns a single value.
         * \param query A string that contains the query.
         * \return Object that contains the result of the query. You need to use `safe_cast` to convert it to the correct type.
         */
        Object^ ExecuteScalar(String^ query);
        /**
         * \brief Executes a query that does not return a value.
         * \param command An instance of SqlCommand that contains the query. It does not need to be contain the connection.
         * \return The number of rows affected by the query. If the query fails, it returns -1.
         */
        int ExecuteNonQuery(SqlClient::SqlCommand^ command);
        /**
         * \brief Executes a query that does not return a value.
         * \param query A string that contains the query.
         * \return The number of rows affected by the query. If the query fails, it returns -1.
         */
        int ExecuteNonQuery(String^ query);
    };
}
