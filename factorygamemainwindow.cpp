#include "factorygamemainwindow.h"
#include "ui_factorygamemainwindow.h"

#include <QPalette>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "factorymap.h"
#include "factoryobjectdisplay.h"
#include "factoryobjectbuilder.h"
#include "factoryobjectwall.h"
#include "factoryobjectroad.h"

#include "factoryview.h"

#include "buildmenu.h"
#include "builditem.h"
#include "menudisplay.h"

#include "testmap1.h"

FactoryMap *factory; //(5,5);
FactoryObjectDisplay *factoryDisplay; //(&factory, 50, 50);

BuildMenu menu;
MenuDisplay menuDisplay(menu);

FactoryGameMainWindow::FactoryGameMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FactoryGameMainWindow)
{
    ui->setupUi(this);

    // create Scene and View
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,ui->factoryFrame->rect().width(), ui->factoryFrame->rect().height());

    QGraphicsView * view;
    view = new FactoryView(scene, ui->factoryFrame); //, ui->frame);
    view->setFixedSize(ui->factoryFrame->rect().width(), ui->factoryFrame->rect().height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    // create FactoryMap
    factory = new FactoryMap(mapPattern1[0].length(), mapPattern1.size());
    TestMap1::show(factory);

    // create Factory Display and init scene by default objects
    factoryDisplay = new FactoryObjectDisplay(factory, scene, 20, 20, 100);

    // add observer (before any changes with factory map)
    factory->add_observer(factoryDisplay);

//    // set objects to the Scene
//    for( std::size_t i = 0; i < factory->get_height()-1; ++i)
//        factory->set_object(std::unique_ptr<FactoryObject>(FactoryObjectBuilder::build(FactoryTypes::WALL, i, i)));

//    std::vector<std::pair<std::size_t, std::size_t>> road_coord = { {4,0}, {4,1}, {4,2}, {4,3}, {4,4} };
//    for (const auto& coord : road_coord)
//    {
//        factory->set_object(std::unique_ptr<FactoryObject>(
//                               FactoryObjectBuilder::build(FactoryTypes::ROAD,coord.first, coord.second)));
//    }

    menu.add_iron_buyer();

    menuDisplay.set_border(200, ui->factoryFrame->rect().height());
    menuDisplay.display(scene);

    // add log
    ui->textLog->appendPlainText(QString("Factory Height : ") + QString::number(factory->get_height()));
    ui->textLog->appendPlainText(QString("Factory Width : ") + QString::number(factory->get_width()));
}

FactoryGameMainWindow::~FactoryGameMainWindow()
{
    delete ui;
}
