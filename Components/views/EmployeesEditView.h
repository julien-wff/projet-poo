#pragma once
#include "../components/EditorHeader.h"
#include "../components/TextField.h"
#include "../components/FormSeparator.h"
#include "../components/DateField.h"
#include "../components/SelectField.h"
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
        Components::DateField^ HireDateField;
        Components::SelectField^ SupervisorField;

        Services::StaffService^ staffService = gcnew Services::StaffService();
        Entities::StaffEntity^ staff;
        Entities::StaffEntity^ supervisor;
        array<Entities::StaffEntity^>^ possibleSupervisors;


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
            this->SupervisorField = (gcnew Components::SelectField());
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
            this->FormLayoutPanel->Controls->Add(this->SupervisorField, 3, 3);
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
            this->HireDateField->Dock = System::Windows::Forms::DockStyle::Top;
            this->HireDateField->LabelText = L"Date d\'embauche";
            this->HireDateField->Location = System::Drawing::Point(120, 150);
            this->HireDateField->Margin = System::Windows::Forms::Padding(0);
            this->HireDateField->Name = L"HireDateField";
            this->HireDateField->Size = System::Drawing::Size(250, 60);
            this->HireDateField->TabIndex = 3;
            this->HireDateField->Value = System::DateTime::Now;
            this->HireDateField->DateChanged += gcnew System::EventHandler(
                this, &EmployeesEditView::HideDateField_DateChanged);
            // 
            // SupervisorField
            // 
            this->SupervisorField->Dock = System::Windows::Forms::DockStyle::Top;
            this->SupervisorField->LabelText = L"Superieur hiérarchique";
            this->SupervisorField->Location = System::Drawing::Point(390, 150);
            this->SupervisorField->Margin = System::Windows::Forms::Padding(0);
            this->SupervisorField->Name = L"SupervisorField";
            this->SupervisorField->Size = System::Drawing::Size(250, 60);
            this->SupervisorField->TabIndex = 4;
            this->SupervisorField->SelectionChanged += gcnew System::EventHandler<Object^>(
                this, &EmployeesEditView::SupervisorField_SelectionChanged);
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
                possibleSupervisors = staffService->GetPossibleSupervisors(staff);
                supervisor = staffService->GetSupervisor(staff);
                this->EditorHeader->Label = "Édition de " + staff->GetFirstname() + " " + staff->GetLastname();
            }
            else
            {
                staff = gcnew Entities::StaffEntity();
                auto staffs = staffService->GetStaffs();
                possibleSupervisors = gcnew array<Entities::StaffEntity^>(staffs->Rows->Count);
                for (int i = 0; i < staffs->Rows->Count; i++)
                    possibleSupervisors[i] = gcnew Entities::StaffEntity(staffs->Rows[i]);
                supervisor = nullptr;

                this->EditorHeader->Label = "Création d'un employé";
            }

            this->LastNameField->Value = staff->GetLastname();
            this->FirstNameField->Value = staff->GetFirstname();
            if (mode == EditorMode::Edit)
                this->HireDateField->Value = staff->GetHireDate();
            else
                this->HireDateField->Value = System::DateTime::Now;

            auto possibleSupervisorsItems = gcnew array<Tuple<Object^, String^>^>(possibleSupervisors->Length + 1);
            possibleSupervisorsItems[0] = gcnew Tuple<Object^, String^>(nullptr, "<Aucun>");
            for (int i = 0; i < possibleSupervisors->Length; i++)
                possibleSupervisorsItems[i + 1] = gcnew Tuple<Object^, String^>(
                    possibleSupervisors[i],
                    possibleSupervisors[i]->GetFirstname() + " " + possibleSupervisors[i]->GetLastname()
                );
            this->SupervisorField->Items = possibleSupervisorsItems;

            // Find the index of supervisor in the list and select it
            if (supervisor != nullptr)
            {
                for (int i = 0; i < possibleSupervisors->Length; i++)
                    if (possibleSupervisors[i]->GetStaffId() == supervisor->GetStaffId())
                    {
                        this->SupervisorField->SelectedIndex = i + 1;
                        break;
                    }
            }
            else
            {
                this->SupervisorField->SelectedIndex = 0;
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
            if (staff->GetLastname() == nullptr || staff->GetLastname()->Trim() == ""
                || staff->GetFirstname() == nullptr || staff->GetFirstname()->Trim() == "")
            {
                MessageBox::Show("Veuillez entrer un nom et un prénom.",
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

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
                String^ message;
                if (Providers::DbProvider::GetLastException()->Number == 547)
                    message =
                        "Impossible de supprimer cet employé car il est lié à d'autres données. Veuillez d'abord supprimer ces données.";
                else
                    message = "Une erreur est survenue lors de la suppression de l'employé :\n" +
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

        System::Void SupervisorField_SelectionChanged(System::Object^ sender, System::Object^ e)
        {
            auto _sup = safe_cast<Entities::StaffEntity^>(e);
            staff->SetSupervisedBy(_sup == nullptr ? 0 : _sup->GetStaffId());
            supervisor = _sup;
        }
#pragma endregion
    };
}
