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
    System::Windows::Forms::Label^ ClientsTableLabel;
    System::Windows::Forms::Label^ ClientEditLabel;
    Components::ArticleEditView^ ArticleEditView;
    Components::OrderTableView^ OrderTableView;
    System::ComponentModel::Container^ components;

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
        this->ClientEditLabel = (gcnew System::Windows::Forms::Label());
        this->ArticleEditView = (gcnew Components::ArticleEditView());
        this->OrderTableView = (gcnew Components::OrderTableView());
        this->MainLayoutPanel->SuspendLayout();
        this->SuspendLayout();
        // 
        // MainLayoutPanel
        // 
        this->MainLayoutPanel->ColumnCount = 9;
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Absolute,
            200)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.49918F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.49918F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.49918F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.49918F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.49918F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.49918F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.50167F)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            12.50328F)));
        this->MainLayoutPanel->Controls->Add(this->Sidebar, 0, 0);
        this->MainLayoutPanel->Controls->Add(this->LoadingView, 1, 0);
        this->MainLayoutPanel->Controls->Add(this->EmployeesTableView, 2, 0);
        this->MainLayoutPanel->Controls->Add(this->EmployeesEditView, 3, 0);
        this->MainLayoutPanel->Controls->Add(this->ArticleTableView, 6, 0);
        this->MainLayoutPanel->Controls->Add(this->ClientsTableView, 4, 0);
        this->MainLayoutPanel->Controls->Add(this->ClientEditLabel, 5, 0);
        this->MainLayoutPanel->Controls->Add(this->ArticleEditView, 7, 0);
        this->MainLayoutPanel->Controls->Add(this->OrderTableView, 8, 0);
        this->MainLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
        this->MainLayoutPanel->Location = System::Drawing::Point(0, 0);
        this->MainLayoutPanel->Margin = System::Windows::Forms::Padding(0);
        this->MainLayoutPanel->Name = L"MainLayoutPanel";
        this->MainLayoutPanel->RowCount = 1;
        this->MainLayoutPanel->RowStyles->Add(
            (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
        this->MainLayoutPanel->Size = System::Drawing::Size(984, 561);
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
        this->LoadingView->Size = System::Drawing::Size(97, 561);
        this->LoadingView->TabIndex = 1;
        // 
        // EmployeesTableView
        // 
        this->EmployeesTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->EmployeesTableView->Location = System::Drawing::Point(297, 0);
        this->EmployeesTableView->Margin = System::Windows::Forms::Padding(0);
        this->EmployeesTableView->Name = L"EmployeesTableView";
        this->EmployeesTableView->Size = System::Drawing::Size(97, 561);
        this->EmployeesTableView->TabIndex = 2;
        this->EmployeesTableView->CreateClick += gcnew System::EventHandler(
            this, &WindowForm::EmployeesTableView_CreateClick);
        this->EmployeesTableView->EmployeeClick += gcnew System::EventHandler<int>(
            this, &WindowForm::EmployeesTableView_EmployeeClick);
        // 
        // EmployeesEditView
        // 
        this->EmployeesEditView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->EmployeesEditView->Location = System::Drawing::Point(394, 0);
        this->EmployeesEditView->Margin = System::Windows::Forms::Padding(0);
        this->EmployeesEditView->Name = L"EmployeesEditView";
        this->EmployeesEditView->Size = System::Drawing::Size(97, 561);
        this->EmployeesEditView->TabIndex = 3;
        this->EmployeesEditView->Back += gcnew System::EventHandler(this, &WindowForm::EmployeesEditView_BackClick);
        // 
        // ArticleTableView
        // 
        this->ArticleTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ArticleTableView->Location = System::Drawing::Point(685, 0);
        this->ArticleTableView->Margin = System::Windows::Forms::Padding(0);
        this->ArticleTableView->Name = L"ArticleTableView";
        this->ArticleTableView->Size = System::Drawing::Size(97, 561);
        this->ArticleTableView->TabIndex = 4;
        this->ArticleTableView->CreateClick += gcnew System::EventHandler(
            this, &WindowForm::ArticleTableView_CreateClick);
        this->ArticleTableView->ArticleClick += gcnew System::EventHandler<int>(
            this, &WindowForm::ArticleTableView_ArticleClick);
        // 
        // ClientTableView
        //
        this->ClientsTableView->Location = System::Drawing::Point(311, 0);
        this->ClientsTableView->Margin = System::Windows::Forms::Padding(0);
        this->ClientsTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ClientsTableView->Name = L"ClientsTableView";
        this->ClientsTableView->Size = System::Drawing::Size(111, 561);
        this->ClientsTableView->TabIndex = 4;
        this->ClientsTableView->CreateClick += gcnew System::EventHandler(
            this, &WindowForm::ClientsTableView_CreateClick);
        this->EmployeesTableView->EmployeeClick += gcnew System::EventHandler<int>(
            this, &WindowForm::ClientsTableView_ClientClick);
        // 
        // ClientEditLabel
        // 
        this->ClientEditLabel->AutoSize = true;
        this->ClientEditLabel->Location = System::Drawing::Point(591, 0);
        this->ClientEditLabel->Name = L"ClientEditLabel";
        this->ClientEditLabel->Size = System::Drawing::Size(67, 16);
        this->ClientEditLabel->TabIndex = 6;
        this->ClientEditLabel->Text = L"Client Edit";
        // 
        // ArticleEditView
        // 
        this->ArticleEditView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->ArticleEditView->Location = System::Drawing::Point(782, 0);
        this->ArticleEditView->Margin = System::Windows::Forms::Padding(0);
        this->ArticleEditView->Name = L"ArticleEditView";
        this->ArticleEditView->Size = System::Drawing::Size(98, 561);
        this->ArticleEditView->TabIndex = 7;
        this->ArticleEditView->Back += gcnew System::EventHandler(this, &WindowForm::ArticleEditView_BackClick);
        // 
        // OrderTableView
        // 
        this->OrderTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->OrderTableView->Location = System::Drawing::Point(880, 0);
        this->OrderTableView->Margin = System::Windows::Forms::Padding(0);
        this->OrderTableView->Name = L"OrderTableView";
        this->OrderTableView->Size = System::Drawing::Size(104, 561);
        this->OrderTableView->TabIndex = 8;
        // 
        // WindowForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(241)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(243)));
        this->ClientSize = System::Drawing::Size(984, 561);
        this->Controls->Add(this->MainLayoutPanel);
        this->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular,
                                                  System::Drawing::GraphicsUnit::Point,
                                                  static_cast<System::Byte>(0)));
        this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(6)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(11)));
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"WindowForm";
        this->Text = L"Application de gestion";
        this->Load += gcnew System::EventHandler(this, &WindowForm::WindowForm_Load);
        this->Shown += gcnew System::EventHandler(this, &WindowForm::WindowForm_Shown);
        this->MainLayoutPanel->ResumeLayout(false);
        this->MainLayoutPanel->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    System::Void Sidebar_HandleSidebarClick(System::Object^ sender, System::EventArgs^ e)
    {
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
        default:
            SetCurrentView(ApplicationViews::Loading);
            break;
        }
    }

    System::Void WindowForm_Shown(System::Object^ sender, System::EventArgs^ e)
    {
        Application::DoEvents();
        String^ connectionString = ConfigurationManager::AppSettings["connectionString"];
        if (connectionString == nullptr)
        {
            MessageBox::Show("La connexion à la base de données n'a pas été configurée.",
                             "Erreur avec la base de données",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Error);
            this->Close();
            return;
        }
        auto dbProvider = gcnew Providers::DbProvider(connectionString);
        auto exception = dbProvider->Connect();
        if (exception != nullptr)
        {
            MessageBox::Show(exception->Message,
                             "Erreur avec la base de données",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Error);
            this->Close();
            return;
        }
        Services::AbstractService::SetProvider(dbProvider);
        this->EmployeesTableView->LoadData();
        SetCurrentView(ApplicationViews::EmployeesTable);
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
        SetCurrentView(ApplicationViews::ClientsEdit);
    }

    System::Void ClientsTableView_ClientClick(System::Object^ sender, int clientId)
    {
        SetCurrentView(ApplicationViews::ClientsEdit);
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
};
