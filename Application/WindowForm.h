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
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void)
    {
        this->components = gcnew System::ComponentModel::Container();
        this->Size = System::Drawing::Size(300, 300);
        this->Text = L"WindowForm";
        this->Padding = System::Windows::Forms::Padding(0);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    }
#pragma endregion
};
