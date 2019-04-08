#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItemGroup>
#include "circle.h"
#include "anchor.h"
#include "connector.h"
#include "sidelink.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_animation_timer = new QTimer(this);

    View = new GraphicsView;
    scene = new QGraphicsScene;
    group = new QGraphicsItemGroup;
    scene->addItem(group);
    group->setZValue(-1);
    //  addGrid();
    // Circle *circle = new Circle(View);
    // scene->addItem(circle);

    Anchor *anchor1 = new Anchor(nullptr,QPointF(-100,100));
    Anchor *anchor2 = new Anchor(nullptr,QPointF(100,100));
    Connector *connect1 = new Connector(nullptr,QPointF(-100,0));
    Connector *connect2 = new Connector(nullptr,QPointF(100,0));
    Coupler *coupler = new Coupler(nullptr,connect1,connect2);
    connect1->addCoupler(coupler);
    connect2->addCoupler(coupler);

    SideLink *sidelink1 = new SideLink(nullptr,anchor1,connect1);
    sidelink1->setColor(Qt::cyan);
    SideLink *sidelink2 = new SideLink(nullptr,anchor2,connect2);
    sidelink2->setColor(Qt::magenta);
    anchor1->addLink(sidelink1);
    connect1->addSideLink(sidelink1);
    anchor2->addLink(sidelink2);
    connect2->addSideLink(sidelink2);

    scene->addItem(anchor1);
    scene->addItem(anchor2);
    scene->addItem(sidelink1);
    scene->addItem(sidelink2);
    scene->addItem(connect1);
    scene->addItem(connect2);
    scene->addItem(coupler);

    View->setScene(scene);

    setCentralWidget(View);

    connect(m_animation_timer,&QTimer::timeout,scene,&QGraphicsScene::advance);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addGrid()
{
    for(int i = -1000;i < 1000;i += 50)
    {
        QGraphicsLineItem *item = new QGraphicsLineItem(i,-1000,i,1000);
        item->setPen(QPen(QColor(Qt::gray).light(120)));
        group->addToGroup(item);
    }
    for(int j = -1000;j < 1000;j += 50)
    {
        QGraphicsLineItem *item = new QGraphicsLineItem(-1000,j,1000,j);
        item->setPen(QPen(QColor(Qt::gray).light(120)));
        group->addToGroup(item);
    }
}

void MainWindow::on_action_2_triggered()
{
    View->setHasGrid(true);
    addGrid();
}

void MainWindow::on_action_3_triggered()
{
    QList<QGraphicsItem *> list =  group->childItems();
 //   scene->removeItem(group);
    QGraphicsItem *item;
    foreach(item,list)
        delete item;
    View->setHasGrid(false);
}

void MainWindow::on_actionStart_triggered()
{
    m_animation_timer->start(100);
}

void MainWindow::on_actionStop_triggered()
{
    m_animation_timer->stop();
}


