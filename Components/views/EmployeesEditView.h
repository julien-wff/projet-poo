#pragma once
#include "../components/EditorHeader.h"
#include "../components/TextField.h"
#include "../components/FormSeparator.h"
#include "../components/DateField.h"
#include "../services/StaffService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class EmployeesEditView : public System::Windows::Forms::UserControl
    {
    public:
        EmployeesEditView(void)
        {
            InitializeComponent();
        }

    protected:
        ~EmployeesEditView()
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

        Services::StaffService^ staffService = gcnew Services::StaffService();
        Entities::StaffEntity^ staff;
    private:
        Components::DateField^ HireDateField;

        EditorMode currentEditorMode;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EditorHeader = (gcnew Components::EditorHeader());
            this->LastNameField = (gcnew Components::TextField());
            this->FirstNameField = (gcnew Components::TextField());
            this->IdentitySeparator = (gcnew Components::FormSeparator());
            this->StaffSeparator = (gcnew Components::FormSeparator());
            this->HireDateField = (gcnew Components::DateField());
            this->TableLayoutPanel->SuspendLayout();
            this->FormLayoutPanel->SuspendLayout();
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
            this->TableLayoutPanel->Controls->Add(this->FormLayoutPanel, 0, 1);
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
            this->FormLayoutPanel->Controls->Add(this->StaffSeparator, 1, 2);
            this->FormLayoutPanel->Controls->Add(this->HireDateField, 1, 3);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 60);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(20);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 4;
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->FormLayoutPanel->Size = System::Drawing::Size(760, 350);
            this->FormLayoutPanel->TabIndex = 1;
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
            this->EditorHeader->CreateClick += gcnew System::EventHandler(
                this, &EmployeesEditView::EditorHeader_CreateClick);
            this->EditorHeader->CancelClick += gcnew System::EventHandler(
                this, &EmployeesEditView::EditorHeader_CancelClick);
            this->EditorHeader->DeleteClick += gcnew System::EventHandler(
                this, &EmployeesEditView::EditorHeader_DeleteClick);
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
                this, &EmployeesEditView::LastNameField_TextChanged);
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
                this, &EmployeesEditView::FirstNameField_TextChanged);
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
            // StaffSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->StaffSeparator, 3);
            this->StaffSeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StaffSeparator->LabelText = L"Employé";
            this->StaffSeparator->Location = System::Drawing::Point(120, 100);
            this->StaffSeparator->Margin = System::Windows::Forms::Padding(0);
            this->StaffSeparator->Name = L"StaffSeparator";
            this->StaffSeparator->Size = System::Drawing::Size(520, 50);
            this->StaffSeparator->TabIndex = 2;
            // 
            // HireDateField
            // 
            this->HireDateField->LabelText = L"Date d'embauche";
            this->HireDateField->Location = System::Drawing::Point(123, 153);
            this->HireDateField->Name = L"HireDateField";
            this->HireDateField->Size = System::Drawing::Size(244, 60);
            this->HireDateField->TabIndex = 3;
            this->HireDateField->Value = System::DateTime::Now;
            this->HireDateField->DateChanged += gcnew System::EventHandler(
                this, &EmployeesEditView::HideDateField_DateChanged);
            // 
            // EmployeesEditView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"EmployeesEditView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->FormLayoutPanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }

    public:
        void LoadForm(EditorMode mode, int employeeId)
        {
            this->EditorHeader->CurrentEditorMode = mode;
            this->currentEditorMode = mode;

            if (employeeId > 0 && mode == EditorMode::Edit)
            {
                staff = staffService->GetStaff(employeeId);
                this->EditorHeader->Label = "Édition de " + staff->GetFirstname() + " " + staff->GetLastname();
            }
            else
            {
                staff = gcnew Entities::StaffEntity();
                this->EditorHeader->Label = "Création d'un employé";
            }

            this->LastNameField->Value = staff->GetLastname();
            this->FirstNameField->Value = staff->GetFirstname();
            if (mode == EditorMode::Edit)
                this->HireDateField->Value = staff->GetHireDate();
            else
                this->HireDateField->Value = System::DateTime::Now;
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
                auto personId = staffService->AddPerson(staff);
                staff->SetPersonId(personId);
                staffService->AddStaff(staff);
            }
            else if (currentEditorMode == EditorMode::Edit)
            {
                staffService->UpdatePerson(staff);
                staffService->UpdateStaff(staff);
            }
            Back(this, e);
        }

        System::Void EditorHeader_DeleteClick(System::Object^ sender, System::EventArgs^ e)
        {
            // Confirm delete
            auto result = MessageBox::Show(
                "Êtes-vous sûr de vouloir supprimer cet employé ? Cette action est irréversible.",
                "Confirmation",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Warning,
                MessageBoxDefaultButton::Button2);

            if (result == DialogResult::No)
                return;

            bool success = staffService->DeleteStaff(staff);
            if (success)
                success = staffService->DeletePerson(staff);

            if (!success)
            {
                MessageBox::Show(
                    "Une erreur est survenue lors de la suppression de l'employé :\n" + Providers::DbProvider::GetLastException()->Message,
                    "Erreur",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Error);
                return;
            }
            
            Back(this, e);
        }

        System::Void LastNameField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            staff->SetLastname(LastNameField->Value);
        }

        System::Void FirstNameField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            staff->SetFirstname(FirstNameField->Value);
        }

        System::Void HideDateField_DateChanged(System::Object^ sender, System::EventArgs^ e)
        {
            staff->SetHireDate(HireDateField->Value);
        }
#pragma endregion
    };
}
