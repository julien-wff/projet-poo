#pragma once

using namespace System;

public ref class SidebarEventArgs : public EventArgs
{
public:
    SidebarEventArgs(String^ action)
    {
        this->Action = action;
    }

    property String^ Action;
};
