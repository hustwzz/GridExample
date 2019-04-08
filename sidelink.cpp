#include "sidelink.h"
#include "connector.h"
#include "anchor.h"

SideLink::SideLink(GraphWidget *graphWidget,  Anchor *startAn, Connector *endCo)
    :graph(graphWidget),startAnchor(startAn),endConnector(endCo),colorOfSideLink(Qt::green)
{
    adjust();
}

QRectF SideLink::boundingRect() const
{
    qreal x1 = qMin(startPos.x(),endPos.x());
    qreal y1 = qMin(startPos.y(),endPos.y());
    qreal x2 = qMax(startPos.x(),endPos.x());
    qreal y2 = qMax(startPos.y(),endPos.y());
    qreal adjust = 1.5;
    return QRectF(x1 - adjust/2,y1 - adjust/2,x2 - x1 + adjust,y2 - y1 + adjust);
}

void SideLink::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::NoBrush,1.5);
    pen.setColor(colorOfSideLink.light(80));
    setPen(pen);
    setLine(QLineF(startPos,endPos));
    QGraphicsLineItem::paint(painter,option,widget);
}

void SideLink::adjust()
{
    if(!startAnchor || !endConnector)
        return;

    startPos = mapFromItem(startAnchor,0,0);
    endPos = mapFromItem(endConnector,0,0);

    prepareGeometryChange();

    update();
}

