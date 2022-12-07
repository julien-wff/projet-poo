#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class DateField : public System::Windows::Forms::UserControl
    {
    public:
        DateField(void)
        {
            InitializeComponent();
        }

    protected:
        ~DateField()
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

        property DateTime Value
        {
            DateTime get()
            {
                return DateTimePicker->Value;
            }

            void set(DateTime value)
            {
                DateTimePicker->Value = value;
            }
        }

        property bool HideDay
        {
            bool get()
            {
                return DateTimePicker->Format == DateTimePickerFormat::Custom;
            }

            void set(bool value)
            {
                if (value)
                {
                    this->DateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
                    this->DateTimePicker->CustomFormat = L"MMMM yyyy";
                }
                else
                {
                    this->DateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Long;
                }
            }
        }

        event EventHandler^ DateChanged;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ Label;
        System::Windows::Forms::Panel^ DateBoxContainer;
        System::Windows::Forms::DateTimePicker^ DateTimePicker;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Label = (gcnew System::Windows::Forms::Label());
            this->DateBoxContainer = (gcnew System::Windows::Forms::Panel());
            this->DateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->TableLayoutPanel->SuspendLayout();
            this->DateBoxContainer->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->Label, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->DateBoxContainer, 0, 1);
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
            // DateBoxContainer
            // 
            this->DateBoxContainer->AutoSize = true;
            this->DateBoxContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->DateBoxContainer->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->DateBoxContainer->Controls->Add(this->DateTimePicker);
            this->DateBoxContainer->Cursor = System::Windows::Forms::Cursors::Hand;
            this->DateBoxContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DateBoxContainer->Location = System::Drawing::Point(3, 20);
            this->DateBoxContainer->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
            this->DateBoxContainer->Name = L"DateBoxContainer";
            this->DateBoxContainer->Padding = System::Windows::Forms::Padding(6);
            this->DateBoxContainer->Size = System::Drawing::Size(244, 40);
            this->DateBoxContainer->TabIndex = 1;
            this->DateBoxContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &DateField::DateBoxContainer_Paint);
            this->DateBoxContainer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(
                this, &DateField::DateBoxContainer_MouseDown);
            // 
            // DateTimePicker
            // 
            this->DateTimePicker->Cursor = System::Windows::Forms::Cursors::Hand;
            this->DateTimePicker->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DateTimePicker->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F,
                                                                      System::Drawing::FontStyle::Regular,
                                                                      System::Drawing::GraphicsUnit::Point,
                                                                      static_cast<System::Byte>(0)));
            this->DateTimePicker->Location = System::Drawing::Point(8, 11);
            this->DateTimePicker->Margin = System::Windows::Forms::Padding(0);
            this->DateTimePicker->MaxDate = System::DateTime(2022, 12, 31, 0, 0, 0, 0);
            this->DateTimePicker->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
            this->DateTimePicker->Name = L"DateTimePicker";
            this->DateTimePicker->Size = System::Drawing::Size(228, 22);
            this->DateTimePicker->TabIndex = 1;
            this->DateTimePicker->ValueChanged += gcnew System::EventHandler(
                this, &DateField::DateTimePicker_ValueChanged);
            // 
            // DateField
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"DateField";
            this->Size = System::Drawing::Size(250, 50);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            this->DateBoxContainer->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void DateBoxContainer_MouseDown(Object^ sender, MouseEventArgs^ e)
        {
            DateTimePicker->Focus();
        }

        System::Void DateBoxContainer_Paint(Object^ sender, PaintEventArgs^ e)
        {
            // Bottom border
            e->Graphics->DrawLine(Pens::LightGray,
                                  0, DateBoxContainer->Height - 1,
                                  DateBoxContainer->Width, DateBoxContainer->Height - 1);
        }

        System::Void DateTimePicker_ValueChanged(Object^ sender, EventArgs^ e)
        {
            DateChanged(this, e);
        }
    };
}
