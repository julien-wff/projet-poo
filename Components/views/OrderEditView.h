#pragma once
#include "../components/EditorHeader.h"
#include "../services/ClientService.h"
#include "../services/OrderService.h"
#include "../components/FormSeparator.h"
#include "../components/DateField.h"
#include "../components/SelectField.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class OrderEditView : public System::Windows::Forms::UserControl
    {
    public:
        OrderEditView(void)
        {
            InitializeComponent();
        }

    protected:
        ~OrderEditView()
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
        System::Windows::Forms::TableLayoutPanel^ FormLayoutPanel;
        System::Windows::Forms::Panel^ FormScrollPanel;
        Components::FormSeparator^ OrderFormSeparator;
        Components::SelectField^ ClientField;
        Components::DateField^ CreationDateField;
        Components::DateField^ DeliveryDateField;

        Services::OrderService^ orderService = gcnew Services::OrderService();
        Entities::OrderEntity^ order = gcnew Entities::OrderEntity();
        Services::ClientService^ clientService = gcnew Services::ClientService();
        array<Entities::ClientEntity^>^ availableClients;

        EditorMode currentEditorMode;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EditorHeader = (gcnew Components::EditorHeader());
            this->FormScrollPanel = (gcnew System::Windows::Forms::Panel());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->OrderFormSeparator = (gcnew Components::FormSeparator());
            this->ClientField = (gcnew Components::SelectField());
            this->CreationDateField = (gcnew Components::DateField());
            this->DeliveryDateField = (gcnew Components::DateField());
            this->TableLayoutPanel->SuspendLayout();
            this->FormScrollPanel->SuspendLayout();
            this->FormLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
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
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
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
                this, &OrderEditView::EditorHeader_DeleteClick);
            this->EditorHeader->CreateClick += gcnew System::EventHandler(
                this, &OrderEditView::EditorHeader_CreateClick);
            this->EditorHeader->CancelClick += gcnew System::EventHandler(
                this, &OrderEditView::EditorHeader_CancelClick);
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
            this->FormScrollPanel->TabIndex = 2;
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
            this->FormLayoutPanel->Controls->Add(this->OrderFormSeparator, 1, 0);
            this->FormLayoutPanel->Controls->Add(this->ClientField, 1, 1);
            this->FormLayoutPanel->Controls->Add(this->CreationDateField, 1, 2);
            this->FormLayoutPanel->Controls->Add(this->DeliveryDateField, 3, 2);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 20);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(20);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 4;
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->FormLayoutPanel->Size = System::Drawing::Size(760, 476);
            this->FormLayoutPanel->TabIndex = 1;
            // 
            // OrderFormSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->OrderFormSeparator, 3);
            this->OrderFormSeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->OrderFormSeparator->LabelText = L"Commande";
            this->OrderFormSeparator->Location = System::Drawing::Point(120, 0);
            this->OrderFormSeparator->Margin = System::Windows::Forms::Padding(0);
            this->OrderFormSeparator->Name = L"OrderFormSeparator";
            this->OrderFormSeparator->Size = System::Drawing::Size(520, 50);
            this->OrderFormSeparator->TabIndex = 0;
            // 
            // ClientField
            // 
            this->ClientField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ClientField->Items = gcnew cli::array<System::Tuple<System::Object^, System::String^>^>(0);
            this->ClientField->LabelText = L"Client";
            this->ClientField->Location = System::Drawing::Point(120, 50);
            this->ClientField->Margin = System::Windows::Forms::Padding(0);
            this->ClientField->Name = L"ClientField";
            this->ClientField->SelectedIndex = -1;
            this->ClientField->Size = System::Drawing::Size(250, 50);
            this->ClientField->TabIndex = 1;
            this->ClientField->SelectionChanged += gcnew System::EventHandler<Object^>(
                this, &OrderEditView::ClientField_SelectionChanged);
            // 
            // CreationDateField
            // 
            this->CreationDateField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CreationDateField->LabelText = L"Date de création";
            this->CreationDateField->Location = System::Drawing::Point(120, 105);
            this->CreationDateField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->CreationDateField->Name = L"CreationDateField";
            this->CreationDateField->Size = System::Drawing::Size(250, 50);
            this->CreationDateField->TabIndex = 2;
            this->CreationDateField->Value = System::DateTime::Now;
            this->CreationDateField->DateChanged += gcnew System::EventHandler(
                this, &OrderEditView::CreationDateField_ValueChanged);
            // 
            // DeliveryDateField
            // 
            this->DeliveryDateField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DeliveryDateField->LabelText = L"Date de livraison";
            this->DeliveryDateField->Location = System::Drawing::Point(390, 105);
            this->DeliveryDateField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->DeliveryDateField->Name = L"DeliveryDateField";
            this->DeliveryDateField->Size = System::Drawing::Size(250, 50);
            this->DeliveryDateField->TabIndex = 3;
            this->DeliveryDateField->Value = System::DateTime::Now;
            this->DeliveryDateField->DateChanged += gcnew System::EventHandler(
                this, &OrderEditView::DeliveryDateField_ValueChanged);
            // 
            // OrderEditView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"OrderEditView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->FormScrollPanel->ResumeLayout(false);
            this->FormLayoutPanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

    public:
        void LoadForm(EditorMode mode, String^ orderReference)
        {
            this->EditorHeader->CurrentEditorMode = mode;
            this->currentEditorMode = mode;
            auto clientTable = clientService->GetClients();
            availableClients = gcnew array<Entities::ClientEntity^>(clientTable->Rows->Count);
            auto clientsSelection = gcnew array<Tuple<Object^, String^>^>(availableClients->Length);
            for (int i = 0; i < clientTable->Rows->Count; i++)
            {
                availableClients[i] = gcnew Entities::ClientEntity(clientTable->Rows[i]);
                clientsSelection[i] = gcnew Tuple<Object^, String^>(
                    availableClients[i],
                    availableClients[i]->GetLastname() + " " + availableClients[i]->GetFirstname());
            }
            ClientField->Items = clientsSelection;

            if (mode == EditorMode::Edit)
            {
                order = orderService->GetOrder(orderReference);
                int selectedClientIndex = -1;
                for (int i = 0; i < availableClients->Length; i++)
                {
                    if (availableClients[i]->GetClientId() == order->GetClientId())
                    {
                        selectedClientIndex = i;
                        break;
                    }
                }
                this->ClientField->SelectedIndex = selectedClientIndex;
                this->CreationDateField->Value = order->GetCreationDate();
                this->DeliveryDateField->Value = order->GetDeliveryDate();
                this->EditorHeader->Label = L"Édition de la commande " + orderReference;
            }
            else
            {
                order = gcnew Entities::OrderEntity();
                this->ClientField->SelectedIndex = -1;
                this->CreationDateField->Value = System::DateTime::Now;
                this->DeliveryDateField->Value = System::DateTime::Now;
                this->EditorHeader->Label = L"Création d'une commande";
            }
        }

        void LoadForm(EditorMode mode)
        {
            LoadForm(mode, nullptr);
        }

        System::Void EditorHeader_CancelClick(System::Object^ sender, System::EventArgs^ e)
        {
            Back(this, e);
        }

        System::Void EditorHeader_CreateClick(System::Object^ sender, System::EventArgs^ e)
        {
            if (currentEditorMode == EditorMode::Create)
            {
                SetOrderReference();
                orderService->AddOrder(order);
            }
            else if (currentEditorMode == EditorMode::Edit)
            {
                orderService->UpdateOrder(order);
            }
            Back(this, e);
        }

        System::Void EditorHeader_DeleteClick(System::Object^ sender, System::EventArgs^ e)
        {
            // Confirm delete
            auto result = MessageBox::Show(
                "Êtes-vous sûr de vouloir supprimer cette commande ? Cette action est irréversible.",
                "Confirmation",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Warning,
                MessageBoxDefaultButton::Button2);

            if (result == DialogResult::No)
                return;

            auto success = orderService->DeleteOrder(order);
            if (!success)
            {
                String^ message;
                if (Providers::DbProvider::GetLastException()->Number == 547)
                    message =
                        "Impossible de supprimer cette employé car elle est liée à d'autres données. Veuillez d'abord supprimer ces données.";
                else
                    message = "Une erreur est survenue lors de la suppression de la commande :\n" +
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

        System::Void ClientField_SelectionChanged(System::Object^ sender, System::Object^ e)
        {
            auto client = safe_cast<Entities::ClientEntity^>(e);
            order->SetClientId(client->GetClientId());
        }

        System::Void CreationDateField_ValueChanged(System::Object^ sender, System::EventArgs^ e)
        {
            order->SetCreationDate(CreationDateField->Value);
        }

        System::Void DeliveryDateField_ValueChanged(System::Object^ sender, System::EventArgs^ e)
        {
            order->SetDeliveryDate(DeliveryDateField->Value);
        }

        void SetOrderReference()
        {
            auto client = safe_cast<Entities::ClientEntity^>(ClientField->SelectedItem);
            String^ reference = orderService->GenerateOrderReference(client);
            order->SetOrderReference(reference);
        }
    };
}
