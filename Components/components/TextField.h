#pragma once
#include "../enums/TextFieldMode.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class TextField : public System::Windows::Forms::UserControl
    {
    public:
        TextField(void)
        {
            InitializeComponent();
        }

    protected:
        ~TextField()
        {
            if (components)
            {
                delete components;
            }
        }

        TextFieldMode _mode;

    public:
        property String^ LabelText
        {
            String^ get()
            {
                return Label->Text;
            }

            void set(String^ value)
            {
                Label->Text = value;
            }
        }

        property String^ Value
        {
            String^ get()
            {
                return TextBox->Text;
            }

            void set(String^ value)
            {
                TextBox->Text = value;
            }
        }

        property TextFieldMode Mode
        {
            TextFieldMode get()
            {
                return _mode;
            }

            void set(TextFieldMode value)
            {
                _mode = value;
            }
        }

        property bool Hidden
        {
            bool get()
            {
                return TextBox->UseSystemPasswordChar;
            }

            void set(bool value)
            {
                TextBox->UseSystemPasswordChar = value;
            }
        }

        event EventHandler^ TextChanged;
        event EventHandler^ Leave;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ Label;
        System::Windows::Forms::Panel^ TextBoxContainer;
        System::Windows::Forms::TextBox^ TextBox;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Label = (gcnew System::Windows::Forms::Label());
            this->TextBoxContainer = (gcnew System::Windows::Forms::Panel());
            this->TextBox = (gcnew System::Windows::Forms::TextBox());
            this->TableLayoutPanel->SuspendLayout();
            this->TextBoxContainer->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->Label, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->TextBoxContainer, 0, 1);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 2;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->TableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->TableLayoutPanel->Size = System::Drawing::Size(250, 60);
            this->TableLayoutPanel->TabIndex = 0;
            // 
            // Label
            // 
            this->Label->AutoSize = true;
            this->Label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular,
                                                             System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Label->Location = System::Drawing::Point(0, 0);
            this->Label->Margin = System::Windows::Forms::Padding(0);
            this->Label->Name = L"Label";
            this->Label->Size = System::Drawing::Size(250, 20);
            this->Label->TabIndex = 0;
            this->Label->Text = L"Label";
            this->Label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // TextBoxContainer
            // 
            this->TextBoxContainer->AutoSize = true;
            this->TextBoxContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->TextBoxContainer->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->TextBoxContainer->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TextBoxContainer->Controls->Add(this->TextBox);
            this->TextBoxContainer->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->TextBoxContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TextBoxContainer->Location = System::Drawing::Point(3, 20);
            this->TextBoxContainer->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
            this->TextBoxContainer->Name = L"TextBoxContainer";
            this->TextBoxContainer->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
            this->TextBoxContainer->Size = System::Drawing::Size(244, 40);
            this->TextBoxContainer->TabIndex = 1;
            this->TextBoxContainer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(
                this, &TextField::TextBoxContainer_MouseDown);
            this->TextBoxContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &TextField::TextBoxContainer_Paint);
            // 
            // TextBox
            // 
            this->TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TextBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TextBox->Location = System::Drawing::Point(12, 10);
            this->TextBox->Name = L"TextBox";
            this->TextBox->Size = System::Drawing::Size(218, 13);
            this->TextBox->TabIndex = 0;
            this->TextBox->TextChanged += gcnew System::EventHandler(this, &TextField::TextBox_TextChanged);
            this->TextBox->Leave += gcnew System::EventHandler(this, &TextField::TextBox_Leave);
            this->TextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(
                this, &TextField::TextBox_KeyPress);
            // 
            // TextField
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"TextField";
            this->Size = System::Drawing::Size(250, 60);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            this->TextBoxContainer->ResumeLayout(false);
            this->TextBoxContainer->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

        Void TextBoxContainer_MouseDown(Object^ sender, MouseEventArgs^ e)
        {
            TextBox->Focus();
        }

        Void TextBoxContainer_Paint(Object^ sender, PaintEventArgs^ e)
        {
            // Bottom border
            e->Graphics->DrawLine(Pens::LightGray,
                                  0, TextBoxContainer->Height - 1,
                                  TextBoxContainer->Width, TextBoxContainer->Height - 1);
        }

        Void TextBox_TextChanged(Object^ sender, EventArgs^ e)
        {
            TextChanged(this, e);
        }

        Void TextBox_Leave(Object^ sender, EventArgs^ e)
        {
            Leave(this, e);
        }

        Void TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
        {
            if (_mode == TextFieldMode::Text)
                return;

            // Allow numbers and backspace
            if ((_mode == TextFieldMode::Integer || _mode == TextFieldMode::Decimal)
                && (Char::IsDigit(e->KeyChar) || e->KeyChar == '\b'))
                return;

            // If it's decimal and there is already a comma, don't allow another one
            if (_mode == TextFieldMode::Decimal && e->KeyChar == ',' && !TextBox->Text->Contains(","))
                return;

            e->Handled = true;
        }
    };
}
