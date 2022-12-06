#pragma once
#include "../Components/enums/views.h"

using namespace System;
using namespace ComponentModel;
using namespace Collections;
using namespace Windows::Forms;
using namespace Data;
using namespace Drawing;
using namespace System::Configuration;

/// <summary>
/// The principal form of the application. This code is run when the application starts.
/// </summary>
public ref class WindowForm : public System::Windows::Forms::Form
{
public:
    WindowForm()
    {
        InitializeComponent();
    }

protected:
    ~WindowForm()
    {
        if (components)
        {
            delete components;
        }
    }

private:
    Components::Sidebar^ Sidebar;
    System::Windows::Forms::TableLayoutPanel^ MainLayoutPanel;
    Components::LoadingView^ LoadingView;
    Components::EmployeesTableView^ EmployeesTableView;
    Components::EmployeesEditView^ EmployeesEditView;
    Components::ArticleTableView^ ArticleTableView;
    Components::ClientsTableView^ ClientsTableView;
    Components::ClientsEditView^ ClientsEditView;
    Components::ArticleEditView^ ArticleEditView;
    Components::OrderTableView^ OrderTableView;
    Components::OrderEditView^ OrderEditView;
    Components::StatisticsView^ StatisticsView;
    Components::LoginView^ LoginView;
    System::ComponentModel::Container^ components;

    Providers::DbProvider^ dbProvider;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->MainLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->Sidebar = (gcnew Components::Sidebar());
        this->LoadingView = (gcnew Components::LoadingView());
        this->EmployeesTableView = (gcnew Components::EmployeesTableView());
        this->EmployeesEditView = (gcnew Components::EmployeesEditView());
        this->ArticleTableView = (gcnew Components::ArticleTableView());
        this->ClientsTableView = (gcnew Components::ClientsTableView());
        this->ClientsEditView = (gcnew Components::ClientsEditView());
        this->ArticleEditView = (gcnew Components::ArticleEditView());
        this->OrderTableView = (gcnew Components::OrderTableView());
        this->OrderEditView = (gcnew Components::OrderEditView());
        this->StatisticsView = (gcnew Components::StatisticsView());
        this->LoginView = (gcnew Components::LoginView());
        this->MainLayoutPanel->SuspendLayout();
        this->SuspendLayout();
        // 
        // MainLayoutPanel
        // 
        this->MainLayoutPanel->ColumnCount = 12;
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Absolute,
            200)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090402F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090402F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090402F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090402F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090402F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090402F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.092209F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.093382F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.091001F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.090092F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            9.09091F)));
        this->MainLayoutPanel->Controls->Add(this->Sidebar, 0, 0);
        this->MainLayoutPanel->Controls->Add(this->LoadingView, 1, 0);
        this->MainLayoutPanel->Controls->Add(this->EmployeesTableView, 2, 0);
        this->MainLayoutPanel->Controls->Add(this->EmployeesEditView, 3, 0);
        this->MainLayoutPanel->Controls->Add(this->ArticleTableView, 6, 0);
        this->MainLayoutPanel->Controls->Add(this->ClientsTableView, 4, 0);
        this->MainLayoutPanel->Controls->Add(this->ClientsEditView, 5, 0);
        this->MainLayoutPanel->Controls->Add(this->ArticleEditView, 7, 0);
        this->MainLayoutPanel->Controls->Add(this->OrderTableView, 8, 0);
        this->MainLayoutPanel->Controls->Add(this->OrderEditView, 9, 0);
        this->MainLayoutPanel->Controls->Add(this->StatisticsView, 10, 0);
        this->MainLayoutPanel->Controls->Add(this->LoginView, 11, 0);
        this->MainLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
        this->MainLayoutPanel->Location = System::Drawing::Point(0, 0);
        this->MainLayoutPanel->Margin = System::Windows::Forms::Padding(0);
        this->MainLayoutPanel->Name = L"MainLayoutPanel";
        this->MainLayoutPanel->RowCount = 1;
        this->MainLayoutPanel->RowStyles->Add(
            (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
        this->MainLayoutPanel->Size = System::Drawing::Size(1044, 561);
        this->MainLayoutPanel->TabIndex = 1;
        // 
        // Sidebar
        // 
        this->Sidebar->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(4)),
            static_cast<System::Int32>(static_cast<System::Byte>(23)),
            static_cast<System::Int32>(static_cast<System::Byte>(55)));
        this->Sidebar->Dock = System::Windows::Forms::DockStyle::Fill;
        this->Sidebar->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(253)),
            static_cast<System::Int32>(static_cast<System::Byte>(254)),
            static_cast<System::Int32>(static_cast<System::Byte>(250)));
        this->Sidebar->Location = System::Drawing::Point(0, 0);
        this->Sidebar->Margin = System::Windows::Forms::Padding(0);
        this->Sidebar->Name = L"Sidebar";
        this->Sidebar->Size = System::Drawing::Size(200, 561);
        this->Sidebar->TabIndex = 0;
        this->Sidebar->HandleSidebarClick += gcnew System::EventHandler(this, &WindowForm::Sidebar_HandleSidebarClick);
        // 
        // LoadingView
        // 
        this->LoadingView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->LoadingView->LoadingText = L"Chargement...";
        this->LoadingView->Location = System::Drawing::Point(200, 0);
        this->LoadingView->Margin = System::Windows::Forms::Padding(0);
        this->LoadingView->Name = L"LoadingView";
        this->LoadingView->Size = System::Drawing::Size(76, 561);
        this->LoadingView->TabIndex = 1;
        // 
        // EmployeesTableView
        // 
        this->EmployeesTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->EmployeesTableView->Location = System::Drawing::Point(276, 0);
        this->EmployeesTableView->Margin = System::Windows::Forms::Padding(0);
        this->EmployeesTableView->Name = L"EmployeesTableView";
        this->EmployeesTableView->Size = System::Drawing::Size(76, 561);
        this->EmployeesTableView->TabIndex = 2;
        this->EmployeesTableView->CreateClick += gcnew System::EventHandler(
            this, &WindowForm::EmployeesTableView_CreateClick);
        this->EmployeesTableView->EmployeeClick += gcnew System::EventHandler<int>(
            this, &WindowForm::EmployeesTableView_EmployeeClick);
        // 
        // EmployeesEditView
        // 
        this->EmployeesEditView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->EmployeesEditView->Location = System::Drawing::Point(352, 0);
        this->EmployeesEditView->Margin = System::Windows::Forms::Padding(0);
        this->EmployeesEditView->Name = L"EmployeesEditView";
        this->EmployeesEditView->Size = System::Drawing::Size(76, 561);
        this->EmployeesEditView->TabIndex = 3;
        this->EmployeesEditView->Back += gcnew System::EventHandler(this, &WindowForm::EmployeesEditView_BackClick);
        // 
        // ArticleTableView
        // 
        this->ArticleTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ArticleTableView->Location = System::Drawing::Point(580, 0);
        this->ArticleTableView->Margin = System::Windows::Forms::Padding(0);
        this->ArticleTableView->Name = L"ArticleTableView";
        this->ArticleTableView->Size = System::Drawing::Size(76, 561);
        this->ArticleTableView->TabIndex = 4;
        this->ArticleTableView->CreateClick += gcnew System::EventHandler(
            this, &WindowForm::ArticleTableView_CreateClick);
        this->ArticleTableView->ArticleClick += gcnew System::EventHandler<int>(
            this, &WindowForm::ArticleTableView_ArticleClick);
        // 
        // ClientsTableView
        // 
        this->ClientsTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ClientsTableView->Location = System::Drawing::Point(428, 0);
        this->ClientsTableView->Margin = System::Windows::Forms::Padding(0);
        this->ClientsTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ClientsTableView->Name = L"ClientsTableView";
        this->ClientsTableView->Size = System::Drawing::Size(76, 561);
        this->ClientsTableView->TabIndex = 4;
        this->ClientsTableView->CreateClick += gcnew System::EventHandler(
            this, &WindowForm::ClientsTableView_CreateClick);
        this->ClientsTableView->ClientClick += gcnew System::EventHandler<int>(
            this, &WindowForm::ClientsTableView_ClientClick);
        // 
        // ClientsEditView
        // 
        this->ClientsEditView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ClientsEditView->Location = System::Drawing::Point(394, 0);
        this->ClientsEditView->Margin = System::Windows::Forms::Padding(0);
        this->ClientsEditView->Name = L"ClientsEditView";
        this->ClientsEditView->Size = System::Drawing::Size(97, 561);
        this->ClientsEditView->TabIndex = 5;
        this->ClientsEditView->Back += gcnew System::EventHandler(this, &WindowForm::ClientsEditView_BackClick);
        // 
        // ArticleEditView
        // 
        this->ArticleEditView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ArticleEditView->Location = System::Drawing::Point(656, 0);
        this->ArticleEditView->Margin = System::Windows::Forms::Padding(0);
        this->ArticleEditView->Name = L"ArticleEditView";
        this->ArticleEditView->Size = System::Drawing::Size(76, 561);
        this->ArticleEditView->TabIndex = 7;
        this->ArticleEditView->Back += gcnew System::EventHandler(this, &WindowForm::ArticleEditView_BackClick);
        // 
        // OrderTableView
        // 
        this->OrderTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->OrderTableView->Location = System::Drawing::Point(732, 0);
        this->OrderTableView->Margin = System::Windows::Forms::Padding(0);
        this->OrderTableView->Name = L"OrderTableView";
        this->OrderTableView->Size = System::Drawing::Size(76, 561);
        this->OrderTableView->TabIndex = 8;
        this->OrderTableView->CreateClick += gcnew System::EventHandler(this, &WindowForm::OrderTableView_CreateClick);
        this->OrderTableView->OrderClick += gcnew System::EventHandler<String^>(
            this, &WindowForm::OrderTableView_OrderClick);
        // 
        // OrderEditView
        // 
        this->OrderEditView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->OrderEditView->Location = System::Drawing::Point(808, 0);
        this->OrderEditView->Margin = System::Windows::Forms::Padding(0);
        this->OrderEditView->Name = L"OrderEditView";
        this->OrderEditView->Size = System::Drawing::Size(76, 561);
        this->OrderEditView->TabIndex = 9;
        this->OrderEditView->Back += gcnew System::EventHandler(this, &WindowForm::OrderEditView_BackClick);
        // 
        // StatisticsView
        // 
        this->StatisticsView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->StatisticsView->Location = System::Drawing::Point(884, 0);
        this->StatisticsView->Margin = System::Windows::Forms::Padding(0);
        this->StatisticsView->Name = L"StatisticsView";
        this->StatisticsView->Size = System::Drawing::Size(76, 561);
        this->StatisticsView->TabIndex = 10;
        // 
        // LoginView
        // 
        this->LoginView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->LoginView->Location = System::Drawing::Point(960, 0);
        this->LoginView->Margin = System::Windows::Forms::Padding(0);
        this->LoginView->Name = L"LoginView";
        this->LoginView->Size = System::Drawing::Size(84, 561);
        this->LoginView->TabIndex = 11;
        this->LoginView->Submit += gcnew System::EventHandler(this, &WindowForm::LoginView_Submit);
        // 
        // WindowForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(241)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(243)));
        this->ClientSize = System::Drawing::Size(1044, 561);
        this->Controls->Add(this->MainLayoutPanel);
        this->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular,
                                                  System::Drawing::GraphicsUnit::Point,
                                                  static_cast<System::Byte>(0)));
        this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(6)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(11)));
        this->Margin = System::Windows::Forms::Padding(4);
        this->MinimumSize = System::Drawing::Size(950, 500);
        this->Name = L"WindowForm";
        this->Text = L"Application de gestion";
        this->Load += gcnew System::EventHandler(this, &WindowForm::WindowForm_Load);
        this->Shown += gcnew System::EventHandler(this, &WindowForm::WindowForm_Shown);
        this->MainLayoutPanel->ResumeLayout(false);
        this->MainLayoutPanel->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    System::Void LoginView_Submit(System::Object^ sender, System::EventArgs^ e)
    {
        LoginView->Loading = true;
        Application::DoEvents();
        SqlClient::SqlConnectionStringBuilder^ builder = gcnew SqlClient::SqlConnectionStringBuilder();
        builder->DataSource = ConfigurationManager::AppSettings["data-source"];
        builder->InitialCatalog = ConfigurationManager::AppSettings["database"];
        builder->UserID = this->LoginView->Username;
        builder->Password = this->LoginView->Password;
        builder->ConnectTimeout = Int32::Parse(ConfigurationManager::AppSettings["connection-timeout"]);
        builder->IntegratedSecurity = false;
        dbProvider = gcnew Providers::DbProvider(builder->ConnectionString);
        auto exception = dbProvider->Connect();
        if (exception != nullptr)
        {
            MessageBox::Show(exception->Message,
                             "Erreur avec la base de données",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Error);
            this->LoginView->Password = "";
            this->LoginView->Loading = false;
            return;
        }
        Services::AbstractService::SetProvider(dbProvider);
        SetCurrentView(ApplicationViews::Loading);
        this->EmployeesTableView->LoadData();
        this->Sidebar->SetActiveBtn(SidebarActions::Employees);
        SetCurrentView(ApplicationViews::EmployeesTable);
    }

    System::Void Sidebar_HandleSidebarClick(System::Object^ sender, System::EventArgs^ e)
    {
        if (dbProvider == nullptr || !dbProvider->IsConnected())
            return;
        SidebarEventArgs^ args = safe_cast<SidebarEventArgs^>(e);
        switch (args->Action)
        {
        case SidebarActions::Employees:
            SetCurrentView(ApplicationViews::Loading);
            EmployeesTableView->LoadData();
            SetCurrentView(ApplicationViews::EmployeesTable);
            break;
        case SidebarActions::Clients:
            SetCurrentView(ApplicationViews::Loading);
            ClientsTableView->LoadData();
            SetCurrentView(ApplicationViews::ClientsTable);
            break;
        case SidebarActions::Articles:
            SetCurrentView(ApplicationViews::Loading);
            ArticleTableView->LoadData();
            SetCurrentView(ApplicationViews::ArticlesTable);
            break;
        case SidebarActions::Orders:
            SetCurrentView(ApplicationViews::Loading);
            OrderTableView->LoadData();
            SetCurrentView(ApplicationViews::OrdersTable);
            break;
        case SidebarActions::Statistics:
            SetCurrentView(ApplicationViews::Statistics);
            break;
        default:
            SetCurrentView(ApplicationViews::Loading);
            break;
        }
    }

    System::Void WindowForm_Shown(System::Object^ sender, System::EventArgs^ e)
    {
        Application::DoEvents();
        SetCurrentView(ApplicationViews::Login);
    }

    System::Void WindowForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        SetCurrentView(ApplicationViews::Loading);
    }

    void SetCurrentView(ApplicationViews view)
    {
        // Suspend layout to prevent flickering
        this->SuspendLayout();
        this->MainLayoutPanel->SuspendLayout();

        // For each column of the layout, set the width to 0 and hide the control
        for (int i = 1; i < this->MainLayoutPanel->ColumnCount; i++)
        {
            this->MainLayoutPanel->ColumnStyles[i]->Width = 0;
            this->MainLayoutPanel->GetControlFromPosition(i, 0)->Hide();
        }

        // Enable the corresponding column and trigger the loading of the panel
        switch (view)
        {
        case ApplicationViews::Loading:
            ShowColumn(1);
            break;
        case ApplicationViews::EmployeesTable:
            ShowColumn(2);
            break;
        case ApplicationViews::EmployeeEdit:
            ShowColumn(3);
            break;
        case ApplicationViews::ClientsTable:
            ShowColumn(4);
            break;
        case ApplicationViews::ClientsEdit:
            ShowColumn(5);
            break;
        case ApplicationViews::ArticlesTable:
            ShowColumn(6);
            break;
        case ApplicationViews::ArticlesEdit:
            ShowColumn(7);
            break;
        case ApplicationViews::OrdersTable:
            ShowColumn(8);
            break;
        case ApplicationViews::OrdersEdit:
            ShowColumn(9);
            break;
        case ApplicationViews::Statistics:
            ShowColumn(10);
            break;
        case ApplicationViews::Login:
            ShowColumn(11);
            break;
        }

        // Resume layout to apply changes
        this->MainLayoutPanel->ResumeLayout();
        this->ResumeLayout();
    }

    void ShowColumn(int index)
    {
        this->MainLayoutPanel->ColumnStyles[index]->Width = 100;
        this->MainLayoutPanel->GetControlFromPosition(index, 0)->Show();
    }

    System::Void EmployeesTableView_CreateClick(System::Object^ sender, System::EventArgs^ e)
    {
        EmployeesEditView->LoadForm(EditorMode::Create);
        SetCurrentView(ApplicationViews::EmployeeEdit);
    }

    System::Void EmployeesEditView_BackClick(System::Object^ sender, System::EventArgs^ e)
    {
        SetCurrentView(ApplicationViews::Loading);
        EmployeesTableView->LoadData();
        SetCurrentView(ApplicationViews::EmployeesTable);
    }

    System::Void EmployeesTableView_EmployeeClick(System::Object^ sender, int staffId)
    {
        SetCurrentView(ApplicationViews::Loading);
        EmployeesEditView->LoadForm(EditorMode::Edit, staffId);
        SetCurrentView(ApplicationViews::EmployeeEdit);
    }

    System::Void ClientsTableView_CreateClick(System::Object^ sender, System::EventArgs^ e)
    {
        SetCurrentView(ApplicationViews::Loading);
        ClientsEditView->LoadForm(EditorMode::Create);
        SetCurrentView(ApplicationViews::ClientsEdit);
    }

    System::Void ClientsTableView_ClientClick(System::Object^ sender, int clientId)
    {
        SetCurrentView(ApplicationViews::Loading);
        ClientsEditView->LoadForm(EditorMode::Edit, clientId);
        SetCurrentView(ApplicationViews::ClientsEdit);
    }

    System::Void ClientsEditView_BackClick(System::Object^ sender, System::EventArgs^ e)
    {
        SetCurrentView(ApplicationViews::Loading);
        ClientsTableView->LoadData();
        SetCurrentView(ApplicationViews::ClientsTable);
    }
    

    System::Void ArticleTableView_CreateClick(System::Object^ sender, System::EventArgs^ e)
    {
        this->ArticleEditView->LoadForm(EditorMode::Create);
        SetCurrentView(ApplicationViews::ArticlesEdit);
    }

    System::Void ArticleTableView_ArticleClick(System::Object^ sender, int articlesReference)
    {
        SetCurrentView(ApplicationViews::Loading);
        this->ArticleEditView->LoadForm(EditorMode::Edit, articlesReference);
        SetCurrentView(ApplicationViews::ArticlesEdit);
    }

    System::Void ArticleEditView_BackClick(System::Object^ sender, System::EventArgs^ e)
    {
        SetCurrentView(ApplicationViews::Loading);
        ArticleTableView->LoadData();
        SetCurrentView(ApplicationViews::ArticlesTable);
    }

    System::Void OrderTableView_CreateClick(System::Object^ sender, System::EventArgs^ e)
    {
        this->OrderEditView->LoadForm(EditorMode::Create);
        SetCurrentView(ApplicationViews::OrdersEdit);
    }

    System::Void OrderTableView_OrderClick(System::Object^ sender, String^ orderReference)
    {
        SetCurrentView(ApplicationViews::Loading);
        this->OrderEditView->LoadForm(EditorMode::Edit, orderReference);
        SetCurrentView(ApplicationViews::OrdersEdit);
    }

    System::Void OrderEditView_BackClick(System::Object^ sender, System::EventArgs^ e)
    {
        SetCurrentView(ApplicationViews::Loading);
        OrderTableView->LoadData();
        SetCurrentView(ApplicationViews::OrdersTable);
    }
};
