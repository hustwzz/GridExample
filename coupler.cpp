#include "coupler.h"
#include "connector.h"
#include <QDebug>

Coupler::Coupler(GraphWidget *graphWidget, Connector *connector1, Connector *connector2)
    :graph(graphWidget),startConnector(connector1),endConnector(connector2)
{
    adjust();
}

QRectF Coupler::boundingRect() const
{
    qreal x1 = qMin(startPos.x(),endPos.x());
    qreal y1 = qMin(startPos.y(),endPos.y());
    qreal x2 = qMax(startPos.x(),endPos.x());
    qreal y2 = qMax(startPos.y(),endPos.y());
    qreal adjust = 1.5;
    return QRectF(x1 - adjust/2,y1 - adjust/2,x2 - x1 + adjust,y2 - y1 + adjust);
}

void Coupler::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::NoBrush,1.5);
    pen.setColor(QColor(Qt::green).light(80));
    setPen(pen);
    setLine(QLineF(startPos,endPos));
    QGraphicsLineItem::paint(painter,option,widget);
}

void Coupler::adjust()
{
    if(!startConnector || !endConnector)
        return;

    startPos = mapFromItem(startConnector,0,0);
    endPos = mapFromItem(endConnector,0,0);

    prepareGeometryChange();

}


