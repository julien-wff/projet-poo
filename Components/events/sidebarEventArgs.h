#pragma once

using namespace System;

public enum class SidebarActions
{
    Menu,
    Employees,
    Clients,
    Articles,
    Orders,
    Statistics,
};


public ref class SidebarEventArgs : public EventArgs
{
public:
    SidebarEventArgs(SidebarActions action)
    {
        this->Action = action;
    }

    property SidebarActions Action;
};
