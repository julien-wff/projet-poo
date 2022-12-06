#pragma once

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
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->HeaderLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->HeaderLabel = (gcnew System::Windows::Forms::Label());
            this->RefreshBtn = (gcnew System::Windows::Forms::Label());
            this->FormScrollPanel = (gcnew System::Windows::Forms::Panel());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->TableLayoutPanel->SuspendLayout();
            this->HeaderLayoutPanel->SuspendLayout();
            this->FormScrollPanel->SuspendLayout();
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
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(20, 20);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->RowCount = 2;
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->FormLayoutPanel->Size = System::Drawing::Size(760, 100);
            this->FormLayoutPanel->TabIndex = 0;
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
            this->ResumeLayout(false);
        }
#pragma endregion
    };
}
