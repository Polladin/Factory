#include "buildmenu.h"



BuildMenu::BuildMenu()
{

}

t_menuButtons BuildMenu::get_available_menus() const
{
    t_menuButtons listOfAvailableMenus;

    for (const auto& menuItem : allMenuButtons)
    {
        if (menuItem->is_available())
            listOfAvailableMenus.push_back(menuItem.get());
    }

    return listOfAvailableMenus;
}

