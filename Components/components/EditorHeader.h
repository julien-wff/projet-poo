#pragma once
#include "../enums/EditorMode.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class EditorHeader : public System::Windows::Forms::UserControl
    {
    public:
        EditorHeader(void)
        {
            InitializeComponent();
        }

    protected:
        ~EditorHeader()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        EditorMode _CurrentEditorMode;

    public:
        event EventHandler^ CancelClick;
        event EventHandler^ CreateClick;
        event EventHandler^ DeleteClick;

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

        property EditorMode CurrentEditorMode
        {
            EditorMode get()
            {
                return _CurrentEditorMode;
            }

            void set(EditorMode mode)
            {
                if (mode == EditorMode::Create)
                {
                    this->TableLayoutPanel->Controls->Remove(this->DeleteBtn);
                    this->CreateBtn->Text = "Créer";
                }
                else
                {
                    this->TableLayoutPanel->Controls->Add(this->DeleteBtn, 3, 0);
                    this->CreateBtn->Text = "Sauvegarder";
                }

                this->_CurrentEditorMode = mode;
            }
        }


    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ CreateBtn;
        System::Windows::Forms::Label^ CancelBtn;
        System::Windows::Forms::Label^ DeleteBtn;
        System::Windows::Forms::Label^ Title;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->CreateBtn = (gcnew System::Windows::Forms::Label());
            this->CancelBtn = (gcnew System::Windows::Forms::Label());
            this->DeleteBtn = (gcnew System::Windows::Forms::Label());
            this->Title = (gcnew System::Windows::Forms::Label());
            this->TableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 4;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->TableLayoutPanel->Controls->Add(this->Title, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->CreateBtn, 1, 0);
            this->TableLayoutPanel->Controls->Add(this->CancelBtn, 2, 0);
            this->TableLayoutPanel->Controls->Add(this->DeleteBtn, 3, 0);
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
            this->CreateBtn->Click += gcnew System::EventHandler(this, &EditorHeader::CreateBtn_Click);
            // 
            // CancelBtn
            // 
            this->CancelBtn->AutoSize = true;
            this->CancelBtn->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(129)),
                static_cast<System::Int32>(static_cast<System::Byte>(56)));
            this->CancelBtn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->CancelBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CancelBtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                 System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
            this->CancelBtn->ForeColor = System::Drawing::Color::White;
            this->CancelBtn->Location = System::Drawing::Point(625, 0);
            this->CancelBtn->Margin = System::Windows::Forms::Padding(0);
            this->CancelBtn->Name = L"CancelBtn";
            this->CancelBtn->Padding = System::Windows::Forms::Padding(50, 0, 50, 0);
            this->CancelBtn->Size = System::Drawing::Size(175, 40);
            this->CancelBtn->TabIndex = 1;
            this->CancelBtn->Text = L"Annuler";
            this->CancelBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->CancelBtn->Click += gcnew System::EventHandler(this, &EditorHeader::CancelBtn_Click);
            // 
            // DeleteBtn
            // 
            this->DeleteBtn->AutoSize = true;
            this->DeleteBtn->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(191)),
                static_cast<System::Int32>(static_cast<System::Byte>(37)),
                static_cast<System::Int32>(static_cast<System::Byte>(37)));
            this->DeleteBtn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->DeleteBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DeleteBtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                 System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
            this->DeleteBtn->ForeColor = System::Drawing::Color::White;
            this->DeleteBtn->Location = System::Drawing::Point(625, 0);
            this->DeleteBtn->Margin = System::Windows::Forms::Padding(0);
            this->DeleteBtn->Name = L"CancelBtn";
            this->DeleteBtn->Padding = System::Windows::Forms::Padding(50, 0, 50, 0);
            this->DeleteBtn->Size = System::Drawing::Size(175, 40);
            this->DeleteBtn->TabIndex = 1;
            this->DeleteBtn->Text = L"Supprimer";
            this->DeleteBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->DeleteBtn->Click += gcnew System::EventHandler(this, &EditorHeader::DeleteBtn_Click);
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

        System::Void CreateBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->CreateClick(this, e);
        }

        System::Void CancelBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->CancelClick(this, e);
        }

        System::Void DeleteBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DeleteClick(this, e);
        }
#pragma endregion
    };
}
