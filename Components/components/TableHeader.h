#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class TableHeader : public System::Windows::Forms::UserControl
    {
    public:
        TableHeader(void)
        {
            InitializeComponent();
        }

    protected:
        ~TableHeader()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        property String^ Label
        {
            String^ get()
            {
                return Title->Text;
            }

            void set(String^ value)
            {
                Title->Text = value;
            }
        }

        event EventHandler^ RefreshClick;
        event EventHandler^ AddClick;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ CreateBtn;
        System::Windows::Forms::Label^ RefreshBtn;
        System::Windows::Forms::Label^ Title;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->CreateBtn = (gcnew System::Windows::Forms::Label());
            this->RefreshBtn = (gcnew System::Windows::Forms::Label());
            this->Title = (gcnew System::Windows::Forms::Label());
            this->TableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 3;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->TableLayoutPanel->Controls->Add(this->Title, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->CreateBtn, 1, 0);
            this->TableLayoutPanel->Controls->Add(this->RefreshBtn, 2, 0);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 1;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayoutPanel->Size = System::Drawing::Size(800, 40);
            this->TableLayoutPanel->TabIndex = 0;
            // 
            // CreateBtn
            // 
            this->CreateBtn->AutoSize = true;
            this->CreateBtn->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(173)));
            this->CreateBtn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->CreateBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CreateBtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                 System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
            this->CreateBtn->ForeColor = System::Drawing::Color::White;
            this->CreateBtn->Location = System::Drawing::Point(477, 0);
            this->CreateBtn->Margin = System::Windows::Forms::Padding(0);
            this->CreateBtn->Name = L"CreateBtn";
            this->CreateBtn->Padding = System::Windows::Forms::Padding(50, 0, 50, 0);
            this->CreateBtn->Size = System::Drawing::Size(148, 40);
            this->CreateBtn->TabIndex = 0;
            this->CreateBtn->Text = L"Créer";
            this->CreateBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->CreateBtn->Click += gcnew System::EventHandler(this, &TableHeader::CreateBtn_Click);
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
            this->RefreshBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->RefreshBtn->Click += gcnew System::EventHandler(this, &TableHeader::RefreshBtn_Click);
            // 
            // Title
            // 
            this->Title->AutoSize = true;
            this->Title->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(4)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->Title->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Title->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                             System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Title->ForeColor = System::Drawing::Color::White;
            this->Title->Location = System::Drawing::Point(0, 0);
            this->Title->Margin = System::Windows::Forms::Padding(0);
            this->Title->Name = L"Title";
            this->Title->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
            this->Title->Size = System::Drawing::Size(477, 40);
            this->Title->TabIndex = 2;
            this->Title->Text = L"Table";
            this->Title->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // TableHeader
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Margin = System::Windows::Forms::Padding(0);
            this->Name = L"TableHeader";
            this->Size = System::Drawing::Size(800, 40);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void CreateBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            AddClick(this, e);
        }

        System::Void RefreshBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            RefreshClick(this, e);
        }
    };
}
