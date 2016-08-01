#include "factorygamemainwindow.h"
#include "ui_factorygamemainwindow.h"

#include <QPalette>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "factorymap.h"
#include "factoryobjectdisplay.h"
#include "factoryobjectwall.h"
#include "factoryobjectroad.h"

#include "factoryview.h"

#include "buildmenu.h"
#include "builditem.h"
#include "menudisplay.h"

FactoryMap factory(5,5);
FactoryObjectDisplay factoryDisplay(&factory, 50, 50);

BuildMenu menu;
MenuDisplay menuDisplay(menu);

FactoryGameMainWindow::FactoryGameMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FactoryGameMainWindow)
{
    ui->setupUi(this);

//    // set background for menu frame
//    QPalette menuPal(ui->menuFrame->palette());

//    menuPal.setColor(QPalette::Background, QColor(255,165,0));
//    ui->menuFrame->setAutoFillBackground(true);
//    ui->menuFrame->setPalette(menuPal);

    ui->textLog->appendPlainText(QString("Factory Height : ") + QString::number(factory.get_height()));
    ui->textLog->appendPlainText(QString("Factory Width : ") + QString::number(factory.get_width()));


    // create Scene and View
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,ui->factoryFrame->rect().width(), ui->factoryFrame->rect().height());

    QGraphicsView * view;
//    view = new QGraphicsView(scene, ui->factoryFrame); //, ui->frame);
    view = new FactoryView(scene, ui->factoryFrame); //, ui->frame);
    view->setFixedSize(ui->factoryFrame->rect().width(), ui->factoryFrame->rect().height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    // set objects to the Scene
    for( std::size_t i = 0; i < factory.get_height()-1; ++i)
        factory.set_object(i, i, std::unique_ptr<FactoryObject>(new FactoryObjectWall()));

    factory.set_object(0,4, std::unique_ptr<FactoryObject>(new FactoryObjectRoad()));
    factory.set_object(1,4, std::unique_ptr<FactoryObject>(new FactoryObjectRoad()));
    factory.set_object(2,4, std::unique_ptr<FactoryObject>(new FactoryObjectRoad()));
    factory.set_object(3,4, std::unique_ptr<FactoryObject>(new FactoryObjectRoad()));
    factory.set_object(4,4, std::unique_ptr<FactoryObject>(new FactoryObjectRoad()));

    factoryDisplay.set_Xoffset(200);
    factoryDisplay.display(scene);

    menu.add_iron_buyer();

    menuDisplay.set_border(200, ui->factoryFrame->rect().height());
    menuDisplay.display(scene);
}

FactoryGameMainWindow::~FactoryGameMainWindow()
{
    delete ui;
}
