#pragma once

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


    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->MainLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->Sidebar = (gcnew Components::Sidebar());
        this->LoadingVue = (gcnew Components::LoadingVue());
        this->MainLayoutPanel->SuspendLayout();
        this->SuspendLayout();
        // 
        // MainLayoutPanel
        // 
        this->MainLayoutPanel->ColumnCount = 2;
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Absolute,
            200)));
        this->MainLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
            System::Windows::Forms::SizeType::Percent,
            100)));
        this->MainLayoutPanel->Controls->Add(this->Sidebar, 0, 0);
        this->MainLayoutPanel->Controls->Add(this->LoadingVue, 1, 0);
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
        this->LoadingVue->Location = System::Drawing::Point(204, 4);
        this->LoadingVue->Margin = System::Windows::Forms::Padding(4);
        this->LoadingVue->Name = L"LoadingVue";
        this->LoadingVue->Size = System::Drawing::Size(776, 553);
        this->LoadingVue->TabIndex = 1;
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
        this->Shown += gcnew System::EventHandler(this, &WindowForm::WindowForm_Shown);
        this->MainLayoutPanel->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion

    System::Void Sidebar_HandleSidebarClick(System::Object^ sender, System::EventArgs^ e)
    {
        SidebarEventArgs^ args = safe_cast<SidebarEventArgs^>(e);
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
    }
};
