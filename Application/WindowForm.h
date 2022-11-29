#pragma once

using namespace System;
using namespace ComponentModel;
using namespace Collections;
using namespace Windows::Forms;
using namespace Data;
using namespace Drawing;

/// <summary>
/// The principal form of the application. This code is run when the application starts.
/// </summary>
public ref class WindowForm : public System::Windows::Forms::Form
{
public:
    WindowForm()
    {
        InitializeComponent();
    }

protected:
    ~WindowForm()
    {
        if (components)
        {
            delete components;
        }
    }

private:
    Components::Sidebar^ Sidebar;


    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->Sidebar = (gcnew Components::Sidebar());
        this->SuspendLayout();
        // 
        // Sidebar
        // 
        this->Sidebar->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(4)),
            static_cast<System::Int32>(static_cast<System::Byte>(23)),
            static_cast<System::Int32>(static_cast<System::Byte>(55)));
        this->Sidebar->Dock = System::Windows::Forms::DockStyle::Left;
        this->Sidebar->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(253)),
            static_cast<System::Int32>(static_cast<System::Byte>(254)),
            static_cast<System::Int32>(static_cast<System::Byte>(250)));
        this->Sidebar->Location = System::Drawing::Point(0, 0);
        this->Sidebar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Sidebar->Name = L"Sidebar";
        this->Sidebar->Size = System::Drawing::Size(233, 738);
        this->Sidebar->TabIndex = 0;
        this->Sidebar->HandleSidebarClick += gcnew System::EventHandler(this, &WindowForm::sidebar1_HandleSidebarClick);
        // 
        // WindowForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(241)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(243)));
        this->ClientSize = System::Drawing::Size(1167, 738);
        this->Controls->Add(this->Sidebar);
        this->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular,
                                                  System::Drawing::GraphicsUnit::Point,
                                                  static_cast<System::Byte>(0)));
        this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(6)),
                                                           static_cast<System::Int32>(static_cast<System::Byte>(11)));
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Name = L"WindowForm";
        this->Text = L"Application de gestion";
        this->ResumeLayout(false);
    }
#pragma endregion

    void sidebar1_HandleSidebarClick(System::Object^ sender, System::EventArgs^ e)
    {
        SidebarEventArgs^ args = safe_cast<SidebarEventArgs^>(e);
    }
};
