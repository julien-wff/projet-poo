#pragma once

#include "../components/EditorHeader.h"
#include "../components/FormSeparator.h"
#include "../components/TextField.h"
#include "../entities/ArticleEntity.h"
#include "../services/ArticleService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class ArticleEditView : public System::Windows::Forms::UserControl
    {
    public:
        ArticleEditView(void)
        {
            InitializeComponent();
        }

    protected:
        ~ArticleEditView()
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
        System::Windows::Forms::TableLayoutPanel^ FormLayoutPanel;
        Components::FormSeparator^ ArticleSeparator;
        Components::TextField^ NameField;
        Components::TextField^ PriceField;
        Components::TextField^ StockField;
        Components::TextField^ MaxStockField;
        Components::TextField^ VatField;
        System::ComponentModel::Container^ components;

        Services::ArticleService^ articleService = gcnew Services::ArticleService();
        Entities::ArticleEntity^ article;

        EditorMode CurrentEditorMode;


#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EditorHeader = (gcnew Components::EditorHeader());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ArticleSeparator = (gcnew Components::FormSeparator());
            this->NameField = (gcnew Components::TextField());
            this->PriceField = (gcnew Components::TextField());
            this->StockField = (gcnew Components::TextField());
            this->MaxStockField = (gcnew Components::TextField());
            this->VatField = (gcnew Components::TextField());
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
                this, &ArticleEditView::EditorHeader_CreateClick);
            this->EditorHeader->CancelClick += gcnew System::EventHandler(
                this, &ArticleEditView::EditorHeader_CancelClick);
            this->EditorHeader->DeleteClick += gcnew System::EventHandler(
                this, &ArticleEditView::EditorHeader_DeleteClick);
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
            this->FormLayoutPanel->Controls->Add(this->ArticleSeparator, 1, 0);
            this->FormLayoutPanel->Controls->Add(this->NameField, 1, 1);
            this->FormLayoutPanel->Controls->Add(this->PriceField, 3, 1);
            this->FormLayoutPanel->Controls->Add(this->StockField, 1, 2);
            this->FormLayoutPanel->Controls->Add(this->MaxStockField, 3, 2);
            this->FormLayoutPanel->Controls->Add(this->VatField, 1, 3);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 60);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(20);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 5;
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->FormLayoutPanel->Size = System::Drawing::Size(760, 253);
            this->FormLayoutPanel->TabIndex = 1;
            // 
            // ArticleSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->ArticleSeparator, 3);
            this->ArticleSeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ArticleSeparator->LabelText = L"Article";
            this->ArticleSeparator->Location = System::Drawing::Point(120, 0);
            this->ArticleSeparator->Margin = System::Windows::Forms::Padding(0);
            this->ArticleSeparator->Name = L"ArticleSeparator";
            this->ArticleSeparator->Size = System::Drawing::Size(520, 50);
            this->ArticleSeparator->TabIndex = 0;
            // 
            // NameField
            // 
            this->NameField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NameField->LabelText = L"Nom";
            this->NameField->Location = System::Drawing::Point(120, 50);
            this->NameField->Margin = System::Windows::Forms::Padding(0);
            this->NameField->Mode = TextFieldMode::Text;
            this->NameField->Name = L"NameField";
            this->NameField->Size = System::Drawing::Size(250, 50);
            this->NameField->TabIndex = 1;
            this->NameField->Value = L"";
            this->NameField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::NameField_TextChanged);
            // 
            // PriceField
            // 
            this->PriceField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->PriceField->LabelText = L"Prix";
            this->PriceField->Location = System::Drawing::Point(390, 50);
            this->PriceField->Margin = System::Windows::Forms::Padding(0);
            this->PriceField->Mode = TextFieldMode::Decimal;
            this->PriceField->Name = L"PriceField";
            this->PriceField->Size = System::Drawing::Size(250, 50);
            this->PriceField->TabIndex = 2;
            this->PriceField->Value = L"";
            this->PriceField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::PriceField_TextChanged);
            // 
            // StockField
            // 
            this->StockField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StockField->LabelText = L"Stock";
            this->StockField->Location = System::Drawing::Point(120, 105);
            this->StockField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->StockField->Mode = TextFieldMode::Integer;
            this->StockField->Name = L"StockField";
            this->StockField->Size = System::Drawing::Size(250, 50);
            this->StockField->TabIndex = 3;
            this->StockField->Value = L"";
            this->StockField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::StockField_TextChanged);
            // 
            // MaxStockField
            // 
            this->MaxStockField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MaxStockField->LabelText = L"Stock maximum";
            this->MaxStockField->Location = System::Drawing::Point(390, 105);
            this->MaxStockField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->MaxStockField->Mode = TextFieldMode::Text;
            this->MaxStockField->Name = L"MaxStockField";
            this->MaxStockField->Size = System::Drawing::Size(250, 50);
            this->MaxStockField->TabIndex = 4;
            this->MaxStockField->Value = L"";
            this->MaxStockField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::MaxStockField_TextChanged);
            // 
            // VatField
            // 
            this->VatField->LabelText = L"TVA (en pourcentage)";
            this->VatField->Location = System::Drawing::Point(120, 160);
            this->VatField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->VatField->Mode = TextFieldMode::Decimal;
            this->VatField->Name = L"VatField";
            this->VatField->Size = System::Drawing::Size(250, 50);
            this->VatField->TabIndex = 5;
            this->VatField->Value = L"";
            this->VatField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::VatField_TextChanged);
            // 
            // ArticleEditView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"ArticleEditView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->FormLayoutPanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void EditorHeader_CreateClick(System::Object^ sender, System::EventArgs^ e)
        {
            if (article->GetName() == nullptr || article->GetName()->Trim()->Length == 0)
            {
                MessageBox::Show("Le nom de l'article ne peut pas être vide.",
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

            if (CurrentEditorMode == EditorMode::Edit)
            {
                articleService->UpdateArticle(article);
            }
            else
            {
                articleService->AddArticle(article);
            }

            Back(this, e);
        }

        System::Void EditorHeader_CancelClick(System::Object^ sender, System::EventArgs^ e)
        {
            Back(this, e);
        }

        System::Void EditorHeader_DeleteClick(System::Object^ sender, System::EventArgs^ e)
        {
            auto dialogResult = MessageBox::Show(
                "Êtes-vous sûr de vouloir supprimer cet article ? Cette action est irréversible.",
                "Suppression",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Warning,
                MessageBoxDefaultButton::Button2);

            if (dialogResult == System::Windows::Forms::DialogResult::No)
                return;

            auto deleteResult = articleService->DeleteArticle(article);
            if (!deleteResult)
            {
                MessageBox::Show("Impossible de supprimer cet article. Erreur :\n"
                                 + Providers::DbProvider::GetLastException()->Message,
                                 "Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

            Back(this, e);
        }

        System::Void NameField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            article->SetName(NameField->Value);
        }

        System::Void PriceField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                article->SetPrice(Convert::ToSingle(PriceField->Value));
            }
            catch (...)
            {
                article->SetPrice(0);
            }
        }

        System::Void StockField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                article->SetStock(Convert::ToInt32(StockField->Value));
            }
            catch (...)
            {
                article->SetStock(0);
            }
        }

        System::Void MaxStockField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                article->SetMaxStock(Convert::ToInt32(MaxStockField->Value));
            }
            catch (...)
            {
                article->SetMaxStock(0);
            }
        }

        System::Void VatField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                article->SetVat(Convert::ToSingle(VatField->Value));
            }
            catch (...)
            {
                article->SetVat(0);
            }
        }

    public:
        void LoadForm(EditorMode mode, int articleReference)
        {
            this->CurrentEditorMode = mode;
            this->EditorHeader->CurrentEditorMode = mode;

            if (CurrentEditorMode == EditorMode::Edit && articleReference > 0)
            {
                article = articleService->GetArticle(articleReference);
                this->EditorHeader->Label = "Édition de " + article->GetName();
            }
            else
            {
                article = gcnew Entities::ArticleEntity();
                this->EditorHeader->Label = "Création d'un article";
            }

            this->NameField->Value = article->GetName();
            this->PriceField->Value = article->GetPrice().ToString();
            this->StockField->Value = article->GetStock().ToString();
            this->MaxStockField->Value = article->GetMaxStock().ToString();
            this->VatField->Value = article->GetVat().ToString();
        }

        void LoadForm(EditorMode mode)
        {
            LoadForm(mode, 0);
        }
    };
}
