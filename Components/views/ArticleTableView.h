#pragma once

#include "../components/TableHeader.h"
#include "../components/TableDisplay.h"
#include "../services/ArticleService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class ArticleTableView : public System::Windows::Forms::UserControl
    {
    public:
        ArticleTableView(void)
        {
            InitializeComponent();
        }

    protected:
        ~ArticleTableView()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        event EventHandler^ CreateClick;
        event EventHandler<int>^ ArticleClick;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        Components::TableHeader^ TableHeader;
        System::ComponentModel::Container^ components;
        Components::TableDisplay^ TableDisplay;

        Services::ArticleService^ articleService = gcnew Services::ArticleService();

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->TableHeader = (gcnew Components::TableHeader());
            this->TableDisplay = (gcnew Components::TableDisplay());
            this->TableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->TableHeader, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->TableDisplay, 0, 1);
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
            // TableHeader
            // 
            this->TableHeader->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableHeader->Label = L"Liste des articles";
            this->TableHeader->Location = System::Drawing::Point(0, 0);
            this->TableHeader->Margin = System::Windows::Forms::Padding(0);
            this->TableHeader->Name = L"TableHeader";
            this->TableHeader->Size = System::Drawing::Size(800, 40);
            this->TableHeader->TabIndex = 0;
            this->TableHeader->RefreshClick += gcnew System::EventHandler(
                this, &ArticleTableView::TableHeader_RefreshClick);
            this->TableHeader->AddClick += gcnew System::EventHandler(
                this, &ArticleTableView::TableHeader_AddClick);
            // 
            // TableDisplay
            // 
            this->TableDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableDisplay->Location = System::Drawing::Point(0, 40);
            this->TableDisplay->Margin = System::Windows::Forms::Padding(0);
            this->TableDisplay->Name = L"TableDisplay";
            this->TableDisplay->Size = System::Drawing::Size(800, 560);
            this->TableDisplay->TabIndex = 1;
            this->TableDisplay->Load += gcnew System::EventHandler(this, &ArticleTableView::TableDisplay_Load);
            this->TableDisplay->RowSelect += gcnew System::EventHandler<DataRow^>(
                this, &ArticleTableView::TableDisplay_RowSelected);
            // 
            // ArticleTableView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"ArticleTableView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void TableDisplay_Load(System::Object^ sender, System::EventArgs^ e)
        {
            this->TableDisplay->AddColumn("Référence", "reference");
            this->TableDisplay->AddColumn("Nom", "name");
            this->TableDisplay->AddColumn("Stock restant", "stock");
            this->TableDisplay->AddColumn("Prix d'achat", "buy_price");
            this->TableDisplay->AddColumn("Prix de vente", "price");
        }

        System::Void TableHeader_RefreshClick(System::Object^ sender, System::EventArgs^ e)
        {
            this->LoadData();
        }

        System::Void TableHeader_AddClick(System::Object^ sender, System::EventArgs^ e)
        {
            this->CreateClick(this, e);
        }

        System::Void TableDisplay_RowSelected(System::Object^ sender, DataRow^ row)
        {
            this->ArticleClick(this, safe_cast<int>(row["reference"]));
        }

    public:
        void LoadData()
        {
            auto articles = articleService->GetArticles();
            TableDisplay->SetDataSource(articles);
        }
    };
}
