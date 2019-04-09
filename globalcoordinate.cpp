#include "globalcoordinate.h"
#include <QPen>
#include <QFont>

GlobalCoordinate::GlobalCoordinate(QGraphicsItem *parent):QGraphicsEllipseItem(parent)
  ,axisWidth(2),axisColor(QColor(Qt::red).light(120)),originFontSize(10),xyFontSize(10)
{
    xAxis = new QGraphicsLineItem(this);
    xAxis->setLine(0,0,80,0);
    xAxis->setPen(QPen(axisColor,axisWidth));

    yAxis = new QGraphicsLineItem(this);
    yAxis->setLine(0,0,0,-80);
    yAxis->setPen(QPen(axisColor,axisWidth));

    xHead << QPointF(80,3) << QPointF(92,0) << QPointF(80,-3);
    xArrow = new QGraphicsPolygonItem(xHead,this);
    xArrow->setBrush(axisColor);
    xArrow->setPen(QPen(axisColor,axisWidth));

    yHead << QPointF(3,-80) << QPointF(0,-92) << QPointF(-3,-80);
    yArrow = new QGraphicsPolygonItem(yHead,this);
    yArrow->setBrush(axisColor);
    yArrow->setPen(QPen(axisColor,axisWidth));

    Origin = new QGraphicsTextItem("O",this);
    Origin->setPos(-14,1);
    QFont originFont("O",originFontSize,QFont::Bold,true);
    Origin->setFont(originFont);

    xLabel = new QGraphicsTextItem("X",this);
    xLabel->setPos(80,1);
    QFont xLabelFont("X",xyFontSize,QFont::Normal,true);
    xLabel->setFont(xLabelFont);

    yLabel = new QGraphicsTextItem("Y",this);
    yLabel->setPos(1,-80);
    QFont yLabelFont("Y",xyFontSize,QFont::Normal,true);
    yLabel->setFont(yLabelFont);

    setFlag(QGraphicsItem::ItemIgnoresTransformations);
}








