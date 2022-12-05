#pragma once

#include "../components/EditorHeader.h"
#include "../components/FormSeparator.h"
#include "../components/TextField.h"
#include "../components/ArticleVariantFields.h"
#include "../entities/ArticleEntity.h"
#include "../services/ArticleService.h"
#include "../services/ArticleVariantService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Generic;


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
        Components::FormSeparator^ VariantsSeparator;
        System::Windows::Forms::TableLayoutPanel^ VariantsLayoutPanel;
        System::Windows::Forms::Panel^ FormScrollPanel;
        System::Windows::Forms::TableLayoutPanel^ VariantAddLayoutPanel;
        System::Windows::Forms::Label^ VariantAddBtn;
        Components::TextField^ BuyPriceField;
        System::ComponentModel::Container^ components;

        Services::ArticleService^ articleService = gcnew Services::ArticleService();
        Entities::ArticleEntity^ article;
        Services::ArticleVariantService^ articleVariantService = gcnew Services::ArticleVariantService();
        List<Entities::ArticleVariantEntity^>^ articleVariants = gcnew List<Entities::ArticleVariantEntity^>();
        List<Entities::ArticleVariantEntity^>^ addedArticleVariants = gcnew List<Entities::ArticleVariantEntity^>();
        List<Entities::ArticleVariantEntity^>^ deletedArticleVariants = gcnew List<Entities::ArticleVariantEntity^>();
        List<Entities::ArticleVariantEntity^>^ updatedArticleVariants = gcnew List<Entities::ArticleVariantEntity^>();

        EditorMode CurrentEditorMode;


