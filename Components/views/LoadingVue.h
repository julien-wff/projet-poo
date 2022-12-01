#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class LoadingVue : public System::Windows::Forms::UserControl
    {
    public:
        LoadingVue(void)
        {
            InitializeComponent();
        }

    protected:
        ~LoadingVue()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        property String^ LoadingText
        {
            String^ get()
            {
                return this->LoadingLabel->Text;
            }

            void set(String^ value)
            {
                this->LoadingLabel->Text = value;
            }
        }

    private:
        System::Windows::Forms::Label^ LoadingLabel;
        System::Windows::Forms::TableLayoutPanel^ CenterLayoutPanel;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->LoadingLabel = (gcnew System::Windows::Forms::Label());
            this->CenterLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->CenterLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // LoadingLabel
            // 
            this->LoadingLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((
                        System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                    | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->LoadingLabel->AutoSize = true;
            this->LoadingLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                                    System::Drawing::GraphicsUnit::Point,
                                                                    static_cast<System::Byte>(0)));
            this->LoadingLabel->Location = System::Drawing::Point(347, 291);
            this->LoadingLabel->Name = L"LoadingLabel";
            this->LoadingLabel->Size = System::Drawing::Size(106, 18);
            this->LoadingLabel->TabIndex = 0;
            this->LoadingLabel->Text = L"Chargement...";
            this->LoadingLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // CenterLayoutPanel
            // 
            this->CenterLayoutPanel->ColumnCount = 3;
            this->CenterLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->CenterLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->CenterLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->CenterLayoutPanel->Controls->Add(this->LoadingLabel, 1, 1);
            this->CenterLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CenterLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->CenterLayoutPanel->Name = L"CenterLayoutPanel";
            this->CenterLayoutPanel->RowCount = 3;
            this->CenterLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->CenterLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->CenterLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->CenterLayoutPanel->Size = System::Drawing::Size(800, 600);
            this->CenterLayoutPanel->TabIndex = 1;
            // 
            // LoadingVue
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->CenterLayoutPanel);
            this->Name = L"LoadingVue";
            this->Size = System::Drawing::Size(800, 600);
            this->CenterLayoutPanel->ResumeLayout(false);
            this->CenterLayoutPanel->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion
    };
}
