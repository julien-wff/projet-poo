#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    public ref class TableDisplay : public System::Windows::Forms::UserControl
    {
    public:
        TableDisplay(void)
        {
            InitializeComponent();
        }

    protected:
        ~TableDisplay()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        event EventHandler<DataRow^>^ RowSelect;

    private:
        System::Windows::Forms::DataGridView^ DataGridView;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->DataGridView = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // DataGridView
            // 
            this->DataGridView->AllowUserToAddRows = false;
            this->DataGridView->AllowUserToDeleteRows = false;
            this->DataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
            this->DataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->DataGridView->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->DataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
            this->DataGridView->Location = System::Drawing::Point(0, 0);
            this->DataGridView->Margin = System::Windows::Forms::Padding(0);
            this->DataGridView->Name = L"DataGridView";
            this->DataGridView->ReadOnly = true;
            this->DataGridView->RowHeadersVisible = false;
            this->DataGridView->Size = System::Drawing::Size(800, 560);
            this->DataGridView->TabIndex = 2;
            this->DataGridView->AutoGenerateColumns = false;
            this->DataGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            this->DataGridView->DefaultCellStyle->SelectionBackColor = Color::White;
            this->DataGridView->DefaultCellStyle->SelectionForeColor = Color::Black;
            this->DataGridView->CellClick += gcnew DataGridViewCellEventHandler(
                this, &TableDisplay::DataGridView_CellClick);
            // 
            // TableDisplay
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->DataGridView);
            this->Name = L"TableDisplay";
            this->Size = System::Drawing::Size(800, 560);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataGridView))->EndInit();
            this->ResumeLayout(false);
        }

        System::Void DataGridView_CellClick(System::Object^ sender,
                                            System::Windows::Forms::DataGridViewCellEventArgs^ e)
        {
            // Get corresponding DataRow based on the DataSouce of the DataGridView
            DataRowView^ drv = (DataRowView^)DataGridView->Rows[e->RowIndex]->DataBoundItem;
            RowSelect(this, drv->Row);
        }

    public:
        void SetDataSource(System::Data::DataTable^ table)
        {
            this->DataGridView->DataSource = table;
        }

        void AddColumn(String^ headerText, String^ dataProperty, int width)
        {
            auto column = gcnew DataGridViewTextBoxColumn();
            column->DataPropertyName = dataProperty;
            column->HeaderText = headerText;
            column->MinimumWidth = 50;
            column->Name = dataProperty + "Column";
            column->ReadOnly = true;
            column->SortMode = DataGridViewColumnSortMode::NotSortable;
            column->Width = width;
            this->DataGridView->Columns->Add(column);
        }

        void AddColumn(String^ headerText, String^ dataProperty)
        {
            this->AddColumn(headerText, dataProperty, 150);
        }
    };
#pragma endregion
};
