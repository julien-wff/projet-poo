#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class FormSeparator : public System::Windows::Forms::UserControl
    {
    public:
        FormSeparator(void)
        {
            InitializeComponent();
        }

    protected:
        ~FormSeparator()
        {
            if (components)
            {
                delete components;
            }
        }

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

    private:
        System::Windows::Forms::Label^ Label;
    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->Label = (gcnew System::Windows::Forms::Label());
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->TableLayoutPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // Label
            // 
            this->Label->AutoSize = true;
            this->Label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Label->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                             System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Label->Location = System::Drawing::Point(0, 20);
            this->Label->Margin = System::Windows::Forms::Padding(0);
            this->Label->Name = L"Label";
            this->Label->Padding = System::Windows::Forms::Padding(0, 0, 0, 5);
            this->Label->Size = System::Drawing::Size(500, 23);
            this->Label->TabIndex = 0;
            this->Label->Text = L"Séparateur";
            this->Label->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormSeparator::Label_Paint);
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->Label, 0, 1);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 3;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->TableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 10)));
            this->TableLayoutPanel->Size = System::Drawing::Size(500, 50);
            this->TableLayoutPanel->TabIndex = 1;
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
            // 
            // FormSeparator
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"FormSeparator";
            this->Size = System::Drawing::Size(500, 50);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void Label_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->DrawLine(System::Drawing::Pens::Black, 0, this->Label->Height - 1, this->Label->Width,
                                  this->Label->Height - 1);
        }
    };
}
