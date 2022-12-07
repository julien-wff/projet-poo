#pragma once
#include "../components/EditorHeader.h"
#include "../components/TextField.h"
#include "../components/FormSeparator.h"
#include "../components/DateField.h"
#include "../components/AddressCityFields.h"
#include "../components/SelectField.h"
#include "../entities/ClientEntity.h"
#include "../services/AddressService.h"
#include "../services/ClientService.h"
#include "../services/StaffService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class ClientsEditView : public System::Windows::Forms::UserControl
    {
    public:
        ClientsEditView(void)
        {
            InitializeComponent();
        }

    protected:
        ~ClientsEditView()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        event EventHandler^ Back;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        Components::EditorHeader^ EditorHeader;
        System::ComponentModel::Container^ components;
        Components::TextField^ FirstNameField;
        Components::TextField^ LastNameField;
        System::Windows::Forms::TableLayoutPanel^ FormLayoutPanel;
        Components::FormSeparator^ IdentitySeparator;
        Components::FormSeparator^ StaffSeparator;
        Components::DateField^ BirthDateField;
        Components::SelectField^ SupervisorField;
        Components::FormSeparator^ AddressSeparator;
        Components::AddressCityFields^ AddressCityFields;
        Components::TextField^ StreetField;

        Services::ClientService^ clientService = gcnew Services::ClientService();
        Entities::ClientEntity^ client;
        Services::AddressService^ addressService = gcnew Services::AddressService();
        Entities::AddressEntity^ address;
        
        EditorMode currentEditorMode;
#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EditorHeader = (gcnew Components::EditorHeader());
            this->TableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Absolute,
                20)));
            this->TableLayoutPanel->Controls->Add(this->EditorHeader, 0, 0);
            //this->TableLayoutPanel->Controls->Add(this->FormLayoutPanel, 0, 1);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 2;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayoutPanel->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->TabIndex = 0;
            // 
            // EditorHeader
            // 
            this->EditorHeader->CurrentEditorMode = EditorMode::Create;
            this->EditorHeader->Dock = System::Windows::Forms::DockStyle::Fill;
            this->EditorHeader->Label = L"Table";
            this->EditorHeader->Location = System::Drawing::Point(0, 0);
            this->EditorHeader->Margin = System::Windows::Forms::Padding(0);
            this->EditorHeader->Name = L"EditorHeader";
            this->EditorHeader->Size = System::Drawing::Size(800, 40);
            this->EditorHeader->TabIndex = 0;
            this->EditorHeader->DeleteClick += gcnew System::EventHandler(
                this, &ClientsEditView::EditorHeader_DeleteClick);
            this->EditorHeader->CreateClick += gcnew System::EventHandler(
                this, &ClientsEditView::EditorHeader_CreateClick);
            this->EditorHeader->CancelClick += gcnew System::EventHandler(
                this, &ClientsEditView::EditorHeader_CancelClick);
            // 
            // ClientsEditView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"EmployeesEditView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion 

    public:
        void LoadForm(EditorMode mode, int clientId)
        {
            this->EditorHeader->CurrentEditorMode = mode;
            this->currentEditorMode = mode;

            if (clientId > 0 && mode == EditorMode::Edit)
            {
                client = clientService->GetClient(clientId);
                this->EditorHeader->Label = "Édition de " + client->GetFirstname() + " " + client->GetLastname();
            }
            else
            {
                client = gcnew Entities::ClientEntity();
                auto clients = clientService->GetClients();
                this->EditorHeader->Label = "Création d'un employé";
            }
        }

        void LoadForm(EditorMode mode)
        {
            LoadForm(mode, 0);
        }

        System::Void EditorHeader_CancelClick(System::Object^ sender, System::EventArgs^ e)
        {
            Back(this, e);
        }

        System::Void EditorHeader_CreateClick(System::Object^ sender, System::EventArgs^ e)
        {
            if (currentEditorMode == EditorMode::Create)
            {
                MessageBox::Show("La fonction n'est pas implémentée !",
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Information);
                return;
            }
            Back(this, e);
        }

        System::Void EditorHeader_DeleteClick(System::Object^ sender, System::EventArgs^ e)
        {
            // Confirm delete
            auto result = MessageBox::Show("La fonction n'est pas implémentée !",
                                           "Erreur",
                                           MessageBoxButtons::OK,
                                           MessageBoxIcon::Information);
            if (result == DialogResult::No)
                return;
            Back(this, e);
        }
    };
}
