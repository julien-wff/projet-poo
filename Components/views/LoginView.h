#pragma once

#include "../components/TextField.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class LoginView : public System::Windows::Forms::UserControl
    {
    public:
        LoginView(void)
        {
            InitializeComponent();
        }

    protected:
        ~LoginView()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        property String^ Username
        {
            String^ get()
            {
                return this->UserField->Value;
            }

            void set(String^ value)
            {
                this->UserField->Value = value;
            }
        }

        property String^ Password
        {
            String^ get()
            {
                return this->PasswordField->Value;
            }

            void set(String^ value)
            {
                this->PasswordField->Value = value;
            }
        }

        property bool Loading
        {
            bool get()
            {
                return this->Cursor == Cursors::WaitCursor;
            }

            void set(bool loading)
            {
                this->Cursor = loading ? Cursors::WaitCursor : Cursors::Default;
                this->LoginBtn->Cursor = loading ? Cursors::WaitCursor : Cursors::Hand;
                if (loading)
                    this->LoginBtn->BackColor = System::Drawing::Color::FromArgb(92, 109, 138);
                else
                    this->LoginBtn->BackColor = System::Drawing::Color::FromArgb(57, 99, 173);
            }
        }

        event EventHandler^ Submit;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ HeaderLabel;
        System::Windows::Forms::TableLayoutPanel^ FormLayoutPanel;
        Components::TextField^ UserField;
        Components::TextField^ PasswordField;
        System::Windows::Forms::PictureBox^ IconBox;
        System::Windows::Forms::Label^ LoginBtn;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew
                System::ComponentModel::ComponentResourceManager(LoginView::typeid));
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->HeaderLabel = (gcnew System::Windows::Forms::Label());
            this->FormLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->IconBox = (gcnew System::Windows::Forms::PictureBox());
            this->LoginBtn = (gcnew System::Windows::Forms::Label());
            this->UserField = (gcnew Components::TextField());
            this->PasswordField = (gcnew Components::TextField());
            this->TableLayoutPanel->SuspendLayout();
            this->FormLayoutPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IconBox))->BeginInit();
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
                350)));
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->TableLayoutPanel->Controls->Add(this->HeaderLabel, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->FormLayoutPanel, 1, 2);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 4;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->TableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->TableLayoutPanel->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->TabIndex = 0;
            // 
            // HeaderLabel
            // 
            this->HeaderLabel->AutoSize = true;
            this->HeaderLabel->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(4)),
                static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->TableLayoutPanel->SetColumnSpan(this->HeaderLabel, 3);
            this->HeaderLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->HeaderLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                   System::Drawing::GraphicsUnit::Point,
                                                                   static_cast<System::Byte>(0)));
            this->HeaderLabel->ForeColor = System::Drawing::Color::White;
            this->HeaderLabel->Location = System::Drawing::Point(0, 0);
            this->HeaderLabel->Margin = System::Windows::Forms::Padding(0);
            this->HeaderLabel->Name = L"HeaderLabel";
            this->HeaderLabel->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
            this->HeaderLabel->Size = System::Drawing::Size(800, 40);
            this->HeaderLabel->TabIndex = 0;
            this->HeaderLabel->Text = L"Connexion";
            this->HeaderLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // FormLayoutPanel
            // 
            this->FormLayoutPanel->AutoSize = true;
            this->FormLayoutPanel->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(219)),
                static_cast<System::Int32>(static_cast<System::Byte>(227)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->FormLayoutPanel->ColumnCount = 3;
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Absolute,
                40)));
            this->FormLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->FormLayoutPanel->Controls->Add(this->UserField, 0, 1);
            this->FormLayoutPanel->Controls->Add(this->PasswordField, 0, 2);
            this->FormLayoutPanel->Controls->Add(this->IconBox, 1, 0);
            this->FormLayoutPanel->Controls->Add(this->LoginBtn, 0, 4);
            this->FormLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->FormLayoutPanel->Location = System::Drawing::Point(225, 185);
            this->FormLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->FormLayoutPanel->Name = L"FormLayoutPanel";
            this->FormLayoutPanel->Padding = System::Windows::Forms::Padding(20);
            this->FormLayoutPanel->RowCount = 5;
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->FormLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->FormLayoutPanel->Size = System::Drawing::Size(350, 270);
            this->FormLayoutPanel->TabIndex = 1;
            // 
            // IconBox
            // 
            this->IconBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IconBox.Image")));
            this->IconBox->Location = System::Drawing::Point(155, 20);
            this->IconBox->Margin = System::Windows::Forms::Padding(0);
            this->IconBox->Name = L"IconBox";
            this->IconBox->Size = System::Drawing::Size(40, 40);
            this->IconBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->IconBox->TabIndex = 2;
            this->IconBox->TabStop = false;
            // 
            // LoginBtn
            // 
            this->LoginBtn->AutoSize = true;
            this->LoginBtn->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(173)));
            this->FormLayoutPanel->SetColumnSpan(this->LoginBtn, 3);
            this->LoginBtn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->LoginBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->LoginBtn->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                System::Drawing::GraphicsUnit::Point,
                                                                static_cast<System::Byte>(0)));
            this->LoginBtn->ForeColor = System::Drawing::Color::White;
            this->LoginBtn->Location = System::Drawing::Point(23, 210);
            this->LoginBtn->Name = L"LoginBtn";
            this->LoginBtn->Size = System::Drawing::Size(304, 40);
            this->LoginBtn->TabIndex = 3;
            this->LoginBtn->Text = L"Connexion";
            this->LoginBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->LoginBtn->Click += gcnew System::EventHandler(this, &LoginView::LoginBtn_Click);
            // 
            // UserField
            // 
            this->FormLayoutPanel->SetColumnSpan(this->UserField, 3);
            this->UserField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->UserField->LabelText = L"Nom d\'utilisateur";
            this->UserField->Location = System::Drawing::Point(20, 80);
            this->UserField->Margin = System::Windows::Forms::Padding(0);
            this->UserField->Mode = TextFieldMode::Text;
            this->UserField->Name = L"UserField";
            this->UserField->Size = System::Drawing::Size(310, 50);
            this->UserField->TabIndex = 0;
            this->UserField->Value = L"";
            // 
            // PasswordField
            // 
            this->FormLayoutPanel->SetColumnSpan(this->PasswordField, 3);
            this->PasswordField->Dock = System::Windows::Forms::DockStyle::Fill;
            this->PasswordField->LabelText = L"Mot de passe";
            this->PasswordField->Location = System::Drawing::Point(20, 140);
            this->PasswordField->Margin = System::Windows::Forms::Padding(0, 10, 0, 0);
            this->PasswordField->Mode = TextFieldMode::Text;
            this->PasswordField->Name = L"PasswordField";
            this->PasswordField->Size = System::Drawing::Size(310, 50);
            this->PasswordField->TabIndex = 1;
            this->PasswordField->Value = L"";
            this->PasswordField->Hidden = true;
            this->PasswordField->Submit += gcnew System::EventHandler(this, &LoginView::LoginBtn_Click);
            // 
            // LoginView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Margin = System::Windows::Forms::Padding(0);
            this->Name = L"LoginView";
            this->Size = System::Drawing::Size(800, 600);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            this->FormLayoutPanel->ResumeLayout(false);
            this->FormLayoutPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IconBox))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void LoginBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (this->Username->Trim()->Length == 0 || this->Password->Trim()->Length == 0)
            {
                MessageBox::Show(L"Veuillez entrer un nom d\'utilisateur et un mot de passe valide",
                                 L"Erreur",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Error);
                return;
            }

            Submit(this, e);
        }
    };
}
