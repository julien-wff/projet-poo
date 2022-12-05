#pragma once
#include "TextField.h"
#include "../entities/ArticleVariantEntity.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class ArticleVariantFields : public System::Windows::Forms::UserControl
    {
    public:
        ArticleVariantFields(void)
        {
            InitializeComponent();
        }

    protected:
        ~ArticleVariantFields()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        property bool AllowDelete
        {
            bool get()
            {
                return DeleteIcon->Visible;
            }

            void set(bool value)
            {
                DeleteIcon->Visible = value;
            }
        }

        property String^ Label
        {
            String^ get()
            {
                return VariantLabel->Text;
            }

            void set(String^ value)
            {
                VariantLabel->Text = value;
            }
        }

        property Entities::ArticleVariantEntity^ ArticleVariant
        {
            Entities::ArticleVariantEntity^ get()
            {
                return articleVariant;
            }

            void set(Entities::ArticleVariantEntity^ value)
            {
                articleVariant = value;
                ReductionField->Value = articleVariant->GetReductionValue().ToString();
                ReductionProductCountField->Value = articleVariant->GetReductionProductCount().ToString();
                ColorField->Value = articleVariant->GetColor();
            }
        }

        event EventHandler<Entities::ArticleVariantEntity^>^ Delete;
        event EventHandler^ Change;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ VariantLabel;
        Components::TextField^ ReductionField;
        Components::TextField^ ReductionProductCountField;
        Components::TextField^ ColorField;
        System::Windows::Forms::PictureBox^ DeleteIcon;
        System::ComponentModel::Container^ components;

        Entities::ArticleVariantEntity^ articleVariant;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew
                System::ComponentModel::ComponentResourceManager(ArticleVariantFields::typeid));
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->VariantLabel = (gcnew System::Windows::Forms::Label());
            this->ReductionField = (gcnew Components::TextField());
            this->ReductionProductCountField = (gcnew Components::TextField());
            this->ColorField = (gcnew Components::TextField());
            this->DeleteIcon = (gcnew System::Windows::Forms::PictureBox());
            this->TableLayoutPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteIcon))->BeginInit();
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
            this->TableLayoutPanel->Controls->Add(this->VariantLabel, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->ReductionField, 0, 1);
            this->TableLayoutPanel->Controls->Add(this->ReductionProductCountField, 2, 1);
            this->TableLayoutPanel->Controls->Add(this->ColorField, 0, 2);
            this->TableLayoutPanel->Controls->Add(this->DeleteIcon, 2, 0);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 3;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayoutPanel->Size = System::Drawing::Size(520, 150);
            this->TableLayoutPanel->TabIndex = 0;
            // 
            // VariantLabel
            // 
            this->VariantLabel->AutoSize = true;
            this->VariantLabel->Dock = System::Windows::Forms::DockStyle::Left;
            this->VariantLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                    System::Drawing::GraphicsUnit::Point,
                                                                    static_cast<System::Byte>(0)));
            this->VariantLabel->Location = System::Drawing::Point(0, 0);
            this->VariantLabel->Margin = System::Windows::Forms::Padding(0);
            this->VariantLabel->Name = L"VariantLabel";
            this->VariantLabel->Size = System::Drawing::Size(66, 30);
            this->VariantLabel->TabIndex = 0;
            this->VariantLabel->Text = L"Variante";
            this->VariantLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // ReductionField
            // 
            this->ReductionField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ReductionField->LabelText = L"Valeur de la réduction par produit (€)";
            this->ReductionField->Location = System::Drawing::Point(0, 30);
            this->ReductionField->Margin = System::Windows::Forms::Padding(0);
            this->ReductionField->Mode = TextFieldMode::Decimal;
            this->ReductionField->Name = L"ReductionField";
            this->ReductionField->Size = System::Drawing::Size(250, 50);
            this->ReductionField->TabIndex = 1;
            this->ReductionField->Value = L"0";
            this->ReductionField->TextChanged += gcnew System::EventHandler(
                this, &ArticleVariantFields::ReductionField_TextChanged);
            // 
            // ReductionProductCountField
            // 
            this->ReductionProductCountField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ReductionProductCountField->LabelText = L"Produits nécessaires pour la réduction";
            this->ReductionProductCountField->Location = System::Drawing::Point(270, 30);
            this->ReductionProductCountField->Margin = System::Windows::Forms::Padding(0);
            this->ReductionProductCountField->Mode = TextFieldMode::Integer;
            this->ReductionProductCountField->Name = L"ReductionProductCountField";
            this->ReductionProductCountField->Size = System::Drawing::Size(250, 50);
            this->ReductionProductCountField->TabIndex = 2;
            this->ReductionProductCountField->Value = L"0";
            this->ReductionProductCountField->TextChanged += gcnew System::EventHandler(
                this, &ArticleVariantFields::ReductionProductCountField_TextChanged);
            // 
            // ColorField
            // 
            this->ColorField->LabelText = L"Couleur";
            this->ColorField->Location = System::Drawing::Point(0, 85);
            this->ColorField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->ColorField->Mode = TextFieldMode::Text;
            this->ColorField->Name = L"ColorField";
            this->ColorField->Size = System::Drawing::Size(250, 50);
            this->ColorField->TabIndex = 3;
            this->ColorField->Value = L"";
            this->ColorField->TextChanged += gcnew System::EventHandler(
                this, &ArticleVariantFields::ColorField_TextChanged);
            // 
            // DeleteIcon
            // 
            this->DeleteIcon->Cursor = System::Windows::Forms::Cursors::Hand;
            this->DeleteIcon->Dock = System::Windows::Forms::DockStyle::Right;
            this->DeleteIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->
                GetObject(L"DeleteIcon.Image")));
            this->DeleteIcon->Location = System::Drawing::Point(494, 4);
            this->DeleteIcon->Margin = System::Windows::Forms::Padding(4);
            this->DeleteIcon->Name = L"DeleteIcon";
            this->DeleteIcon->Size = System::Drawing::Size(22, 22);
            this->DeleteIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->DeleteIcon->TabIndex = 4;
            this->DeleteIcon->TabStop = false;
            this->DeleteIcon->Click += gcnew System::EventHandler(this, &ArticleVariantFields::DeleteIcon_Click);
            // 
            // ArticleVariantFields
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Margin = System::Windows::Forms::Padding(0);
            this->Name = L"ArticleVariantFields";
            this->Size = System::Drawing::Size(520, 150);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteIcon))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void ReductionField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                this->ArticleVariant->SetReductionValue(Convert::ToSingle(ReductionField->Value));
                Change(this, e);
            }
            catch (...)
            {
                this->ArticleVariant->SetReductionValue(0);
            }
        }

        System::Void ReductionProductCountField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                this->ArticleVariant->SetReductionProductCount(Convert::ToInt32(ReductionProductCountField->Value));
                Change(this, e);
            }
            catch (...)
            {
                this->ArticleVariant->SetReductionProductCount(0);
            }
        }

        System::Void ColorField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            this->ArticleVariant->SetColor(ColorField->Value);
            Change(this, e);
        }

        System::Void DeleteIcon_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Delete(this, articleVariant);
        }
    };
}
