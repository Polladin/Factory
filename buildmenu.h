#pragma once

#include <list>
#include <set>
#include <memory>

#include "menuitem.h"
#include "builditem.h"
#include "menuironbuyer.h"

using t_menuButtons = std::list<MenuItem*>;

class BuildMenu
{
public:
    BuildMenu();

    t_menuButtons get_available_menus() const;

//    void add_iron_buyer() { allMenuButtons.emplace(new MenuIronBuyer); }
    void add_iron_buyer()
        { allMenuButtons.insert(std::unique_ptr<MenuItem>(new MenuIronBuyer)); }

private:

//    std::list<std::unique_ptr<MenuItem>> allMenuButtons;


    // storage for all builded menu buttons and compare object for this
    class compareMenuTypes
    {
    public:
        bool operator() (const std::unique_ptr<MenuItem>& obj1, const std::unique_ptr<MenuItem>& obj2)
            { return obj1->get_type() == obj2->get_type(); }
    };

    std::set<std::unique_ptr<MenuItem>, compareMenuTypes> allMenuButtons;

};


