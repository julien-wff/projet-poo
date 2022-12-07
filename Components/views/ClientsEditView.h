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
        Components::DateField^ BirthDateField;
        Components::FormSeparator^ AddressBillingSeparator;
        Components::AddressCityFields^ AddressCityBillingFields;
        Components::TextField^ StreetBillingField;
        Components::FormSeparator^ AddressDeliverySeparator;
        Components::AddressCityFields^ AddressCityDeliveryFields;
        Components::TextField^ StreetDeliveryField;
        System::Windows::Forms::Panel^ FormScrollPanel;

        Services::ClientService^ clientService = gcnew Services::ClientService();
        Entities::ClientEntity^ client;
        Services::AddressService^ addressService = gcnew Services::AddressService();
        Entities::AddressEntity^ addressbilling;
        Entities::AddressEntity^ addressdelivery;

        EditorMode currentEditorMode;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EditorHeader = (gcnew Components::EditorHeader());
            this->FormScrollPanel = (gcnew System::Windows::Forms::Panel());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->LastNameField = (gcnew Components::TextField());
            this->FirstNameField = (gcnew Components::TextField());
            this->IdentitySeparator = (gcnew Components::FormSeparator());
            this->BirthDateField = (gcnew Components::DateField());
            this->AddressDeliverySeparator = (gcnew Components::FormSeparator());
            this->AddressCityDeliveryFields = (gcnew Components::AddressCityFields());
            this->StreetDeliveryField = (gcnew Components::TextField());
            this->AddressBillingSeparator = (gcnew Components::FormSeparator());
            this->AddressCityBillingFields = (gcnew Components::AddressCityFields());
            this->StreetBillingField = (gcnew Components::TextField());
            this->TableLayoutPanel->SuspendLayout();
            this->FormScrollPanel->SuspendLayout();
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
            this->TableLayoutPanel->Controls->Add(this->FormScrollPanel, 0, 1);
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
            // FormScrollPanel
            // 
            this->FormScrollPanel->AutoScroll = true;
            this->FormScrollPanel->Controls->Add(this->FormLayoutPanel);
            this->FormScrollPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->FormScrollPanel->Location = System::Drawing::Point(0, 40);
            this->FormScrollPanel->Margin = System::Windows::Forms::Padding(0);
            this->FormScrollPanel->Name = L"FormScrollPanel";
            this->FormScrollPanel->Padding = System::Windows::Forms::Padding(20);
            this->FormScrollPanel->Size = System::Drawing::Size(800, 560);
            this->FormScrollPanel->TabIndex = 1;
            // 
            // FormLayoutPanel
            // 
            this->FormLayoutPanel->ColumnCount = 5;
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Absolute,
                250)));
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Absolute,
                20)));
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Absolute,
                250)));
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->FormLayoutPanel->Controls->Add(this->LastNameField, 1, 1);
            this->FormLayoutPanel->Controls->Add(this->FirstNameField, 3, 1);
            this->FormLayoutPanel->Controls->Add(this->IdentitySeparator, 1, 0);
            this->FormLayoutPanel->Controls->Add(this->BirthDateField, 1, 3);
            this->FormLayoutPanel->Controls->Add(this->AddressDeliverySeparator, 1, 4);
            this->FormLayoutPanel->Controls->Add(this->AddressCityDeliveryFields, 1, 5);
            this->FormLayoutPanel->Controls->Add(this->StreetDeliveryField, 1, 6);
            this->FormLayoutPanel->Controls->Add(this->AddressBillingSeparator, 1, 7);
            this->FormLayoutPanel->Controls->Add(this->AddressCityBillingFields, 1, 8);
            this->FormLayoutPanel->Controls->Add(this->StreetBillingField, 1, 9);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 60);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(20);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 9;
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->FormLayoutPanel->Size = System::Drawing::Size(760, 476);
            this->FormLayoutPanel->TabIndex = 1;
            this->FormLayoutPanel->AutoSize = true;
            // 
            // LastNameField
            // 
            this->LastNameField->LabelText = L"Nom";
            this->LastNameField->Location = System::Drawing::Point(120, 50);
            this->LastNameField->Margin = System::Windows::Forms::Padding(0);
            this->LastNameField->Name = L"LastNameField";
            this->LastNameField->Size = System::Drawing::Size(250, 50);
            this->LastNameField->TabIndex = 1;
            this->LastNameField->Value = L"";
            this->LastNameField->TextChanged += gcnew System::EventHandler(
                this, &ClientsEditView::LastNameField_TextChanged);
            // 
            // FirstNameField
            // 
            this->FirstNameField->LabelText = L"Prénom";
            this->FirstNameField->Location = System::Drawing::Point(390, 50);
            this->FirstNameField->Margin = System::Windows::Forms::Padding(0);
            this->FirstNameField->Name = L"FirstNameField";
            this->FirstNameField->Size = System::Drawing::Size(250, 50);
            this->FirstNameField->TabIndex = 1;
            this->FirstNameField->Value = L"";
            this->FirstNameField->TextChanged += gcnew System::EventHandler(
                this, &ClientsEditView::FirstNameField_TextChanged);
            //
            // IdentitySeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->IdentitySeparator, 3);
            this->IdentitySeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->IdentitySeparator->LabelText = L"Identité";
            this->IdentitySeparator->Location = System::Drawing::Point(120, 0);
            this->IdentitySeparator->Margin = System::Windows::Forms::Padding(0);
            this->IdentitySeparator->Name = L"IdentitySeparator";
            this->IdentitySeparator->Size = System::Drawing::Size(520, 50);
            this->IdentitySeparator->TabIndex = 2;
            // 
            // BirthDateField
            // 
            this->BirthDateField->Dock = System::Windows::Forms::DockStyle::Top;
            this->BirthDateField->LabelText = L"Date de naissance";
            this->BirthDateField->Location = System::Drawing::Point(120, 150);
            this->BirthDateField->Margin = System::Windows::Forms::Padding(0);
            this->BirthDateField->Name = L"BirthDateField";
            this->BirthDateField->Size = System::Drawing::Size(250, 50);
            this->BirthDateField->TabIndex = 3;
            this->BirthDateField->Value = System::DateTime::Now;
            this->BirthDateField->DateChanged += gcnew System::EventHandler(
                this, &ClientsEditView::HideDateField_DateChanged);
            // 
            // AddressDeliverySeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->AddressDeliverySeparator, 3);
            this->AddressDeliverySeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AddressDeliverySeparator->LabelText = L"Adresse de livraison";
            this->AddressDeliverySeparator->Location = System::Drawing::Point(120, 200);
            this->AddressDeliverySeparator->Margin = System::Windows::Forms::Padding(0);
            this->AddressDeliverySeparator->Name = L"AddressDeliverySeparator";
            this->AddressDeliverySeparator->Size = System::Drawing::Size(520, 50);
            this->AddressDeliverySeparator->TabIndex = 5;
            // 
            // AddressCityDeliveryFields
            // 
            this->FormLayoutPanel->SetColumnSpan(this->AddressCityDeliveryFields, 3);
            this->AddressCityDeliveryFields->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AddressCityDeliveryFields->Location = System::Drawing::Point(120, 250);
            this->AddressCityDeliveryFields->Margin = System::Windows::Forms::Padding(0);
            this->AddressCityDeliveryFields->Name = L"AddressCityDeliveryFields";
            this->AddressCityDeliveryFields->Size = System::Drawing::Size(520, 50);
            this->AddressCityDeliveryFields->TabIndex = 6;
            this->AddressCityDeliveryFields->CityChanged += gcnew System::EventHandler<Entities::CityEntity^>(
                this, &ClientsEditView::AddressCityDeliveryFields_CityChanged);
            // 
            // StreetDeliveryField
            // 
            this->FormLayoutPanel->SetColumnSpan(this->StreetDeliveryField, 3);
            this->StreetDeliveryField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StreetDeliveryField->LabelText = L"Adresse de livraison";
            this->StreetDeliveryField->Location = System::Drawing::Point(123, 303);
            this->StreetDeliveryField->Name = L"StreetDeliveryField";
            this->StreetDeliveryField->Size = System::Drawing::Size(514, 50);
            this->StreetDeliveryField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->StreetDeliveryField->TabIndex = 7;
            this->StreetDeliveryField->Value = L"";
            this->StreetDeliveryField->TextChanged += gcnew System::EventHandler(
                this, &ClientsEditView::StreetDeliveryField_TextChanged);
            // 
            // AddressBillingSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->AddressBillingSeparator, 3);
            this->AddressBillingSeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AddressBillingSeparator->LabelText = L"Adresse de facturation";
            this->AddressBillingSeparator->Location = System::Drawing::Point(120, 200);
            this->AddressBillingSeparator->Margin = System::Windows::Forms::Padding(0);
            this->AddressBillingSeparator->Name = L"AddressBillingSeparator";
            this->AddressBillingSeparator->Size = System::Drawing::Size(520, 50);
            this->AddressBillingSeparator->TabIndex = 8;
            // 
            // AddressCityFields
            // 
            this->FormLayoutPanel->SetColumnSpan(this->AddressCityBillingFields, 3);
            this->AddressCityBillingFields->Dock = System::Windows::Forms::DockStyle::Fill;
            this->AddressCityBillingFields->Location = System::Drawing::Point(120, 250);
            this->AddressCityBillingFields->Margin = System::Windows::Forms::Padding(0);
            this->AddressCityBillingFields->Name = L"AddressCityBillingFields";
            this->AddressCityBillingFields->Size = System::Drawing::Size(520, 50);
            this->AddressCityBillingFields->TabIndex = 9;
            this->AddressCityBillingFields->CityChanged += gcnew System::EventHandler<Entities::CityEntity^>(
                this, &ClientsEditView::AddressCityBillingFields_CityChanged);
            // 
            // StreetField
            // 
            this->FormLayoutPanel->SetColumnSpan(this->StreetBillingField, 3);
            this->StreetBillingField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StreetBillingField->LabelText = L"Adresse de facturation";
            this->StreetBillingField->Location = System::Drawing::Point(123, 303);
            this->StreetBillingField->Name = L"StreetBillingField";
            this->StreetBillingField->Size = System::Drawing::Size(514, 50);
            this->StreetBillingField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->StreetBillingField->TabIndex = 10;
            this->StreetBillingField->Value = L"";
            this->StreetBillingField->TextChanged += gcnew System::EventHandler(
                this, &ClientsEditView::StreetBillingField_TextChanged);
            // 
            // ClientsEditView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"ClientsEditView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->FormScrollPanel->ResumeLayout(false);
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

            this->LastNameField->Value = client->GetLastname();
            this->FirstNameField->Value = client->GetFirstname();
            if (mode == EditorMode::Edit)
                this->BirthDateField->Value = client->GetClientBirthDate();
            else
                this->BirthDateField->Value = System::DateTime::Now;
            
            if (mode == EditorMode::Edit)
            {
                //Billing
                addressbilling = clientService->GetBillingAddress(client);
                AddressCityBillingFields->ZipCode = addressbilling->GetZipCode();
                AddressCityBillingFields->SetSelectedCity(addressbilling);
                StreetBillingField->Value = addressbilling->GetStreet();
                //Delivery
                addressdelivery = clientService->GetDeliveryAddress(client);
                AddressCityDeliveryFields->ZipCode = addressdelivery->GetZipCode();
                AddressCityDeliveryFields->SetSelectedCity(addressdelivery);
                StreetDeliveryField->Value = addressdelivery->GetStreet();
            }
            else
            {
                //Billing
                addressbilling = gcnew Entities::AddressEntity();
                addressbilling->SetAddressTypeId(1);
                AddressCityBillingFields->ClearFields();
                StreetBillingField->Value = "";
                //delivery
                addressdelivery = gcnew Entities::AddressEntity();
                addressdelivery->SetAddressTypeId(2);
                AddressCityDeliveryFields->ClearFields();
                StreetDeliveryField->Value = "";
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
            if (client->GetLastname() == nullptr || client->GetLastname()->Trim() == ""
                || client->GetFirstname() == nullptr || client->GetFirstname()->Trim() == "")
            {
                MessageBox::Show("Veuillez entrer un nom et un prénom.",
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

            if (addressbilling->GetCityId() == 0 || addressbilling->GetStreet() == nullptr || addressbilling->GetStreet()->Trim() == "")
            {
                MessageBox::Show("Veuillez entrer une adresse de facturation valide.",
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

            if (addressdelivery->GetCityId() == 0 || addressdelivery->GetStreet() == nullptr || addressdelivery->GetStreet()->Trim() == "")
            {
                MessageBox::Show("Veuillez entrer une adresse de livraison valide.",
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

            if (currentEditorMode == EditorMode::Create)
            {
                auto personId = clientService->AddPerson(client);
                client->SetPersonId(personId);
                clientService->AddClient(client);
                addressbilling->SetPersonId(personId);
                addressService->AddAddress(addressbilling);
                addressdelivery->SetPersonId(personId);
                addressService->AddAddress(addressdelivery);
                
            }
            else if (currentEditorMode == EditorMode::Edit)
            {
                clientService->UpdatePerson(client);
                clientService->UpdateClient(client);
                addressService->UpdateAddress(addressbilling);
                addressService->UpdateAddress(addressdelivery);
            }
            Back(this, e);
        }

        System::Void EditorHeader_DeleteClick(System::Object^ sender, System::EventArgs^ e)
        {
            // Confirm delete
            auto result = MessageBox::Show(
                "Êtes-vous sûr de vouloir supprimer ce client ? Cette action est irréversible.",
                "Confirmation",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Warning,
                MessageBoxDefaultButton::Button2);

            if (result == DialogResult::No)
                return;

            bool success = addressService->DeleteAddress(addressbilling);
            if (success)
                success = addressService->DeleteAddress(addressdelivery);
            if (success)
                success = clientService->DeleteClient(client);
            if (success)
                success = clientService->DeletePerson(client);

            if (!success)
            {
                String^ message;
                if (Providers::DbProvider::GetLastException()->Number == 547)
                    message =
                        "Impossible de supprimer cet employé car il est lié à d'autres données. Veuillez d'abord supprimer ces données.";
                else
                    message = "Une erreur est survenue lors de la suppression du client :\n" +
                        Providers::DbProvider::GetLastException()->Message;
                MessageBox::Show(
                    message,
                    "Erreur",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Error);
                return;
            }

            Back(this, e);
        }
#pragma endregion

        System::Void LastNameField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            client->SetLastname(LastNameField->Value);
        }

        System::Void FirstNameField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            client->SetFirstname(FirstNameField->Value);
        }

        System::Void HideDateField_DateChanged(System::Object^ sender, System::EventArgs^ e)
        {
            client->SetBirthDate(BirthDateField->Value);
        }

        System::Void AddressCityDeliveryFields_CityChanged(System::Object^ sender, Entities::CityEntity^ city)
        {
            if (city == nullptr)
            {
                addressdelivery->SetCityId(0);
                return;
            }
            addressdelivery->SetZipCode(city->GetZipCode());
            addressdelivery->SetCity(city->GetCity());
            addressdelivery->SetCityId(city->GetCityId());
        }

        System::Void StreetDeliveryField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            addressdelivery->SetStreet(StreetDeliveryField->Value);
        }

        System::Void AddressCityBillingFields_CityChanged(System::Object^ sender, Entities::CityEntity^ city)
        {
            if (city == nullptr)
            {
                addressbilling->SetCityId(0);
                return;
            }
            addressbilling->SetZipCode(city->GetZipCode());
            addressbilling->SetCity(city->GetCity());
            addressbilling->SetCityId(city->GetCityId());
        }

        System::Void StreetBillingField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            addressbilling->SetStreet(StreetBillingField->Value);
        }
    };
}