#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EditorHeader = (gcnew Components::EditorHeader());
            this->FormScrollPanel = (gcnew System::Windows::Forms::Panel());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ArticleSeparator = (gcnew Components::FormSeparator());
            this->NameField = (gcnew Components::TextField());
            this->VatField = (gcnew Components::TextField());
            this->PriceField = (gcnew Components::TextField());
            this->BuyPriceField = (gcnew Components::TextField());
            this->StockField = (gcnew Components::TextField());
            this->MaxStockField = (gcnew Components::TextField());
            this->VariantsLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->VariantsSeparator = (gcnew Components::FormSeparator());
            this->VariantAddLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->VariantAddBtn = (gcnew System::Windows::Forms::Label());
            this->TableLayoutPanel->SuspendLayout();
            this->FormScrollPanel->SuspendLayout();
            this->FormLayoutPanel->SuspendLayout();
            this->VariantAddLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->AutoScroll = true;
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->EditorHeader, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->FormScrollPanel, 0, 2);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 3;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
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
                this, &ArticleEditView::EditorHeader_DeleteClick);
            this->EditorHeader->CreateClick += gcnew System::EventHandler(
                this, &ArticleEditView::EditorHeader_CreateClick);
            this->EditorHeader->CancelClick += gcnew System::EventHandler(
                this, &ArticleEditView::EditorHeader_CancelClick);
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
            this->FormLayoutPanel->AutoSize = true;
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
            this->FormLayoutPanel->Controls->Add(this->VatField, 3, 1);
            this->FormLayoutPanel->Controls->Add(this->BuyPriceField, 1, 2);
            this->FormLayoutPanel->Controls->Add(this->PriceField, 3, 2);
            this->FormLayoutPanel->Controls->Add(this->StockField, 1, 3);
            this->FormLayoutPanel->Controls->Add(this->MaxStockField, 3, 3);
            this->FormLayoutPanel->Controls->Add(this->VariantsLayoutPanel, 1, 5);
            this->FormLayoutPanel->Controls->Add(this->VariantsSeparator, 1, 4);
            this->FormLayoutPanel->Controls->Add(this->VariantAddLayoutPanel, 1, 6);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 20);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(20);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 8;
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->FormLayoutPanel->Size = System::Drawing::Size(760, 325);
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
            this->NameField->Size = System::Drawing::Size(250, 55);
            this->NameField->TabIndex = 1;
            this->NameField->Value = L"";
            this->NameField->TextChanged += gcnew System::EventHandler(this, &ArticleEditView::NameField_TextChanged);
            // 
            // VatField
            // 
            this->VatField->LabelText = L"TVA (en pourcentage)";
            this->VatField->Location = System::Drawing::Point(390, 55);
            this->VatField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->VatField->Mode = TextFieldMode::Decimal;
            this->VatField->Name = L"VatField";
            this->VatField->Size = System::Drawing::Size(250, 50);
            this->VatField->TabIndex = 2;
            this->VatField->Value = L"";
            this->VatField->TextChanged += gcnew System::EventHandler(this, &ArticleEditView::VatField_TextChanged);
            // 
            // PriceField
            // 
            this->PriceField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->PriceField->LabelText = L"Prix de vente";
            this->PriceField->Location = System::Drawing::Point(120, 105);
            this->PriceField->Margin = System::Windows::Forms::Padding(0);
            this->PriceField->Mode = TextFieldMode::Decimal;
            this->PriceField->Name = L"PriceField";
            this->PriceField->Size = System::Drawing::Size(250, 55);
            this->PriceField->TabIndex = 4;
            this->PriceField->Value = L"";
            this->PriceField->TextChanged += gcnew System::EventHandler(this, &ArticleEditView::PriceField_TextChanged);
            // 
            // BuyPriceField
            // 
            this->BuyPriceField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->BuyPriceField->LabelText = L"Prix d\'achat";
            this->BuyPriceField->Location = System::Drawing::Point(390, 105);
            this->BuyPriceField->Margin = System::Windows::Forms::Padding(0);
            this->BuyPriceField->Mode = TextFieldMode::Decimal;
            this->BuyPriceField->Name = L"BuyPriceField";
            this->BuyPriceField->Size = System::Drawing::Size(250, 55);
            this->BuyPriceField->TabIndex = 3;
            this->BuyPriceField->Value = L"";
            this->BuyPriceField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::BuyPriceField_TextChanged);
            // 
            // StockField
            // 
            this->StockField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StockField->LabelText = L"Stock";
            this->StockField->Location = System::Drawing::Point(120, 165);
            this->StockField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->StockField->Mode = TextFieldMode::Integer;
            this->StockField->Name = L"StockField";
            this->StockField->Size = System::Drawing::Size(250, 50);
            this->StockField->TabIndex = 5;
            this->StockField->Value = L"";
            this->StockField->TextChanged += gcnew System::EventHandler(this, &ArticleEditView::StockField_TextChanged);
            // 
            // MaxStockField
            // 
            this->MaxStockField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MaxStockField->LabelText = L"Stock maximum";
            this->MaxStockField->Location = System::Drawing::Point(390, 165);
            this->MaxStockField->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
            this->MaxStockField->Mode = TextFieldMode::Text;
            this->MaxStockField->Name = L"MaxStockField";
            this->MaxStockField->Size = System::Drawing::Size(250, 50);
            this->MaxStockField->TabIndex = 6;
            this->MaxStockField->Value = L"";
            this->MaxStockField->TextChanged += gcnew System::EventHandler(
                this, &ArticleEditView::MaxStockField_TextChanged);
            // 
            // VariantsLayoutPanel
            // 
            this->VariantsLayoutPanel->AutoSize = true;
            this->VariantsLayoutPanel->ColumnCount = 1;
            this->FormLayoutPanel->SetColumnSpan(this->VariantsLayoutPanel, 3);
            this->VariantsLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->VariantsLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->VariantsLayoutPanel->Location = System::Drawing::Point(120, 265);
            this->VariantsLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->VariantsLayoutPanel->Name = L"VariantsLayoutPanel";
            this->VariantsLayoutPanel->RowCount = 1;
            this->VariantsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->VariantsLayoutPanel->Size = System::Drawing::Size(520, 0);
            this->VariantsLayoutPanel->TabIndex = 7;
            // 
            // VariantsSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->VariantsSeparator, 3);
            this->VariantsSeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->VariantsSeparator->LabelText = L"Variantes";
            this->VariantsSeparator->Location = System::Drawing::Point(120, 215);
            this->VariantsSeparator->Margin = System::Windows::Forms::Padding(0);
            this->VariantsSeparator->Name = L"VariantsSeparator";
            this->VariantsSeparator->Size = System::Drawing::Size(520, 50);
            // 
            // VariantAddLayoutPanel
            // 
            this->VariantAddLayoutPanel->ColumnCount = 3;
            this->FormLayoutPanel->SetColumnSpan(this->VariantAddLayoutPanel, 3);
            this->VariantAddLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->VariantAddLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->VariantAddLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->VariantAddLayoutPanel->Controls->Add(this->VariantAddBtn, 1, 0);
            this->VariantAddLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->VariantAddLayoutPanel->Location = System::Drawing::Point(120, 265);
            this->VariantAddLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->VariantAddLayoutPanel->Name = L"VariantAddLayoutPanel";
            this->VariantAddLayoutPanel->RowCount = 1;
            this->VariantAddLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->VariantAddLayoutPanel->Size = System::Drawing::Size(520, 40);
            // 
            // VariantAddBtn
            // 
            this->VariantAddBtn->AutoSize = true;
            this->VariantAddBtn->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(173)));
            this->VariantAddBtn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->VariantAddBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->VariantAddBtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                     System::Drawing::GraphicsUnit::Point,
                                                                     static_cast<System::Byte>(0)));
            this->VariantAddBtn->ForeColor = System::Drawing::Color::White;
            this->VariantAddBtn->Location = System::Drawing::Point(167, 0);
            this->VariantAddBtn->Margin = System::Windows::Forms::Padding(0);
            this->VariantAddBtn->Name = L"VariantAddBtn";
            this->VariantAddBtn->Padding = System::Windows::Forms::Padding(20, 2, 20, 2);
            this->VariantAddBtn->Size = System::Drawing::Size(185, 40);
            this->VariantAddBtn->TabIndex = 8;
            this->VariantAddBtn->Text = L"Ajouter une variante";
            this->VariantAddBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->VariantAddBtn->Click += gcnew System::EventHandler(this, &ArticleEditView::VariantAddBtn_Click);
            // 
            // ArticleEditView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"ArticleEditView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->FormScrollPanel->ResumeLayout(false);
            this->FormScrollPanel->PerformLayout();
            this->FormLayoutPanel->ResumeLayout(false);
            this->FormLayoutPanel->PerformLayout();
            this->VariantAddLayoutPanel->ResumeLayout(false);
            this->VariantAddLayoutPanel->PerformLayout();
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

            for (int i = 0; i < addedArticleVariants->Count; i++)
            {
                articleVariantService->AddArticleVariant(addedArticleVariants[i]);
            }
            for (int i = 0; i < updatedArticleVariants->Count; i++)
            {
                articleVariantService->UpdateArticleVariant(updatedArticleVariants[i]);
            }
            for (int i = 0; i < deletedArticleVariants->Count; i++)
            {
                articleVariantService->DeleteArticleVariant(deletedArticleVariants[i]);
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

        System::Void BuyPriceField_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                article->SetBuyPrice(Convert::ToSingle(BuyPriceField->Value));
            }
            catch (...)
            {
                article->SetBuyPrice(0);
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

        System::Void ArticleVariant_DeleteClick(System::Object^ sender, Entities::ArticleVariantEntity^ articleVariant)
        {
            for (int i = 0; i < articleVariants->Count; i++)
            {
                if (articleVariants[i]->GetArticleVariantId() == articleVariant->GetArticleVariantId())
                {
                    deletedArticleVariants->Add(articleVariants[i]);
                    articleVariants->RemoveAt(i);
                    break;
                }
            }
            // Look for the article variant in the added article variants
            for (int i = 0; i < addedArticleVariants->Count; i++)
            {
                if (addedArticleVariants[i]->GetArticleVariantId() == articleVariant->GetArticleVariantId())
                {
                    addedArticleVariants->RemoveAt(i);
                    break;
                }
            }
            // Look for the article variant in the updated article variants
            for (int i = 0; i < updatedArticleVariants->Count; i++)
            {
                if (updatedArticleVariants[i]->GetArticleVariantId() == articleVariant->GetArticleVariantId())
                {
                    updatedArticleVariants->RemoveAt(i);
                    break;
                }
            }
            BuildVariantList();
        }

        System::Void VariantAddBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            auto newArticleVariant = gcnew Entities::ArticleVariantEntity();
            articleVariants->Add(newArticleVariant);
            addedArticleVariants->Add(newArticleVariant);
            newArticleVariant->SetArticleReference(article->GetArticleReference());
            BuildVariantList();
        }

        void BuildVariantList()
        {
            this->VariantsLayoutPanel->SuspendLayout();
            this->VariantAddLayoutPanel->SuspendLayout();
            this->FormLayoutPanel->SuspendLayout();
            this->TableLayoutPanel->SuspendLayout();
            this->VariantsLayoutPanel->Controls->Clear();
            this->VariantsLayoutPanel->RowCount = articleVariants->Count;

            for (int i = 0; i < articleVariants->Count; i++)
            {
                auto variantField = gcnew Components::ArticleVariantFields();
                variantField->ArticleVariant = articleVariants[i];
                variantField->Dock = DockStyle::Fill;
                variantField->AllowDelete = articleVariants->Count > 1;
                variantField->Label = L"Variante #" + (i + 1);
                variantField->Location = System::Drawing::Point(0, 0);
                variantField->Margin = System::Windows::Forms::Padding(0);
                variantField->Name = L"ArticleVariantFields" + (i + 1);
                variantField->Size = System::Drawing::Size(520, 160);
                variantField->TabIndex = 0;
                variantField->Delete += gcnew System::EventHandler<Entities::ArticleVariantEntity^>(
                    this, &ArticleEditView::ArticleVariant_DeleteClick);
                this->VariantsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
                this->VariantsLayoutPanel->Controls->Add(variantField, 0, i);
            }

            this->VariantsLayoutPanel->ResumeLayout(false);
            this->VariantsLayoutPanel->PerformLayout();
            this->VariantAddLayoutPanel->ResumeLayout(false);
            this->VariantAddLayoutPanel->PerformLayout();
            this->FormLayoutPanel->ResumeLayout(false);
            this->FormLayoutPanel->PerformLayout();
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
        }

    public:
        void LoadForm(EditorMode mode, int articleReference)
        {
            this->CurrentEditorMode = mode;
            this->EditorHeader->CurrentEditorMode = mode;

            articleVariants->Clear();
            addedArticleVariants->Clear();
            deletedArticleVariants->Clear();
            updatedArticleVariants->Clear();

            if (CurrentEditorMode == EditorMode::Edit && articleReference > 0)
            {
                article = articleService->GetArticle(articleReference);
                auto variants = articleService->GetArticleVariants(article);
                articleVariants = gcnew List<Entities::ArticleVariantEntity^>(variants);
                updatedArticleVariants = gcnew List<Entities::ArticleVariantEntity^>(variants);
                this->EditorHeader->Label = "Édition de " + article->GetName();
            }
            else
            {
                article = gcnew Entities::ArticleEntity();
                auto newArticleVariant = gcnew Entities::ArticleVariantEntity();
                articleVariants->Add(newArticleVariant);
                addedArticleVariants->Add(newArticleVariant);
                newArticleVariant->SetArticleReference(article->GetArticleReference());
                this->EditorHeader->Label = "Création d'un article";
            }

            this->NameField->Value = article->GetName();
            this->PriceField->Value = article->GetPrice().ToString();
            this->BuyPriceField->Value = article->GetBuyPrice().ToString();
            this->StockField->Value = article->GetStock().ToString();
            this->MaxStockField->Value = article->GetMaxStock().ToString();
            this->VatField->Value = article->GetVat().ToString();
            BuildVariantList();
            this->FormScrollPanel->AutoScrollPosition = System::Drawing::Point(0, 0);
        }

        void LoadForm(EditorMode mode)
        {
            LoadForm(mode, 0);
        }
    };
}
