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
    Components::LoadingVue^ LoadingVue;
    Components::EmployeesTableView^ EmployeesTableView;
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->MainLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->Sidebar = (gcnew Components::Sidebar());
        this->LoadingVue = (gcnew Components::LoadingVue());
        this->EmployeesTableView = (gcnew Components::EmployeesTableView());
        this->MainLayoutPanel->SuspendLayout();
        this->SuspendLayout();
        // 
        // MainLayoutPanel
        // 
        this->MainLayoutPanel->ColumnCount = 3;
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Absolute,
            200)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            50)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            50)));
        this->MainLayoutPanel->Controls->Add(this->Sidebar, 0, 0);
        this->MainLayoutPanel->Controls->Add(this->LoadingVue, 1, 0);
        this->MainLayoutPanel->Controls->Add(this->EmployeesTableView, 2, 0);
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
        // LoadingVue
        // 
        this->LoadingVue->Dock = System::Windows::Forms::DockStyle::Fill;
        this->LoadingVue->LoadingText = L"Chargement...";
        this->LoadingVue->Location = System::Drawing::Point(200, 0);
        this->LoadingVue->Margin = System::Windows::Forms::Padding(0);
        this->LoadingVue->Name = L"LoadingVue";
        this->LoadingVue->Size = System::Drawing::Size(392, 561);
        this->LoadingVue->TabIndex = 1;
        // 
        // EmployeesTableView
        // 
        this->EmployeesTableView->Dock = System::Windows::Forms::DockStyle::Fill;
        this->EmployeesTableView->Location = System::Drawing::Point(592, 0);
        this->EmployeesTableView->Margin = System::Windows::Forms::Padding(0);
        this->EmployeesTableView->Name = L"EmployeesTableView";
        this->EmployeesTableView->Size = System::Drawing::Size(392, 561);
        this->EmployeesTableView->TabIndex = 2;
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
};
