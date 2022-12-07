#pragma once
#include "../events/sidebarEventArgs.h"
#include "SidebarBtn.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Components
{
    // <summary>
    // The sidebar of the application
    // </summary>
    public ref class Sidebar : public System::Windows::Forms::UserControl
    {
    public:
        Sidebar(void)
        {
            InitializeComponent();
        }

    protected:
        ~Sidebar()
        {
            if (components)
            {
                delete components;
            }
        }

        System::Windows::Forms::TableLayoutPanel^ TableLayout;
        Components::SidebarBtn^ EmployeesBtn;
        Components::SidebarBtn^ ClientsBtn;
        Components::SidebarBtn^ ArticlesBtn;
        Components::SidebarBtn^ OrdersBtn;
        Components::SidebarBtn^ StatisticsBtn;
        Components::SidebarBtn^ MenuBtn;
        System::ComponentModel::Container^ components;

    public:
        // Event fired when a button is clicked
        event EventHandler^ HandleSidebarClick;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew
                System::ComponentModel::ComponentResourceManager(Sidebar::typeid));
            this->TableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->EmployeesBtn = (gcnew Components::SidebarBtn());
            this->ClientsBtn = (gcnew Components::SidebarBtn());
            this->MenuBtn = (gcnew Components::SidebarBtn());
            this->ArticlesBtn = (gcnew Components::SidebarBtn());
            this->OrdersBtn = (gcnew Components::SidebarBtn());
            this->StatisticsBtn = (gcnew Components::SidebarBtn());
            this->TableLayout->SuspendLayout();
            this->SuspendLayout();
            // 
            // TableLayout
            // 
            this->TableLayout->ColumnCount = 1;
            this->TableLayout->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->TableLayout->Controls->Add(this->EmployeesBtn, 0, 2);
            this->TableLayout->Controls->Add(this->ClientsBtn, 0, 3);
            this->TableLayout->Controls->Add(this->MenuBtn, 0, 0);
            this->TableLayout->Controls->Add(this->ArticlesBtn, 0, 4);
            this->TableLayout->Controls->Add(this->OrdersBtn, 0, 5);
            this->TableLayout->Controls->Add(this->StatisticsBtn, 0, 6);
            this->TableLayout->Dock = System::Windows::Forms::DockStyle::Fill;
            this->TableLayout->Location = System::Drawing::Point(0, 0);
            this->TableLayout->Name = L"TableLayout";
            this->TableLayout->RowCount = 9;
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->TableLayout->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->TableLayout->Size = System::Drawing::Size(200, 600);
            this->TableLayout->TabIndex = 1;
            // 
            // EmployeesBtn
            // 
            this->EmployeesBtn->BackColor = System::Drawing::Color::Transparent;
            this->EmployeesBtn->BtnActive = false;
            this->EmployeesBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->EmployeesBtn->IconImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(
                L"EmployeesBtn.IconImage")));
            this->EmployeesBtn->LabelText = L"Employés";
            this->EmployeesBtn->Location = System::Drawing::Point(0, 200);
            this->EmployeesBtn->Margin = System::Windows::Forms::Padding(0);
            this->EmployeesBtn->Name = L"EmployeesBtn";
            this->EmployeesBtn->Size = System::Drawing::Size(200, 40);
            this->EmployeesBtn->TabIndex = 1;
            this->EmployeesBtn->ButtonClick += gcnew System::EventHandler(this, &Sidebar::SidebarEmployeeBtn_Click);
            // 
            // ClientsBtn
            // 
            this->ClientsBtn->BackColor = System::Drawing::Color::Transparent;
            this->ClientsBtn->BtnActive = false;
            this->ClientsBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ClientsBtn->IconImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(
                L"ClientsBtn.IconImage")));
            this->ClientsBtn->LabelText = L"Clients";
            this->ClientsBtn->Location = System::Drawing::Point(0, 240);
            this->ClientsBtn->Margin = System::Windows::Forms::Padding(0);
            this->ClientsBtn->Name = L"ClientsBtn";
            this->ClientsBtn->Size = System::Drawing::Size(200, 40);
            this->ClientsBtn->TabIndex = 2;
            this->ClientsBtn->ButtonClick += gcnew System::EventHandler(this, &Sidebar::SidebarClientBtn_Click);
            // 
            // MenuBtn
            // 
            this->MenuBtn->BackColor = System::Drawing::Color::Transparent;
            this->MenuBtn->BtnActive = false;
            this->MenuBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MenuBtn->IconImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(
                L"MenuBtn.IconImage")));
            this->MenuBtn->LabelText = L"Digital Electronics";
            this->MenuBtn->Location = System::Drawing::Point(0, 0);
            this->MenuBtn->Margin = System::Windows::Forms::Padding(0);
            this->MenuBtn->Name = L"MenuBtn";
            this->MenuBtn->Size = System::Drawing::Size(200, 40);
            this->MenuBtn->TabIndex = 3;
            // 
            // ArticlesBtn
            // 
            this->ArticlesBtn->BackColor = System::Drawing::Color::Transparent;
            this->ArticlesBtn->BtnActive = false;
            this->ArticlesBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ArticlesBtn->IconImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(
                L"ArticlesBtn.IconImage")));
            this->ArticlesBtn->LabelText = L"Articles";
            this->ArticlesBtn->Location = System::Drawing::Point(0, 280);
            this->ArticlesBtn->Margin = System::Windows::Forms::Padding(0);
            this->ArticlesBtn->Name = L"ArticlesBtn";
            this->ArticlesBtn->Size = System::Drawing::Size(200, 40);
            this->ArticlesBtn->TabIndex = 4;
            this->ArticlesBtn->ButtonClick += gcnew System::EventHandler(this, &Sidebar::SidebarArticleBtn_Click);
            // 
            // OrdersBtn
            // 
            this->OrdersBtn->BackColor = System::Drawing::Color::Transparent;
            this->OrdersBtn->BtnActive = false;
            this->OrdersBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->OrdersBtn->IconImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(
                L"OrdersBtn.IconImage")));
            this->OrdersBtn->LabelText = L"Commandes";
            this->OrdersBtn->Location = System::Drawing::Point(0, 320);
            this->OrdersBtn->Margin = System::Windows::Forms::Padding(0);
            this->OrdersBtn->Name = L"OrdersBtn";
            this->OrdersBtn->Size = System::Drawing::Size(200, 40);
            this->OrdersBtn->TabIndex = 5;
            this->OrdersBtn->ButtonClick += gcnew System::EventHandler(this, &Sidebar::SidebarOrderBtn_Click);
            // 
            // StatisticsBtn
            // 
            this->StatisticsBtn->BackColor = System::Drawing::Color::Transparent;
            this->StatisticsBtn->BtnActive = false;
            this->StatisticsBtn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StatisticsBtn->IconImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(
                L"StatisticsBtn.IconImage")));
            this->StatisticsBtn->LabelText = L"Statistiques";
            this->StatisticsBtn->Location = System::Drawing::Point(0, 360);
            this->StatisticsBtn->Margin = System::Windows::Forms::Padding(0);
            this->StatisticsBtn->Name = L"StatisticsBtn";
            this->StatisticsBtn->Size = System::Drawing::Size(200, 40);
            this->StatisticsBtn->TabIndex = 6;
            this->StatisticsBtn->ButtonClick += gcnew System::EventHandler(this, &Sidebar::SidebarStatisticsBtn_Click);
            // 
            // Sidebar
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)),
                                                               static_cast<System::Int32>(static_cast<System::Byte>(
                                                                   23)),
                                                               static_cast<System::Int32>(static_cast<System::Byte>(
                                                                   55)));
            this->Controls->Add(this->TableLayout);
            this->ForeColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(253)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->Margin = System::Windows::Forms::Padding(0);
            this->Name = L"Sidebar";
            this->Size = System::Drawing::Size(200, 600);
            this->TableLayout->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
    private:
        // System::Void SidebarMenuBtn_Click(System::Object^ sender, System::EventArgs^ e)
        // {
        //     SidebarEventArgs^ args = gcnew SidebarEventArgs("menu");
        //     this->HandleSidebarClick(this, args);
        // }

        System::Void SidebarEmployeeBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            SidebarEventArgs^ args = gcnew SidebarEventArgs(SidebarActions::Employees);
            this->HandleSidebarClick(this, args);
            this->SetActiveBtn(args->Action);
        }

        System::Void SidebarClientBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            SidebarEventArgs^ args = gcnew SidebarEventArgs(SidebarActions::Clients);
            this->HandleSidebarClick(this, args);
            this->SetActiveBtn(args->Action);
        }

        System::Void SidebarArticleBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            SidebarEventArgs^ args = gcnew SidebarEventArgs(SidebarActions::Articles);
            this->HandleSidebarClick(this, args);
            this->SetActiveBtn(args->Action);
        }

        System::Void SidebarOrderBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            SidebarEventArgs^ args = gcnew SidebarEventArgs(SidebarActions::Orders);
            this->HandleSidebarClick(this, args);
            this->SetActiveBtn(args->Action);
        }

        System::Void SidebarStatisticsBtn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            SidebarEventArgs^ args = gcnew SidebarEventArgs(SidebarActions::Statistics);
            this->HandleSidebarClick(this, args);
            this->SetActiveBtn(args->Action);
        }

    public:
        System::Void SetActiveBtn(SidebarActions action)
        {
            this->EmployeesBtn->BtnActive = action == SidebarActions::Employees;
            this->ClientsBtn->BtnActive = action == SidebarActions::Clients;
            this->ArticlesBtn->BtnActive = action == SidebarActions::Articles;
            this->OrdersBtn->BtnActive = action == SidebarActions::Orders;
            this->StatisticsBtn->BtnActive = action == SidebarActions::Statistics;
        }
    };
}
