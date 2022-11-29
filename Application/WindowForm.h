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
        this->Sidebar->BackColor = System::Drawing::SystemColors::ControlLight;
        this->Sidebar->Dock = System::Windows::Forms::DockStyle::Left;
        this->Sidebar->Location = System::Drawing::Point(0, 0);
        this->Sidebar->Name = L"Sidebar";
        this->Sidebar->Size = System::Drawing::Size(200, 600);
        this->Sidebar->TabIndex = 0;
        this->Sidebar->HandleSidebarClick += gcnew System::EventHandler(this, &WindowForm::sidebar1_HandleSidebarClick);
        // 
        // WindowForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1000, 600);
        this->Controls->Add(this->Sidebar);
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
