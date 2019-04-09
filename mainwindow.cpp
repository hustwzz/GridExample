#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsItemGroup>
#include <cmath>
#include <QDebug>

#include "circle.h"
#include "anchor.h"
#include "connector.h"
#include "sidelink.h"
#include "globalcoordinate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),gridSize(50),gridGroup(nullptr)
{
    ui->setupUi(this);
    createDockWidgets();

    m_animation_timer = new QTimer(this);

    View = new GraphicsView;
    scene = new QGraphicsScene;
//    scene->setSceneRect(-200,-150,400,300);
    // Circle *circle = new Circle(View);
    // scene->addItem(circle);

    Anchor *anchor1 = new Anchor(QPointF(-100,100));
    Anchor *anchor2 = new Anchor(QPointF(100,100));
    Connector *connect1 = new Connector(nullptr,QPointF(-100,0));
    Connector *connect2 = new Connector(nullptr,QPointF(100,0));
    Coupler *coupler = new Coupler(nullptr,connect1,connect2);
    connect1->addCoupler(coupler);
    connect2->addCoupler(coupler);

    SideLink *sidelink1 = new SideLink(nullptr,anchor1,connect1);
    sidelink1->setColor(Qt::cyan);
    SideLink *sidelink2 = new SideLink(nullptr,anchor2,connect2);
    sidelink2->setColor(Qt::magenta);
    anchor1->addSideLink(sidelink1);
    connect1->addSideLink(sidelink1);
    anchor2->addSideLink(sidelink2);
    connect2->addSideLink(sidelink2);

    scene->addItem(anchor1);
    scene->addItem(anchor2);
    scene->addItem(sidelink1);
    scene->addItem(sidelink2);
    scene->addItem(connect1);
    scene->addItem(connect2);
    scene->addItem(coupler);

    GlobalCoordinate *globalCoordinate = new GlobalCoordinate;
    scene->addItem(globalCoordinate);

    View->setScene(scene);

    setCentralWidget(View);

    connect(m_animation_timer,&QTimer::timeout,scene,&QGraphicsScene::advance);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDockWidgets()
{
    setDockOptions(QMainWindow::AnimatedDocks);
    plotWidget = new QDockWidget(tr("仿真曲线"),this);
    plotWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::RightDockWidgetArea,plotWidget);

}

void MainWindow::viewShowGrid(bool isGridShow)
{
    if(!gridGroup)
    {
        QPen pen(QColor(Qt::gray).light(120));
        gridGroup = new QGraphicsItemGroup;
        for(int x = -2000;x <= 2000;x += gridSize)
        {
            QGraphicsLineItem *item = new QGraphicsLineItem(x,-1500,x,1500);
            item->setPen(pen);
            gridGroup->addToGroup(item);
        }
        for(int y = -1500;y <= 1500;y += gridSize)
        {
            QGraphicsLineItem *item = new QGraphicsLineItem(-2000,y,2000,y);
            item->setPen(pen);
            gridGroup->addToGroup(item);
        }
        scene->addItem(gridGroup);
        gridGroup->setZValue(-1);
    }
    gridGroup->setVisible(isGridShow);
}

void MainWindow::on_action_2_triggered()
{
   viewShowGrid(true);
}

void MainWindow::on_action_3_triggered()
{
    viewShowGrid(false);
}

void MainWindow::on_actionStart_triggered()
{
    m_animation_timer->start(100);
}

void MainWindow::on_actionStop_triggered()
{
    m_animation_timer->stop();
}


