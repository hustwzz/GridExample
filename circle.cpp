#include "circle.h"
#include <QPainter>
#include <QDebug>
#include <qmath.h>

Circle::Circle(GraphicsView* view)
{
    View = view;
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
}

QRectF Circle::boundingRect() const
{
    qreal adjust = 1;
    return QRectF(-5-adjust/2, -5-adjust/2, 10+adjust, 10+adjust);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::NoBrush,1);
    pen.setColor(Qt::blue);
    setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    setRect(-5,-5,10,10);
    QGraphicsEllipseItem::paint(painter,option,widget);
}

QVariant Circle::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    static QPointF point(0,0);
    switch (change) {
    case ItemPositionHasChanged:
        if(View->getHasGrid())
        {
            point = checkGrid(View->getGridSpace());
            if((mapToScene(0,0)-point).manhattanLength() < 8)
                setPos(point);
        }
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

QPointF Circle::checkGrid(int space)
{
    int x = static_cast<int>(mapToScene(0,0).rx());
    int y = static_cast<int>(mapToScene(0,0).ry());
    int relative_x = qAbs(x % space);
    int relative_y = qAbs(y % space);
    if(relative_x <= space/2 && relative_y <= space/2)
        return QPointF(x - x % space,y - y % space);
    else if(relative_x <= space/2 && relative_y > space/2)
        return QPointF(x - x % space,y - y % space + (y >= 0? space:-space));
    else if(relative_x > space/2 && relative_y <= space/2)
        return QPointF(x - x % space + (x >= 0? space:-space),y - y % space);
    else
        return QPointF(x - x % space + (x >= 0? space:-space),y - y % space + (y >= 0? space:-space));
}

void Circle::advance(int phase)
{
    static int i = 0;
    setPos(100*qSin(i/360.0*2*3.14),100*qCos(i/360.0*2*3.14));
    ++i;
}


