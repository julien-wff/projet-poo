#pragma once

#include "../components/FormSeparator.h"
#include "../services/StatisticService.h"
#include "../components/SelectField.h"
#include "../components/DateField.h"
#include "../components/TextField.h"
#include "../services/ClientService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class StatisticsView : public System::Windows::Forms::UserControl
    {
    public:
        StatisticsView(void)
        {
            InitializeComponent();
        }

    protected:
        ~StatisticsView()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::TableLayoutPanel^ HeaderLayoutPanel;
        System::Windows::Forms::Label^ HeaderLabel;
        System::Windows::Forms::Label^ RefreshBtn;
        System::Windows::Forms::Panel^ FormScrollPanel;
        System::Windows::Forms::TableLayoutPanel^ FormLayoutPanel;
        Components::FormSeparator^ CommercialStockValue;
        System::Windows::Forms::Label^ CommercialStockValueLabel;
        System::ComponentModel::Container^ components;
        Components::FormSeparator^ ArticlesSellsSeparator;
        System::Windows::Forms::TableLayoutPanel^ BestArticlesLayoutPanel;
        System::Windows::Forms::Label^ BestArticlesHeader;
        System::Windows::Forms::TableLayoutPanel^ WorstArticlesLayoutPanel;
        System::Windows::Forms::Label^ WorstArticlesHeader;
        Components::FormSeparator^ ClientExpenseSeparator;
        Components::SelectField^ ClientExpenseSelect;
        System::Windows::Forms::Label^ ClientExpensesLabel;
        Components::FormSeparator^ MonthTurnoverSeparator;
        Components::DateField^ MonthTurnoverDateField;
        System::Windows::Forms::Label^ MonthTurnoverLabel;
        Components::FormSeparator^ AverageCartSeparator;
        System::Windows::Forms::Label^ AverageCardLabel;
        Components::FormSeparator^ ProductRestockSeparator;
        Components::TextField^ ProductRestockField;
        System::Windows::Forms::Label^ ProductsRestockPanel;
        Components::FormSeparator^ ClientBirthdaySeparator;
        System::Windows::Forms::TableLayoutPanel^ ClientBirthdayTodayTablePanel;
        System::Windows::Forms::Label^ ClientBirthdayTodayLabel;
        System::Windows::Forms::TableLayoutPanel^ ClientFutureBirthdayTableLayoutPanel;
        System::Windows::Forms::Label^ ClientFutureBirthdayLabel;
        System::Windows::Forms::TableLayoutPanel^ ProductRestockTableLayoutPanel;

        Services::StatisticService^ statisticService = gcnew Services::StatisticService();
        Services::ClientService^ clientService = gcnew Services::ClientService();

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->HeaderLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->HeaderLabel = (gcnew System::Windows::Forms::Label());
            this->RefreshBtn = (gcnew System::Windows::Forms::Label());
            this->FormScrollPanel = (gcnew System::Windows::Forms::Panel());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ClientBirthdayTodayTablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ClientBirthdayTodayLabel = (gcnew System::Windows::Forms::Label());
            this->CommercialStockValue = (gcnew Components::FormSeparator());
            this->CommercialStockValueLabel = (gcnew System::Windows::Forms::Label());
            this->ArticlesSellsSeparator = (gcnew Components::FormSeparator());
            this->BestArticlesLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->BestArticlesHeader = (gcnew System::Windows::Forms::Label());
            this->WorstArticlesLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->WorstArticlesHeader = (gcnew System::Windows::Forms::Label());
            this->ClientExpenseSeparator = (gcnew Components::FormSeparator());
            this->ClientExpenseSelect = (gcnew Components::SelectField());
            this->ClientExpensesLabel = (gcnew System::Windows::Forms::Label());
            this->MonthTurnoverSeparator = (gcnew Components::FormSeparator());
            this->MonthTurnoverDateField = (gcnew Components::DateField());
            this->MonthTurnoverLabel = (gcnew System::Windows::Forms::Label());
            this->AverageCartSeparator = (gcnew Components::FormSeparator());
            this->AverageCardLabel = (gcnew System::Windows::Forms::Label());
            this->ProductRestockSeparator = (gcnew Components::FormSeparator());
            this->ProductRestockField = (gcnew Components::TextField());
            this->ProductRestockTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ProductsRestockPanel = (gcnew System::Windows::Forms::Label());
            this->ClientBirthdaySeparator = (gcnew Components::FormSeparator());
            this->ClientFutureBirthdayTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->ClientFutureBirthdayLabel = (gcnew System::Windows::Forms::Label());
            this->TableLayoutPanel->SuspendLayout();
            this->HeaderLayoutPanel->SuspendLayout();
            this->FormScrollPanel->SuspendLayout();
            this->FormLayoutPanel->SuspendLayout();
            this->ClientBirthdayTodayTablePanel->SuspendLayout();
            this->BestArticlesLayoutPanel->SuspendLayout();
            this->WorstArticlesLayoutPanel->SuspendLayout();
            this->ProductRestockTableLayoutPanel->SuspendLayout();
            this->ClientFutureBirthdayTableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->HeaderLayoutPanel, 0, 0);
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
            // HeaderLayoutPanel
            // 
            this->HeaderLayoutPanel->ColumnCount = 2;
            this->HeaderLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->HeaderLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->HeaderLayoutPanel->Controls->Add(this->HeaderLabel, 0, 0);
            this->HeaderLayoutPanel->Controls->Add(this->RefreshBtn, 1, 0);
            this->HeaderLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->HeaderLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->HeaderLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->HeaderLayoutPanel->Name = L"HeaderLayoutPanel";
            this->HeaderLayoutPanel->RowCount = 1;
            this->HeaderLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->HeaderLayoutPanel->Size = System::Drawing::Size(800, 40);
            this->HeaderLayoutPanel->TabIndex = 0;
            // 
            // HeaderLabel
            // 
            this->HeaderLabel->AutoSize = true;
            this->HeaderLabel->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(4)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->HeaderLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->HeaderLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                   System::Drawing::GraphicsUnit::Point,
                                                                   static_cast<System::Byte>(0)));
            this->HeaderLabel->ForeColor = System::Drawing::Color::White;
            this->HeaderLabel->Location = System::Drawing::Point(0, 0);
            this->HeaderLabel->Margin = System::Windows::Forms::Padding(0);
            this->HeaderLabel->Name = L"HeaderLabel";
            this->HeaderLabel->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
            this->HeaderLabel->Size = System::Drawing::Size(625, 40);
            this->HeaderLabel->TabIndex = 0;
            this->HeaderLabel->Text = L"Statistiques";
            this->HeaderLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // RefreshBtn
            // 
            this->RefreshBtn->AutoSize = true;
            this->RefreshBtn->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(69)),
                static_cast<System::Int32>(static_cast<System::Byte>(186)),
                static_cast<System::Int32>(static_cast<System::Byte>(103)));
            this->RefreshBtn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->RefreshBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->RefreshBtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                  System::Drawing::GraphicsUnit::Point,
                                                                  static_cast<System::Byte>(0)));
            this->RefreshBtn->ForeColor = System::Drawing::Color::White;
            this->RefreshBtn->Location = System::Drawing::Point(625, 0);
            this->RefreshBtn->Margin = System::Windows::Forms::Padding(0);
            this->RefreshBtn->Name = L"RefreshBtn";
            this->RefreshBtn->Padding = System::Windows::Forms::Padding(50, 0, 50, 0);
            this->RefreshBtn->Size = System::Drawing::Size(175, 40);
            this->RefreshBtn->TabIndex = 1;
            this->RefreshBtn->Text = L"Rafraichir";
            this->RefreshBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->RefreshBtn->Click += gcnew System::EventHandler(this, &StatisticsView::RefreshBtn_Click);
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
            this->FormLayoutPanel->Controls->Add(this->ClientFutureBirthdayTableLayoutPanel, 3, 14);
            this->FormLayoutPanel->Controls->Add(this->ClientBirthdayTodayTablePanel, 1, 14);
            this->FormLayoutPanel->Controls->Add(this->CommercialStockValue, 1, 0);
            this->FormLayoutPanel->Controls->Add(this->CommercialStockValueLabel, 1, 1);
            this->FormLayoutPanel->Controls->Add(this->ArticlesSellsSeparator, 1, 2);
            this->FormLayoutPanel->Controls->Add(this->BestArticlesLayoutPanel, 1, 3);
            this->FormLayoutPanel->Controls->Add(this->WorstArticlesLayoutPanel, 3, 3);
            this->FormLayoutPanel->Controls->Add(this->ClientExpenseSeparator, 1, 4);
            this->FormLayoutPanel->Controls->Add(this->ClientExpenseSelect, 1, 5);
            this->FormLayoutPanel->Controls->Add(this->ClientExpensesLabel, 3, 5);
            this->FormLayoutPanel->Controls->Add(this->MonthTurnoverSeparator, 1, 6);
            this->FormLayoutPanel->Controls->Add(this->MonthTurnoverDateField, 1, 7);
            this->FormLayoutPanel->Controls->Add(this->MonthTurnoverLabel, 3, 7);
            this->FormLayoutPanel->Controls->Add(this->AverageCartSeparator, 1, 8);
            this->FormLayoutPanel->Controls->Add(this->AverageCardLabel, 1, 9);
            this->FormLayoutPanel->Controls->Add(this->ProductRestockSeparator, 1, 10);
            this->FormLayoutPanel->Controls->Add(this->ProductRestockField, 1, 11);
            this->FormLayoutPanel->Controls->Add(this->ProductRestockTableLayoutPanel, 3, 11);
            this->FormLayoutPanel->Controls->Add(this->ClientBirthdaySeparator, 1, 13);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 20);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 16;
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
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
            this->FormLayoutPanel->Size = System::Drawing::Size(743, 672);
            this->FormLayoutPanel->TabIndex = 0;
            // 
            // ClientBirthdayTodayTablePanel
            // 
            this->ClientBirthdayTodayTablePanel->AutoSize = true;
            this->ClientBirthdayTodayTablePanel->ColumnCount = 1;
            this->ClientBirthdayTodayTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->ClientBirthdayTodayTablePanel->Controls->Add(this->ClientBirthdayTodayLabel, 0, 0);
            this->ClientBirthdayTodayTablePanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->ClientBirthdayTodayTablePanel->Location = System::Drawing::Point(111, 603);
            this->ClientBirthdayTodayTablePanel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->ClientBirthdayTodayTablePanel->Name = L"ClientBirthdayTodayTablePanel";
            this->ClientBirthdayTodayTablePanel->RowCount = 2;
            this->ClientBirthdayTodayTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->ClientBirthdayTodayTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Absolute,
                20)));
            this->ClientBirthdayTodayTablePanel->Size = System::Drawing::Size(250, 39);
            this->ClientBirthdayTodayTablePanel->TabIndex = 16;
            // 
            // ClientBirthdayTodayLabel
            // 
            this->ClientBirthdayTodayLabel->AutoSize = true;
            this->ClientBirthdayTodayLabel->Dock = System::Windows::Forms::DockStyle::Top;
            this->ClientBirthdayTodayLabel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ClientBirthdayTodayLabel->Location = System::Drawing::Point(0, 0);
            this->ClientBirthdayTodayLabel->Margin = System::Windows::Forms::Padding(0, 0, 0, 3);
            this->ClientBirthdayTodayLabel->Name = L"ClientBirthdayTodayLabel";
            this->ClientBirthdayTodayLabel->Size = System::Drawing::Size(250, 16);
            this->ClientBirthdayTodayLabel->TabIndex = 0;
            this->ClientBirthdayTodayLabel->Text = L"Anniversaire aujourd\'hui";
            // 
            // CommercialStockValue
            // 
            this->FormLayoutPanel->SetColumnSpan(this->CommercialStockValue, 3);
            this->CommercialStockValue->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CommercialStockValue->LabelText = L"Valeur commerciale du stock";
            this->CommercialStockValue->Location = System::Drawing::Point(111, 0);
            this->CommercialStockValue->Margin = System::Windows::Forms::Padding(0);
            this->CommercialStockValue->Name = L"CommercialStockValue";
            this->CommercialStockValue->Size = System::Drawing::Size(520, 50);
            this->CommercialStockValue->TabIndex = 0;
            // 
            // CommercialStockValueLabel
            // 
            this->CommercialStockValueLabel->AutoSize = true;
            this->FormLayoutPanel->SetColumnSpan(this->CommercialStockValueLabel, 3);
            this->CommercialStockValueLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CommercialStockValueLabel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->CommercialStockValueLabel->Location = System::Drawing::Point(111, 55);
            this->CommercialStockValueLabel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->CommercialStockValueLabel->Name = L"CommercialStockValueLabel";
            this->CommercialStockValueLabel->Size = System::Drawing::Size(520, 16);
            this->CommercialStockValueLabel->TabIndex = 1;
            this->CommercialStockValueLabel->Text = L"Valeur commerciale";
            this->CommercialStockValueLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // ArticlesSellsSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->ArticlesSellsSeparator, 3);
            this->ArticlesSellsSeparator->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ArticlesSellsSeparator->LabelText = L"Meilleures et pires ventes";
            this->ArticlesSellsSeparator->Location = System::Drawing::Point(111, 81);
            this->ArticlesSellsSeparator->Margin = System::Windows::Forms::Padding(0);
            this->ArticlesSellsSeparator->Name = L"ArticlesSellsSeparator";
            this->ArticlesSellsSeparator->Size = System::Drawing::Size(520, 50);
            this->ArticlesSellsSeparator->TabIndex = 2;
            // 
            // BestArticlesLayoutPanel
            // 
            this->BestArticlesLayoutPanel->AutoSize = true;
            this->BestArticlesLayoutPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->BestArticlesLayoutPanel->ColumnCount = 1;
            this->BestArticlesLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->BestArticlesLayoutPanel->Controls->Add(this->BestArticlesHeader, 0, 0);
            this->BestArticlesLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->BestArticlesLayoutPanel->Location = System::Drawing::Point(111, 136);
            this->BestArticlesLayoutPanel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->BestArticlesLayoutPanel->Name = L"BestArticlesLayoutPanel";
            this->BestArticlesLayoutPanel->RowCount = 1;
            this->BestArticlesLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->BestArticlesLayoutPanel->Size = System::Drawing::Size(250, 21);
            this->BestArticlesLayoutPanel->TabIndex = 3;
            // 
            // BestArticlesHeader
            // 
            this->BestArticlesHeader->AutoSize = true;
            this->BestArticlesHeader->Dock = System::Windows::Forms::DockStyle::Top;
            this->BestArticlesHeader->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BestArticlesHeader->Location = System::Drawing::Point(0, 0);
            this->BestArticlesHeader->Margin = System::Windows::Forms::Padding(0, 0, 0, 5);
            this->BestArticlesHeader->Name = L"BestArticlesHeader";
            this->BestArticlesHeader->Size = System::Drawing::Size(250, 16);
            this->BestArticlesHeader->TabIndex = 0;
            this->BestArticlesHeader->Text = L"Meilleurs articles";
            // 
            // WorstArticlesLayoutPanel
            // 
            this->WorstArticlesLayoutPanel->AutoSize = true;
            this->WorstArticlesLayoutPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->WorstArticlesLayoutPanel->ColumnCount = 1;
            this->WorstArticlesLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->WorstArticlesLayoutPanel->Controls->Add(this->WorstArticlesHeader, 0, 0);
            this->WorstArticlesLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->WorstArticlesLayoutPanel->Location = System::Drawing::Point(381, 136);
            this->WorstArticlesLayoutPanel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->WorstArticlesLayoutPanel->Name = L"WorstArticlesLayoutPanel";
            this->WorstArticlesLayoutPanel->RowCount = 1;
            this->WorstArticlesLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->WorstArticlesLayoutPanel->Size = System::Drawing::Size(250, 21);
            this->WorstArticlesLayoutPanel->TabIndex = 3;
            // 
            // WorstArticlesHeader
            // 
            this->WorstArticlesHeader->AutoSize = true;
            this->WorstArticlesHeader->Dock = System::Windows::Forms::DockStyle::Top;
            this->WorstArticlesHeader->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->WorstArticlesHeader->Location = System::Drawing::Point(0, 0);
            this->WorstArticlesHeader->Margin = System::Windows::Forms::Padding(0, 0, 0, 5);
            this->WorstArticlesHeader->Name = L"WorstArticlesHeader";
            this->WorstArticlesHeader->Size = System::Drawing::Size(250, 16);
            this->WorstArticlesHeader->TabIndex = 0;
            this->WorstArticlesHeader->Text = L"Pires articles";
            // 
            // ClientExpenseSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->ClientExpenseSeparator, 3);
            this->ClientExpenseSeparator->Dock = System::Windows::Forms::DockStyle::Top;
            this->ClientExpenseSeparator->LabelText = L"Dépense d\'un client";
            this->ClientExpenseSeparator->Location = System::Drawing::Point(111, 167);
            this->ClientExpenseSeparator->Margin = System::Windows::Forms::Padding(0);
            this->ClientExpenseSeparator->Name = L"ClientExpenseSeparator";
            this->ClientExpenseSeparator->Size = System::Drawing::Size(520, 50);
            this->ClientExpenseSeparator->TabIndex = 4;
            // 
            // ClientExpenseSelect
            // 
            this->ClientExpenseSelect->LabelText = L"Client";
            this->ClientExpenseSelect->Location = System::Drawing::Point(111, 217);
            this->ClientExpenseSelect->Margin = System::Windows::Forms::Padding(0);
            this->ClientExpenseSelect->Name = L"ClientExpenseSelect";
            this->ClientExpenseSelect->SelectedIndex = -1;
            this->ClientExpenseSelect->Size = System::Drawing::Size(250, 50);
            this->ClientExpenseSelect->TabIndex = 5;
            this->ClientExpenseSelect->SelectionChanged += gcnew System::EventHandler<System::Object^>(
                this, &StatisticsView::ClientExpenseSelect_SelectionChanged);
            // 
            // ClientExpensesLabel
            // 
            this->ClientExpensesLabel->AutoSize = true;
            this->ClientExpensesLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ClientExpensesLabel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ClientExpensesLabel->Location = System::Drawing::Point(381, 237);
            this->ClientExpensesLabel->Margin = System::Windows::Forms::Padding(0, 20, 0, 0);
            this->ClientExpensesLabel->Name = L"ClientExpensesLabel";
            this->ClientExpensesLabel->Size = System::Drawing::Size(250, 30);
            this->ClientExpensesLabel->TabIndex = 6;
            this->ClientExpensesLabel->Text = L"Veuillez sélectionner un client";
            this->ClientExpensesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // MonthTurnoverSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->MonthTurnoverSeparator, 3);
            this->MonthTurnoverSeparator->Dock = System::Windows::Forms::DockStyle::Top;
            this->MonthTurnoverSeparator->LabelText = L"Chiffre d\'affaire d\'un mois";
            this->MonthTurnoverSeparator->Location = System::Drawing::Point(111, 267);
            this->MonthTurnoverSeparator->Margin = System::Windows::Forms::Padding(0);
            this->MonthTurnoverSeparator->Name = L"MonthTurnoverSeparator";
            this->MonthTurnoverSeparator->Size = System::Drawing::Size(520, 50);
            this->MonthTurnoverSeparator->TabIndex = 7;
            // 
            // MonthTurnoverDateField
            // 
            this->MonthTurnoverDateField->Dock = System::Windows::Forms::DockStyle::Top;
            this->MonthTurnoverDateField->HideDay = true;
            this->MonthTurnoverDateField->LabelText = L"Mois";
            this->MonthTurnoverDateField->Location = System::Drawing::Point(111, 317);
            this->MonthTurnoverDateField->Margin = System::Windows::Forms::Padding(0);
            this->MonthTurnoverDateField->Name = L"MonthTurnoverDateField";
            this->MonthTurnoverDateField->Size = System::Drawing::Size(250, 50);
            this->MonthTurnoverDateField->TabIndex = 8;
            this->MonthTurnoverDateField->Value = System::DateTime(2022, 12, 7, 0, 37, 26, 295);
            this->MonthTurnoverDateField->DateChanged += gcnew System::EventHandler(
                this, &StatisticsView::MonthTurnoverDateField_DateChanged);
            // 
            // MonthTurnoverLabel
            // 
            this->MonthTurnoverLabel->AutoSize = true;
            this->MonthTurnoverLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MonthTurnoverLabel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->MonthTurnoverLabel->Location = System::Drawing::Point(381, 337);
            this->MonthTurnoverLabel->Margin = System::Windows::Forms::Padding(0, 20, 0, 0);
            this->MonthTurnoverLabel->Name = L"MonthTurnoverLabel";
            this->MonthTurnoverLabel->Size = System::Drawing::Size(250, 30);
            this->MonthTurnoverLabel->TabIndex = 9;
            this->MonthTurnoverLabel->Text = L"Veuillez sélectionner un mois";
            this->MonthTurnoverLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // AverageCartSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->AverageCartSeparator, 3);
            this->AverageCartSeparator->Dock = System::Windows::Forms::DockStyle::Top;
            this->AverageCartSeparator->LabelText = L"Valeur moyen des paniers";
            this->AverageCartSeparator->Location = System::Drawing::Point(111, 367);
            this->AverageCartSeparator->Margin = System::Windows::Forms::Padding(0);
            this->AverageCartSeparator->Name = L"AverageCartSeparator";
            this->AverageCartSeparator->Size = System::Drawing::Size(520, 50);
            this->AverageCartSeparator->TabIndex = 10;
            // 
            // AverageCardLabel
            // 
            this->AverageCardLabel->AutoSize = true;
            this->FormLayoutPanel->SetColumnSpan(this->AverageCardLabel, 3);
            this->AverageCardLabel->Dock = System::Windows::Forms::DockStyle::Top;
            this->AverageCardLabel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->AverageCardLabel->Location = System::Drawing::Point(111, 422);
            this->AverageCardLabel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->AverageCardLabel->Name = L"AverageCardLabel";
            this->AverageCardLabel->Size = System::Drawing::Size(520, 16);
            this->AverageCardLabel->TabIndex = 11;
            this->AverageCardLabel->Text = L"Valeur moyen des paniers";
            // 
            // ProductRestockSeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->ProductRestockSeparator, 3);
            this->ProductRestockSeparator->Dock = System::Windows::Forms::DockStyle::Top;
            this->ProductRestockSeparator->LabelText = L"Produits à restocker";
            this->ProductRestockSeparator->Location = System::Drawing::Point(111, 448);
            this->ProductRestockSeparator->Margin = System::Windows::Forms::Padding(0);
            this->ProductRestockSeparator->Name = L"ProductRestockSeparator";
            this->ProductRestockSeparator->Size = System::Drawing::Size(520, 50);
            this->ProductRestockSeparator->TabIndex = 12;
            // 
            // ProductRestockField
            // 
            this->ProductRestockField->Dock = System::Windows::Forms::DockStyle::Top;
            this->ProductRestockField->Hidden = false;
            this->ProductRestockField->LabelText = L"Seuil de stock";
            this->ProductRestockField->Location = System::Drawing::Point(111, 498);
            this->ProductRestockField->Margin = System::Windows::Forms::Padding(0);
            this->ProductRestockField->Mode = TextFieldMode::Integer;
            this->ProductRestockField->Name = L"ProductRestockField";
            this->ProductRestockField->Size = System::Drawing::Size(250, 50);
            this->ProductRestockField->TabIndex = 13;
            this->ProductRestockField->Value = L"5";
            this->ProductRestockField->Submit += gcnew System::EventHandler(
                this, &StatisticsView::ProductRestockField_Submit);
            this->ProductRestockField->Leave += gcnew System::EventHandler(
                this, &StatisticsView::ProductRestockField_Leave);
            // 
            // ProductRestockTableLayoutPanel
            // 
            this->ProductRestockTableLayoutPanel->AutoSize = true;
            this->ProductRestockTableLayoutPanel->ColumnCount = 1;
            this->ProductRestockTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->ProductRestockTableLayoutPanel->Controls->Add(this->ProductsRestockPanel, 0, 1);
            this->ProductRestockTableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->ProductRestockTableLayoutPanel->Location = System::Drawing::Point(381, 503);
            this->ProductRestockTableLayoutPanel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->ProductRestockTableLayoutPanel->Name = L"ProductRestockTableLayoutPanel";
            this->ProductRestockTableLayoutPanel->RowCount = 2;
            this->ProductRestockTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->ProductRestockTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Absolute,
                20)));
            this->ProductRestockTableLayoutPanel->Size = System::Drawing::Size(250, 20);
            this->ProductRestockTableLayoutPanel->TabIndex = 14;
            // 
            // ProductsRestockPanel
            // 
            this->ProductsRestockPanel->AutoSize = true;
            this->ProductsRestockPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->ProductsRestockPanel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ProductsRestockPanel->Location = System::Drawing::Point(0, 0);
            this->ProductsRestockPanel->Margin = System::Windows::Forms::Padding(0, 0, 0, 3);
            this->ProductsRestockPanel->Name = L"ProductsRestockPanel";
            this->ProductsRestockPanel->Size = System::Drawing::Size(250, 16);
            this->ProductsRestockPanel->TabIndex = 0;
            this->ProductsRestockPanel->Text = L"Produits à restocker";
            // 
            // ClientBirthdaySeparator
            // 
            this->FormLayoutPanel->SetColumnSpan(this->ClientBirthdaySeparator, 3);
            this->ClientBirthdaySeparator->Dock = System::Windows::Forms::DockStyle::Top;
            this->ClientBirthdaySeparator->LabelText = L"Anniversaire des clients";
            this->ClientBirthdaySeparator->Location = System::Drawing::Point(111, 548);
            this->ClientBirthdaySeparator->Margin = System::Windows::Forms::Padding(0);
            this->ClientBirthdaySeparator->Name = L"ClientBirthdaySeparator";
            this->ClientBirthdaySeparator->Size = System::Drawing::Size(520, 50);
            this->ClientBirthdaySeparator->TabIndex = 15;
            // 
            // ClientFutureBirthdayTableLayoutPanel
            // 
            this->ClientFutureBirthdayTableLayoutPanel->AutoSize = true;
            this->ClientFutureBirthdayTableLayoutPanel->ColumnCount = 1;
            this->ClientFutureBirthdayTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->ClientFutureBirthdayTableLayoutPanel->Controls->Add(this->ClientFutureBirthdayLabel, 0, 0);
            this->ClientFutureBirthdayTableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->ClientFutureBirthdayTableLayoutPanel->Location = System::Drawing::Point(381, 603);
            this->ClientFutureBirthdayTableLayoutPanel->Margin = System::Windows::Forms::Padding(0, 5, 0, 10);
            this->ClientFutureBirthdayTableLayoutPanel->Name = L"ClientFutureBirthdayTableLayoutPanel";
            this->ClientFutureBirthdayTableLayoutPanel->RowCount = 2;
            this->ClientFutureBirthdayTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->ClientFutureBirthdayTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
                System::Windows::Forms::SizeType::Absolute,
                20)));
            this->ClientFutureBirthdayTableLayoutPanel->Size = System::Drawing::Size(250, 39);
            this->ClientFutureBirthdayTableLayoutPanel->TabIndex = 17;
            // 
            // ClientFutureBirthdayLabel
            // 
            this->ClientFutureBirthdayLabel->AutoSize = true;
            this->ClientFutureBirthdayLabel->Dock = System::Windows::Forms::DockStyle::Top;
            this->ClientFutureBirthdayLabel->Font = (gcnew System::Drawing::Font(
                L"Arial", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ClientFutureBirthdayLabel->Location = System::Drawing::Point(0, 0);
            this->ClientFutureBirthdayLabel->Margin = System::Windows::Forms::Padding(0, 0, 0, 3);
            this->ClientFutureBirthdayLabel->Name = L"ClientFutureBirthdayLabel";
            this->ClientFutureBirthdayLabel->Size = System::Drawing::Size(250, 16);
            this->ClientFutureBirthdayLabel->TabIndex = 0;
            this->ClientFutureBirthdayLabel->Text = L"Anniversaire dans 15 jours";
            // 
            // StatisticsView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Margin = System::Windows::Forms::Padding(0);
            this->Name = L"StatisticsView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->HeaderLayoutPanel->ResumeLayout(false);
            this->HeaderLayoutPanel->PerformLayout();
            this->FormScrollPanel->ResumeLayout(false);
            this->FormScrollPanel->PerformLayout();
            this->FormLayoutPanel->ResumeLayout(false);
            this->FormLayoutPanel->PerformLayout();
            this->ClientBirthdayTodayTablePanel->ResumeLayout(false);
            this->ClientBirthdayTodayTablePanel->PerformLayout();
            this->BestArticlesLayoutPanel->ResumeLayout(false);
            this->BestArticlesLayoutPanel->PerformLayout();
            this->WorstArticlesLayoutPanel->ResumeLayout(false);
            this->WorstArticlesLayoutPanel->PerformLayout();
            this->ProductRestockTableLayoutPanel->ResumeLayout(false);
            this->ProductRestockTableLayoutPanel->PerformLayout();
            this->ClientFutureBirthdayTableLayoutPanel->ResumeLayout(false);
            this->ClientFutureBirthdayTableLayoutPanel->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void RefreshBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->LoadData();
        }

        System::Void ClientExpenseSelect_SelectionChanged(System::Object^ sender, System::Object^ e)
        {
            auto client = safe_cast<Entities::ClientEntity^>(ClientExpenseSelect->SelectedItem);
            auto expenses = statisticService->GetTotalSpentPerClient(client);
            ClientExpensesLabel->Text = "Dépenses : " + expenses.ToString("C");
        }

        System::Void MonthTurnoverDateField_DateChanged(System::Object^ sender, System::EventArgs^ e)
        {
            auto date = MonthTurnoverDateField->Value;
            auto turnover = statisticService->GetTurnoverPerMonth(date);
            MonthTurnoverLabel->Text = "Chiffre d'affaire : " + turnover.ToString("C");
        }

        System::Void ProductRestockField_Leave(System::Object^ sender, System::EventArgs^ e)
        {
            this->RefreshProductRestock();
        }

        System::Void ProductRestockField_Submit(System::Object^ sender, System::EventArgs^ e)
        {
            this->RefreshProductRestock();
        }

        void RefreshProductRestock()
        {
            auto threshold = Convert::ToInt32(ProductRestockField->Value);
            auto products = statisticService->GetProductToRestock(threshold);

            for (int i = ProductRestockTableLayoutPanel->Controls->Count - 1; i >= 1; i--)
            {
                auto control = ProductRestockTableLayoutPanel->Controls[i];
                ProductRestockTableLayoutPanel->Controls->Remove(control);
                ProductRestockTableLayoutPanel->RowStyles->RemoveAt(i);
                ProductRestockTableLayoutPanel->RowCount--;
                delete control;
            }

            for each (auto product in products)
            {
                auto label = gcnew Label();
                label->AutoSize = true;
                label->Text = "- " + product->GetName();
                label->Dock = DockStyle::Top;
                label->Margin = System::Windows::Forms::Padding(0, 2, 0, 0);
                ProductRestockTableLayoutPanel->RowCount++;
                ProductRestockTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
                ProductRestockTableLayoutPanel->Controls->Add(label, 0, ProductRestockTableLayoutPanel->RowCount - 1);
            }
        }

    public:
        void LoadData()
        {
            this->FormLayoutPanel->SuspendLayout();
            this->FormScrollPanel->SuspendLayout();
            this->BestArticlesLayoutPanel->SuspendLayout();
            this->WorstArticlesLayoutPanel->SuspendLayout();

            auto commercialStockValue = statisticService->GetCommercialStockValue();
            CommercialStockValueLabel->Text = "Valeur commerciale : " + commercialStockValue.ToString("C");

            auto bestSellingArticles = statisticService->GetBestSellingArticles();
            // Remove previous added rows
            for (int i = BestArticlesLayoutPanel->Controls->Count - 1; i >= 1; i--)
            {
                auto control = BestArticlesLayoutPanel->Controls[i];
                BestArticlesLayoutPanel->Controls->Remove(control);
                BestArticlesLayoutPanel->RowStyles->RemoveAt(i);
                BestArticlesLayoutPanel->RowCount--;
                delete control;
            }
            // Add new rows
            for (int i = 0; i < bestSellingArticles->Length; i++)
            {
                auto article = bestSellingArticles[i];
                auto label = gcnew System::Windows::Forms::Label();
                label->AutoSize = true;
                label->Dock = System::Windows::Forms::DockStyle::Top;
                label->Text = "#" + (i + 1) + " - " + article->GetName();
                BestArticlesLayoutPanel->RowCount++;
                BestArticlesLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
                BestArticlesLayoutPanel->Controls->Add(label, 0, i + 1);
            }

            auto worstSellingArticles = statisticService->GetWorstSellingArticles();
            // Remove previous added rows
            for (int i = WorstArticlesLayoutPanel->Controls->Count - 1; i >= 1; i--)
            {
                auto control = WorstArticlesLayoutPanel->Controls[i];
                WorstArticlesLayoutPanel->Controls->Remove(control);
                WorstArticlesLayoutPanel->RowStyles->RemoveAt(i);
                WorstArticlesLayoutPanel->RowCount--;
                delete control;
            }
            // Add new rows
            for (int i = 0; i < worstSellingArticles->Length; i++)
            {
                auto article = worstSellingArticles[i];
                auto label = gcnew System::Windows::Forms::Label();
                label->AutoSize = true;
                label->Dock = System::Windows::Forms::DockStyle::Top;
                label->Text = "#" + (i + 1) + " - " + article->GetName();
                WorstArticlesLayoutPanel->RowCount++;
                WorstArticlesLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
                WorstArticlesLayoutPanel->Controls->Add(label, 0, i + 1);
            }

            auto clientTable = clientService->GetClients();
            auto clients = gcnew array<Entities::ClientEntity^>(clientTable->Rows->Count);
            auto clientsSelection = gcnew array<Tuple<Object^, String^>^>(clients->Length);
            for (int i = 0; i < clientTable->Rows->Count; i++)
            {
                clients[i] = gcnew Entities::ClientEntity(clientTable->Rows[i]);
                clientsSelection[i] = gcnew Tuple<Object^, String^>(
                    clients[i],
                    clients[i]->GetLastname() + " " + clients[i]->GetFirstname());
            }
            ClientExpenseSelect->Items = clientsSelection;
            ClientExpenseSelect->SelectedIndex = -1;
            ClientExpensesLabel->Text = "Veuillez sélectionner un client";

            MonthTurnoverDateField->Value = DateTime::Now;
            MonthTurnoverDateField_DateChanged(this, gcnew EventArgs());

            auto averageCartValue = statisticService->GetAverageShoppingCartValue();
            AverageCardLabel->Text = "Valeur moyen des paniers : " + averageCartValue.ToString("C");

            RefreshProductRestock();

            auto todayBirthdayClients = statisticService->GetBirthdayClients();
            // Remove previous added rows
            for (int i = ClientBirthdayTodayTablePanel->Controls->Count - 1; i >= 1; i--)
            {
                auto control = ClientBirthdayTodayTablePanel->Controls[i];
                ClientBirthdayTodayTablePanel->Controls->Remove(control);
                ClientBirthdayTodayTablePanel->RowStyles->RemoveAt(i);
                ClientBirthdayTodayTablePanel->RowCount--;
                delete control;
            }
            // Add new rows
            for (int i = 0; i < todayBirthdayClients->Length; i++)
            {
                auto client = todayBirthdayClients[i];
                auto label = gcnew System::Windows::Forms::Label();
                label->AutoSize = true;
                label->Dock = System::Windows::Forms::DockStyle::Top;
                label->Text = "- " + client->GetFirstname() + " " + client->GetLastname();
                label->Margin = System::Windows::Forms::Padding(0, 2, 0, 0);
                ClientBirthdayTodayTablePanel->RowCount++;
                ClientBirthdayTodayTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
                ClientBirthdayTodayTablePanel->Controls->Add(label, 0, i + 1);
            }

            auto futureBirthdayClients = statisticService->GetFutureBirthdayClients();
            // Remove previous added rows
            for (int i = ClientFutureBirthdayTableLayoutPanel->Controls->Count - 1; i >= 1; i--)
            {
                auto control = ClientFutureBirthdayTableLayoutPanel->Controls[i];
                ClientFutureBirthdayTableLayoutPanel->Controls->Remove(control);
                ClientFutureBirthdayTableLayoutPanel->RowStyles->RemoveAt(i);
                ClientFutureBirthdayTableLayoutPanel->RowCount--;
                delete control;
            }
            // Add new rows
            for (int i = 0; i < futureBirthdayClients->Length; i++)
            {
                auto client = futureBirthdayClients[i];
                auto label = gcnew System::Windows::Forms::Label();
                label->AutoSize = true;
                label->Dock = System::Windows::Forms::DockStyle::Top;
                label->Text = "- " + client->GetFirstname() + " " + client->GetLastname();
                label->Margin = System::Windows::Forms::Padding(0, 2, 0, 0);
                ClientFutureBirthdayTableLayoutPanel->RowCount++;
                ClientFutureBirthdayTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
                ClientFutureBirthdayTableLayoutPanel->Controls->Add(label, 0, i + 1);
            }

            this->FormLayoutPanel->ResumeLayout();
            this->FormScrollPanel->ResumeLayout();
            this->BestArticlesLayoutPanel->ResumeLayout();
            this->WorstArticlesLayoutPanel->ResumeLayout();
        }
    };
}
