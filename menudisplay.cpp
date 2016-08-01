#include <QGraphicsRectItem>

#include "menudisplay.h"

#include "menuironbuyerpixel.h"

MenuDisplay::MenuDisplay(const BuildMenu &initBuildMenu)
    : buildMenu (initBuildMenu)
{

}

void MenuDisplay::display(QGraphicsScene *pScene) const
{
    t_menuButtons menuToDisplay = buildMenu.get_available_menus();

    for (const auto* menuItem : menuToDisplay)
    {
        QGraphicsRectItem *item;

        switch (menuItem->get_type())
        {
        case MenuItemType::IRON_BUYER:
            // create QGraphicsItem
//            item = new QGraphicsRectItem(10, 10, 40, 40);
//            item->setBrush(QBrush(Qt::green));

            item = new MenuIronBuyerPixel(10, 10, 40);


            // add the Item to Scene
            pScene->addItem(item);

            break;

        default:
            break;
        }
    }
}
