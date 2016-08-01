#pragma once

enum class MenuItemType
{
    UNDEFINED = 0
    , IRON_BUYER
};

class MenuItem
{
public:
    MenuItem(MenuItemType initType);

    virtual ~MenuItem() {}

    MenuItemType get_type() const { return type; }

    bool is_available() const { return available; }

    void set_available(bool flag) { available = flag; }

private:
    MenuItemType type;

    bool available {true};
};

