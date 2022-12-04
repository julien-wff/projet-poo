#pragma once
#include "SelectField.h"
#include "TextField.h"
#include "../services/CityService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class AddressCityFields : public System::Windows::Forms::UserControl
    {
    public:
        AddressCityFields(void)
        {
            InitializeComponent();
        }

    protected:
        ~AddressCityFields()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        property int ZipCode
        {
            int get()
            {
                // Test if the zip code is a valid integer
                try
                {
                    return Convert::ToInt32(PostalCodeField->Value);
                }
                catch (FormatException^)
                {
                    return 0;
                }
            }

            void set(int value)
            {
                PostalCodeField->Value = value.ToString();
                LoadCitySuggestions();
            }
        }

        bool SetSelectedCity(Entities::CityEntity^ city)
        {
            auto cities = CityField->Items;
            for (int i = 0; i < cities->Length; i++)
            {
                auto item = safe_cast<Entities::CityEntity^>(cities[i]->Item1);
                if (item->GetCityId() == city->GetCityId())
                {
                    CityField->SelectedIndex = i;
                    return true;
                }
            }
            return false;
        }

        void ClearFields()
        {
            CityField->SelectedIndex = -1;
            CityField->Items = nullptr;
            PostalCodeField->Value = "";
        }

        event EventHandler<Entities::CityEntity^>^ CityChanged;
        event EventHandler<int>^ ZipCodeChanged;

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        Components::TextField^ PostalCodeField;
        Components::SelectField^ CityField;

        Services::CityService^ cityService = gcnew Services::CityService();
        Entities::CityEntity^ SelectedCity;
        int PreviousZipCode = 0;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->PostalCodeField = (gcnew Components::TextField());
            this->CityField = (gcnew Components::SelectField());
            this->TableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 3;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Absolute,
                20)));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->TableLayoutPanel->Controls->Add(this->PostalCodeField, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->CityField, 2, 0);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 1;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayoutPanel->Size = System::Drawing::Size(520, 50);
            this->TableLayoutPanel->TabIndex = 0;
            // 
            // PostalCodeField
            // 
            this->PostalCodeField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->PostalCodeField->LabelText = L"Code postal";
            this->PostalCodeField->Location = System::Drawing::Point(0, 0);
            this->PostalCodeField->Margin = System::Windows::Forms::Padding(0);
            this->PostalCodeField->Name = L"PostalCodeField";
            this->PostalCodeField->Size = System::Drawing::Size(250, 50);
            this->PostalCodeField->TabIndex = 0;
            this->PostalCodeField->Value = L"";
            this->PostalCodeField->Leave += gcnew System::EventHandler(this, &AddressCityFields::PostalCodeField_Leave);
            // 
            // CityField
            // 
            this->CityField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CityField->Items = gcnew cli::array<System::Tuple<System::Object^, System::String^>^>(0);
            this->CityField->LabelText = L"Ville";
            this->CityField->Location = System::Drawing::Point(270, 0);
            this->CityField->Margin = System::Windows::Forms::Padding(0);
            this->CityField->Name = L"CityField";
            this->CityField->Size = System::Drawing::Size(250, 50);
            this->CityField->TabIndex = 1;
            this->CityField->SelectionChanged += gcnew System::EventHandler<Object^>(
                this, &AddressCityFields::CityField_SelectionChanged);
            // 
            // AddressCityFields
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"AddressCityFields";
            this->Size = System::Drawing::Size(520, 50);
            this->TableLayoutPanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void PostalCodeField_Leave(System::Object^ sender, System::EventArgs^ e)
        {
            if (PreviousZipCode == ZipCode)
                return;

            LoadCitySuggestions();
            PreviousZipCode = ZipCode;
            ZipCodeChanged(this, ZipCode);
            CityChanged(this, nullptr);
        }

        System::Void CityField_SelectionChanged(System::Object^ sender, System::Object^ e)
        {
            if (CityField->SelectedIndex == -1)
                return;

            SelectedCity = safe_cast<Entities::CityEntity^>(CityField->SelectedItem);
            CityChanged(this, SelectedCity);
        }

        void LoadCitySuggestions()
        {
            auto cities = cityService->GetCitiesByZipCode(ZipCode);
            if (cities->Length == 0)
            {
                CityField->SelectedIndex = -1;
                CityField->Items = nullptr;
                CityChanged(this, nullptr);
                return;
            }

            array<Tuple<Object^, String^>^>^ items = gcnew array<Tuple<Object^, String^>^>(cities->Length);
            for (int i = 0; i < cities->Length; i++)
                items[i] = gcnew Tuple<Object^, String^>(cities[i], cities[i]->GetCity());
            CityField->Items = items;
        }
    };
}
