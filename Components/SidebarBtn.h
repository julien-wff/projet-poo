#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    // <summary>
    // An individual button that is added to the sidebar. The label and icon are customizable.
    // </summary>
    public ref class SidebarBtn : public System::Windows::Forms::UserControl
    {
    public:
        SidebarBtn(void)
        {
            InitializeComponent();
        }

    protected:
        ~SidebarBtn()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::PictureBox^ Icon;
        System::Windows::Forms::TableLayoutPanel^ TableLayout;
        System::Windows::Forms::Label^ Label;
        System::ComponentModel::Container^ components;

        // Text label property
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

        // Icon property
        property Image^ IconImage
        {
            Image^ get()
            {
                return Icon->Image;
            }

            void set(Image^ value)
            {
                Icon->Image = value;
            }
        }

        // Active boolean property
    private:
        bool _active;
    public:
        property bool BtnActive
        {
            bool get()
            {
                return _active;
            }

            void set(bool value)
            {
                _active = value;
                if (_active)
                    this->BackColor = System::Drawing::Color::FromArgb(57, 99, 173);
                else
                    this->BackColor = System::Drawing::Color::Transparent;
            }
        }

        // Click event
        event EventHandler^ ButtonClick;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew
                System::ComponentModel::ComponentResourceManager(SidebarBtn::typeid));
            this->Icon = (gcnew System::Windows::Forms::PictureBox());
            this->TableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Label = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Icon))->BeginInit();
            this->TableLayout->SuspendLayout();
            this->SuspendLayout();
            // 
            // Icon
            // 
            this->Icon->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Icon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Icon.Image")));
            this->Icon->Location = System::Drawing::Point(3, 3);
            this->Icon->Name = L"Icon";
            this->Icon->Size = System::Drawing::Size(34, 34);
            this->Icon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->Icon->TabIndex = 0;
            this->Icon->TabStop = false;
            this->Icon->Click += gcnew System::EventHandler(this, &SidebarBtn::SidebarBtn_Click);
            // 
            // TableLayout
            // 
            this->TableLayout->ColumnCount = 2;
            this->TableLayout->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayout->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->TableLayout->Controls->Add(this->Icon, 0, 0);
            this->TableLayout->Controls->Add(this->Label, 1, 0);
            this->TableLayout->Cursor = System::Windows::Forms::Cursors::Hand;
            this->TableLayout->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayout->Location = System::Drawing::Point(0, 0);
            this->TableLayout->Name = L"TableLayout";
            this->TableLayout->RowCount = 1;
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayout->Size = System::Drawing::Size(200, 40);
            this->TableLayout->TabIndex = 1;
            // 
            // Label
            // 
            this->Label->AutoSize = true;
            this->Label->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Label->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular,
                                                             System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Label->Location = System::Drawing::Point(43, 0);
            this->Label->Name = L"Label";
            this->Label->Size = System::Drawing::Size(154, 40);
            this->Label->TabIndex = 1;
            this->Label->Text = L"Label";
            this->Label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->Label->Click += gcnew System::EventHandler(this, &SidebarBtn::SidebarBtn_Click);
            // 
            // SidebarBtn
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->TableLayout);
            this->Name = L"SidebarBtn";
            this->Size = System::Drawing::Size(200, 40);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Icon))->EndInit();
            this->TableLayout->ResumeLayout(false);
            this->TableLayout->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion
    private:
        System::Void SidebarBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            ButtonClick(this, e);
        }
    };
}
