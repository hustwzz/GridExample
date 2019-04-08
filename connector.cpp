#include "connector.h"
#include <QGraphicsSceneMouseEvent>
#include "qmath.h"

Connector::Connector(GraphWidget *graphWidget,const QPointF& point1,const QPointF& point2)
    :graph(graphWidget),posInScene(point1),centerPos(point2),link(nullptr)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);
    setPos(posInScene);
}

QRectF Connector::boundingRect() const
{
    qreal adjust = 1;
    return QRectF( centerPos.x() - 3 - adjust/2,centerPos.y() - 3 - adjust/2,6 + adjust,6 + adjust);
}

void Connector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::NoBrush,1);
    pen.setColor(QColor(Qt::blue).light(120));
    setPen(pen);
    setRect(centerPos.x()-3,centerPos.y()-3,6,6);
    painter->setRenderHint(QPainter::Antialiasing);

    QGraphicsEllipseItem::paint(painter,option,widget);
}

void Connector::advance(int phase)
{
    static int i = 0;
    setPos(50*qSin(i/360.0*2*3.14),50*qCos(i/360.0*2*3.14));
    ++i;
}

void Connector::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    posInScene = event->pos();
    QGraphicsItem::mouseMoveEvent(event);
}

QVariant Connector::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach(Coupler *s,couplers)
            s->adjust();
        if(link!=nullptr) link->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

