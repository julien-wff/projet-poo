#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class SelectField : public System::Windows::Forms::UserControl
    {
    public:
        SelectField(void)
        {
            InitializeComponent();
        }

    protected:
        ~SelectField()
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

        // Property of tuple (String^, String^)
        property array<Tuple<Object^, String^>^>^ Items
        {
            array<Tuple<Object^, String^>^>^ get()
            {
                return _Items;
            }

            void set(array<Tuple<Object^, String^>^>^ value)
            {
                if (value == nullptr)
                    _Items = gcnew array<Tuple<Object^, String^>^>(0);
                else
                    _Items = value;
                Select->Items->Clear();
                for each (Tuple<Object^, String^>^ item in _Items)
                {
                    Select->Items->Add(item->Item2);
                }
            }
        }

        property Object^ SelectedItem
        {
            Object^ get()
            {
                return _Items[Select->SelectedIndex]->Item1;
            }
        }

        property int SelectedIndex
        {
            int get()
            {
                return Select->SelectedIndex;
            }

            void set(int value)
            {
                Select->SelectedIndex = value;
            }
        }

        event EventHandler<Object^>^ SelectionChanged;

    private:
        System::Windows::Forms::TableLayoutPanel^ TableLayoutPanel;
        System::Windows::Forms::Label^ Label;
        System::Windows::Forms::Panel^ SelectBoxContainer;
        System::Windows::Forms::ComboBox^ Select;
        System::ComponentModel::Container^ components;
        array<Tuple<Object^, String^>^>^ _Items;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->TableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Label = (gcnew System::Windows::Forms::Label());
            this->SelectBoxContainer = (gcnew System::Windows::Forms::Panel());
            this->Select = (gcnew System::Windows::Forms::ComboBox());
            this->TableLayoutPanel->SuspendLayout();
            this->SelectBoxContainer->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayoutPanel
            // 
            this->TableLayoutPanel->ColumnCount = 1;
            this->TableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->TableLayoutPanel->Controls->Add(this->Label, 0, 0);
            this->TableLayoutPanel->Controls->Add(this->SelectBoxContainer, 0, 1);
            this->TableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayoutPanel->Location = System::Drawing::Point(0, 0);
            this->TableLayoutPanel->Margin = System::Windows::Forms::Padding(0);
            this->TableLayoutPanel->Name = L"TableLayoutPanel";
            this->TableLayoutPanel->RowCount = 2;
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->TableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->TableLayoutPanel->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->TableLayoutPanel->Size = System::Drawing::Size(250, 60);
            this->TableLayoutPanel->TabIndex = 1;
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
            // SelectBoxContainer
            // 
            this->SelectBoxContainer->AutoSize = true;
            this->SelectBoxContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->SelectBoxContainer->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->SelectBoxContainer->Controls->Add(this->Select);
            this->SelectBoxContainer->Cursor = System::Windows::Forms::Cursors::Hand;
            this->SelectBoxContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->SelectBoxContainer->Location = System::Drawing::Point(3, 20);
            this->SelectBoxContainer->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
            this->SelectBoxContainer->Name = L"SelectBoxContainer";
            this->SelectBoxContainer->Padding = System::Windows::Forms::Padding(6);
            this->SelectBoxContainer->Size = System::Drawing::Size(244, 40);
            this->SelectBoxContainer->TabIndex = 1;
            this->SelectBoxContainer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(
                this, &SelectField::SelectBoxContainer_MouseDown);
            this->SelectBoxContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &SelectField::SelectBoxContainer_Paint);
            // 
            // Select
            // 
            this->Select->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Select->DropDownHeight = 200;
            this->Select->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Select->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Select->FormattingEnabled = true;
            this->Select->IntegralHeight = false;
            this->Select->ItemHeight = 13;
            this->Select->Location = System::Drawing::Point(8, 11);
            this->Select->MaxDropDownItems = 20;
            this->Select->Name = L"Select";
            this->Select->Size = System::Drawing::Size(228, 21);
            this->Select->TabIndex = 5;
            this->Select->SelectedIndexChanged += gcnew System::EventHandler(
                this, &SelectField::Select_SelectedIndexChanged);
            // 
            // SelectField
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayoutPanel);
            this->Name = L"SelectField";
            this->Size = System::Drawing::Size(250, 50);
            this->TableLayoutPanel->ResumeLayout(false);
            this->TableLayoutPanel->PerformLayout();
            this->SelectBoxContainer->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

        Void SelectBoxContainer_MouseDown(Object^ sender, MouseEventArgs^ e)
        {
            // Open the dropdown menu
            Select->DroppedDown = true;
        }

        Void SelectBoxContainer_Paint(Object^ sender, PaintEventArgs^ e)
        {
            // Bottom border
            e->Graphics->DrawLine(Pens::LightGray,
                                  0, SelectBoxContainer->Height - 1,
                                  SelectBoxContainer->Width, SelectBoxContainer->Height - 1);
        }

        Void Select_SelectedIndexChanged(Object^ sender, EventArgs^ e)
        {
            this->SelectionChanged(this, _Items[Select->SelectedIndex]->Item1);
        }
    };
}
